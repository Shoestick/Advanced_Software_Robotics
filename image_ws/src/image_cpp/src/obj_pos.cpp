// find the "centre of gravity" of the white pixels, publish this to the terminal
// publish this CoG to a topic

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
     
class ObjectPosNode : public rclcpp::Node
{
public:
    ObjectPosNode() : Node("obj_pos")
    {
        // declare parameter controlling threshold value
        this->declare_parameter("threshold", 130);

        // subscribe to /image topic and call callbackImage function when recieving data
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image", 10,
        std::bind(&ObjectPosNode::callbackImage, this, std::placeholders::_1));

        // text to terminal when starting
        RCLCPP_INFO(this->get_logger(), "Object position node has begun");
    }

private:
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
        cv::Point p(m.m10/m.m00, m.m01/m.m00);

        RCLCPP_INFO(this->get_logger(), "Centroid of object: (%d, %d)", p.x, p.y);
        
        // show the image with a point mark at the centroid
        circle(src, p, 5, cv::Scalar(128,0,0), -1);
        cv::imshow("Image with center",src);
        cv::waitKey('q'); 
    }

    int threshold_value_ {};
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ObjectPosNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}