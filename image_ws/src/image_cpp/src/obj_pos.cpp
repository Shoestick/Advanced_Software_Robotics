// create my own message type... based off turtle node type??
// publish the x, y coord to a new topic

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "assign1_interfaces/msg/pixel_coordinates.hpp"
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>

using namespace std::chrono_literals;
     
class ObjectPosNode : public rclcpp::Node
{
public:
    ObjectPosNode() : Node("obj_pos")
    {
        // declare parameter controlling threshold value
        this->declare_parameter("threshold", 242);

        // subscribe to /image topic and call callbackImage function when recieving data
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image", 10,
        std::bind(&ObjectPosNode::callbackImage, this, std::placeholders::_1));

        // create a topic called cog that publishes publishCog every half second
        //publisher_ = this->create_publisher<assign1_interfaces::msg::PixelCoordinates>("cog", 10);
        //timer_ = this->create_wall_timer(1s, std::bind(&ObjectPosNode::publishCog, this));

        // text to terminal when starting
        RCLCPP_INFO(this->get_logger(), "Object position node has begun");
    }

private:

    void publishCog()
    {

    }

    void callbackImage(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        // will need to change the "bgr8" to manage other formats of image
        cv::Mat src = cv_bridge::toCvCopy(msg, "bgr8")->image;

        cv::Mat grey {};
        cvtColor(src, grey, CV_BGR2GRAY);

        cv::Mat threshed {};

        int const threshold_type {0};
        threshold_value_ = this->get_parameter("threshold").as_int();

        threshold( grey, threshed, threshold_value_, 255, threshold_type );

        // find moments of the image
        cv::Moments m = cv::moments(threshed, true);
        p_ = cv::Point(m.m10/m.m00, m.m01/m.m00);

        RCLCPP_INFO(this->get_logger(), "Centroid of object: (%d, %d)", p_.x, p_.y);
        
        // show the image with a point mark at the centroid
        circle(src, p_, 5, cv::Scalar(128,0,0), -1);
        cv::imshow("Image with center",src);
        cv::waitKey('q'); 
    }


    int threshold_value_ {};
    cv::Point p_ {};
    rclcpp::Publisher<assign1_interfaces::msg::PixelCoordinates>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
    rclcpp::TimerBase::SharedPtr timer_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ObjectPosNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}