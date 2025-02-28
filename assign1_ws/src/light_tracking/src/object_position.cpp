#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "assign1_interfaces/msg/pixel_coordinates.hpp"
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

using namespace std::chrono_literals;

/**
 * @brief 
 * 
 * Subscribes to topic /image, converts incoming image to greyscale before 
 * binary thresholding the image over some threshold. Calculates centroid of
 * binary image object pixels and publishes them to /cog_object using custom
 * interface.
 * 
 * @note If no object pixels found, publishes (x=-1, y=-1).
 */
class ObjectPositionNode : public rclcpp::Node
{
public:
    ObjectPositionNode() : Node("object_position"), p_(cv::Point(-1, -1))
    {
        // declare parameter controlling threshold value and publish speed
        this->declare_parameter("threshold", 242);
        this->declare_parameter("timer_period", 1.0);

        // subscribe to /image topic and call callbackObjPos function when 
        // receiving data
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image", 10,
        std::bind(&ObjectPositionNode::callbackObjPos, this, 
                                                        std::placeholders::_1));

        
        // create a topic called cog that publishes publishCog at timed interval
        publisher_ = this->create_publisher<assign1_interfaces::msg
                                        ::PixelCoordinates>("cog_object", 10);
        double timer_period { this->get_parameter("timer_period").as_double() };
        timer_ = this->create_wall_timer(std::chrono::duration<double>(timer_period), 
            std::bind(&ObjectPositionNode::publishCog, this));

        // log node starting
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

    /**
     * @brief Callback function that calculates CoG of object in incoming image 
     * messages.
     * 
     * Takes in an image from /image. Applies a binary threshold to the image, 
     * then calulates centre of gravity of remaining object. Centre of gravity 
     * set to -1 -1 if no object pixels detected.
     * 
     * @param msg Image message type received from /image.
     * @note Robust against different 8bit image encodings.
     */
    void callbackObjPos(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        // convert /image msg to cv::Mat
        cv::Mat src = cv_bridge::toCvCopy(msg, msg->encoding)->image;
        cv::Mat grey {};

        if (msg->encoding == sensor_msgs::image_encodings::MONO8) {
            grey = src.clone();
        } else if (msg->encoding == sensor_msgs::image_encodings::BGR8) {
            cvtColor(src, grey, cv::COLOR_BGR2GRAY);
        } else if (msg->encoding == sensor_msgs::image_encodings::RGB8) {
            cvtColor(src, grey, cv::COLOR_RGB2GRAY);
        } else {
            RCLCPP_WARN(this->get_logger(), "Unsupported image encoding: %s", 
                                                        msg->encoding.c_str());
            return;
        }

        cv::Mat threshed {};
        threshold_value_ = this->get_parameter("threshold").as_int();
        int const threshold_type {0}; // binary threshold specifier
        
        threshold( grey, threshed, threshold_value_, 255, threshold_type );

        // check if object exists before giving position value
        if(countNonZero(threshed))
        {
            // use moments to calculate centroid of object
            cv::Moments m = cv::moments(threshed, true);
            p_ = cv::Point(m.m10/m.m00, m.m01/m.m00);
        }
        else
        {
            // no object value
            p_ = cv::Point(-1, -1);
        }
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