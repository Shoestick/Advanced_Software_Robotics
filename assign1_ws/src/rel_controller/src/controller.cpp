//This code sets up a controller for the RELbot used at the course.

//The main objective of the program is to recieve a setpoint via a topic and add it to a vector of setpoints of max size 10.
//When the robot reaches the first setpoint of the vector, it erases it (if there are more setpoints) and proceeds to the next one. 
//It publishes the twist according to the calculations to reach that point. It also publishes the actual target location.

//It has 3 internal variables, its linear calculated velocity, its calculated angular velocity and the vector of targets.

//Controller(): The constructor sets an initial position to the vector of targets and initializes all publishers, subscribers and topics.
//It is subscribed to /output/robot_pose and to /cog_object.
//It publishes in /target and in /input/twist.

//PublishControl() it gets its linear and angular velocities and publishes them as a twist in /input/twist.

//publishTarger() it gets the next target from the vector and publishes it at /target.

//set_vel(float linear float angular) it sets its internal variables to the given values.

//position_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) it gets its actual position from the message and
//using the next target, it calculates the acording control as a linear and angular velocity to set the internal variables.
//It also checks if it has reached a target and if so, (and its not the last target of the vector) it removes it from the list.

//point_callback(const assign1_interfaces::msg::PixelCoordinates::SharedPtr msg) it checks the size of the targets vector, and if its not 10, and the position has a valid value, it adds it to
//the targets vector.

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "example_interfaces/msg/string.hpp"
#include "example_interfaces/msg/float64.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "assign1_interfaces/msg/pixel_coordinates.hpp"

#include <random>
#include <cmath>
#include <vector>

using namespace std::chrono_literals;

struct Pose{ //Type of target positions.
    uint x;
    uint y;
};

class Controller : public rclcpp::Node 
{
public:
    Controller() : Node("controller") //Constructor.
    {
        Pose initial_pose; //Initial pose to add to the targets vector.
        initial_pose.x=20;
        initial_pose.y=20;

        this->positions.push_back(initial_pose); //Push back to the vector.      

        subscription_pose = this->create_subscription<geometry_msgs::msg::PoseStamped>( //Subscription to the pose of the robot.
            "/output/robot_pose", 10, 
            std::bind(&Controller::position_callback, this, std::placeholders::_1));

        subscription_point = this->create_subscription<assign1_interfaces::msg::PixelCoordinates>(//Subscription to the position of the center of gravity of the light in the image.
            "/cog_object", 10, 
            std::bind(&Controller::point_callback, this, std::placeholders::_1));
        // create a publisher to the left wheel, publish control every half second
        publisher_twist = this->create_publisher<geometry_msgs::msg::Twist>("/input/twist",10); //Publisher to the twist.
        publisher_target = this->create_publisher<assign1_interfaces::msg::PixelCoordinates>("/target",10); //Publisher to the target.

        timer_1 = this->create_wall_timer(0.5s, std::bind(&Controller::publishControl, this));//timers
        timer_2 = this->create_wall_timer(0.5s, std::bind(&Controller::publishTarget, this));
        
        // text to terminal when starting
        RCLCPP_INFO(this->get_logger(), "<<SETPOINT CREATOR AND CONTROLLER INITIATED>>");


    }
 
private:
    //Internal variables.
    int v = 0; //linear velocity
    int w = 0; //angular velocity
    std::vector<Pose> positions; // target positions

    void publishControl() //Publishing the twist of the robot.
    {;

        float vel_linear = this->v; //Getting linear and angular velocities.
        float vel_angular = this->w;

        auto msg1 = geometry_msgs::msg::Twist(); //Initializing the type of the message and setting its variables.
        msg1.linear.x = vel_linear;
        msg1.angular.z = vel_angular;

        publisher_twist->publish(msg1); //Publishing.
    }

    void publishTarget() //Publishing the next target.
    {;

        float x_pos = this->positions.at(0).x; //Getting the next target's positions
        float y_pos = this->positions.at(0).y;

        auto msg1 = assign1_interfaces::msg::PixelCoordinates(); //Initializing the type of the message.
        msg1.x = x_pos;
        msg1.y = y_pos;

        publisher_target->publish(msg1); //Publishing
    }

    void set_vel(float linear, float angular){ //setter for linear and angular velocities.

        this->v=linear;
        this->w=angular;

    }

    void point_callback(const assign1_interfaces::msg::PixelCoordinates::SharedPtr msg){ //Callback when getting the center of gravity.
        int x_obj; //Position of the object.
        int y_obj;

        x_obj=msg->x; //extracting the information from the message.
        y_obj=msg->y;

        Pose pose_now; //Variable of type "Pose" to save in the targets vector.
        pose_now.x=x_obj;
        pose_now.y=y_obj;

        if(x_obj!=-1){ //Checking it is a valid value.

            if(this->positions.size()<10){ //Checking there's still space in the vector.
                this->positions.push_back(pose_now); //Adding the position to the targets vector.
                RCLCPP_INFO(this->get_logger(), "Pose added to path.");
            }
    
        }

        
    }

    void position_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) //Callback when getting the position of the robot.
    {
        float x_current = msg->pose.position.x; //Getting the position from the message.
        float y_current = msg->pose.position.y;
        float z_current = msg->pose.orientation.z;

        float x_goal = this->positions.at(0).x; //Getting the goal from the targets vector.
        float y_goal = this->positions.at(0).y;

        float error_x = x_goal - x_current; //find error in position for each coordinate.
        float error_y = y_goal - y_current;

        float success = 5;//Setting the threshold for success.

        float distance = std::sqrt(error_x * error_x + error_y * error_y); //Calculate real distance

        float error_angle = std::atan2(error_y, error_x)-z_current; //Calculate the error in the angle.

        float K_distance = 1; // constants for the control.
        float K_angle = 2;

        float linear_velocity = K_distance * distance; //Calculate linear and angular velocities.
        float angular_velocity = K_angle * error_angle;

        float max_linear = 2;//setting max angular and linear velocities.
        float max_angular = 2;
        float min_angular = -2;

        if(linear_velocity>max_linear){ //Trimming velocities according to the max.
            linear_velocity=max_linear;
        }

        if(angular_velocity>max_angular){
            angular_velocity=max_angular;
        }
        if(angular_velocity<min_angular){
            angular_velocity=min_angular;
        }

        if(distance<success){ //CHecking if we are close enough to the point.
            
            RCLCPP_INFO(this->get_logger(), "<<SUCCESS>>"); //Point reached.

            linear_velocity=0; //stopping the robot.
            angular_velocity=0;

            if(this->positions.size()>1){ // Checking the vector is not empty.
                this->positions.erase(positions.begin()); //If its not the last position in the vector, remove it.
            }else{ //If it is, give a warning.
                RCLCPP_INFO(this->get_logger(), "<<That was the last position!\n Move the center of the object in the tracking screen to add more!>>");
            }

        }else{ //If we are not close enough, set the velocities.
            linear_velocity=linear_velocity;
            angular_velocity=angular_velocity;
        }
        
        set_vel(linear_velocity,angular_velocity); //Setting velocities.
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_twist;
    rclcpp::Publisher<assign1_interfaces::msg::PixelCoordinates>::SharedPtr publisher_target;
    rclcpp::Subscription<assign1_interfaces::msg::PixelCoordinates>::SharedPtr subscription_point;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr subscription_pose;
    rclcpp::TimerBase::SharedPtr timer_1;
    rclcpp::TimerBase::SharedPtr timer_2;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Controller>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}