// grayscale or pick a colour channel
// threshold into binary image
// find the "centre of gravity" of the white pixels
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
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image", 10,
        std::bind(&ObjectPosNode::callbackImage, this, std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Object position node has begun");
    }

private:
    void callbackImage(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        // will need to change the "bgr8" to manage other formats of image
        cv::Mat image = cv_bridge::toCvCopy(msg, "bgr8")->image;
        cv::Mat grey;
        cvtColor(image, grey, CV_BGR2GRAY);
        cv::imshow("OpenCV window", grey);
        cv::waitKey('q');       
    }

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