#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "assign1_interfaces/msg/pixel_coordinates.hpp"
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>

using namespace std::chrono_literals;
     
class ObjectPositionNode : public rclcpp::Node
{
public:
    ObjectPositionNode() : Node("object_position"), p_(cv::Point(-1, -1))
    {
        // declare parameter controlling threshold value
        this->declare_parameter("threshold", 242);
        this->declare_parameter("timer_period", 1.0);

        // subscribe to /image topic and call callbackObjPos function when receiving data
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image", 10,
        std::bind(&ObjectPositionNode::callbackObjPos, this, std::placeholders::_1));

        
        // create a topic called cog that publishes publishCog at timed interval
        publisher_ = this->create_publisher<assign1_interfaces::msg::PixelCoordinates>("cog_object", 10);
        double timer_period { this->get_parameter("timer_period").as_double() };
        timer_ = this->create_wall_timer(std::chrono::duration<double>(timer_period), 
            std::bind(&ObjectPositionNode::publishCog, this));

        // text to terminal when starting
        RCLCPP_INFO(this->get_logger(), "Object position node has begun");
    }

private:
    // publishes 2d coordinates of centre of gravity of object 
    void publishCog()
    {
        auto msg = assign1_interfaces::msg::PixelCoordinates();
        msg.x = p_.x;
        msg.y = p_.y;
        publisher_->publish(msg);
    }

    // applies a binary threshold to the image, then calulates centre of
    // gravity of remaining object
    void callbackObjPos(const sensor_msgs::msg::Image::SharedPtr msg)
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
    auto node = std::make_shared<ObjectPositionNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}