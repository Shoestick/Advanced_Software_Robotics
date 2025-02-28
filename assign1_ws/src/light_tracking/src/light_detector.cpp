#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "example_interfaces/msg/string.hpp"

// equal to the threshold means dark

/**
 * @brief Publishes whether or not input image is light or dark on average.
 * 
 * Subscribes to topic /image, then finds the average pixel value of the given
 * image. The average is compared to a threshold and depending on if it is found
 * above or below it will be considered light or dark. If state changes, it is
 * published to topic /bright.
 * 
 * @note Averages equal to the threshold are considered dark.
 * @warning Image inputs larger than ~32k * ~32k will cause an integer error.
 * @warning Image message with empty or 0 values in members will cause undefined
 * behaviour.
 */
class LightDetector : public rclcpp::Node 
{
public:
LightDetector() : Node("light_detector"), bright_old_(0)
    {
        // declare parameter for threshold value
        this->declare_parameter("threshold", 242);

        // begin subscriber to /image, call callbackLuminance when recieving 
        // something from the topic
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image", 10,
        std::bind(&LightDetector::callbackLuminance, this, std::placeholders::_1));
        
        // create a publisher called /bright, publish when state of luminance 
        // changes
        publisher_ = this->create_publisher<example_interfaces::msg
                                                        ::String>("bright", 10);
        
        // log node starting
        RCLCPP_INFO(this->get_logger(), "Light Detector node has begun");
    }
 
private:
    /**
     * @brief Callback function to check luminance of incoming image messages.
     * 
     * Calculates the size of the image, then adds up all the incoming values
     * before dividing to get the average. Compares average to threshold, if 
     * stat of luminance has changed, publishes it to /bright.
     * 
     * @param msg Image message type received from /image.
     */
    void callbackLuminance(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        // load in variables to get the size of the msg.data 
        std::uint32_t rows = msg->height;
        std::uint32_t step = msg->step;

        // add all pixel values and divide by num pixels to get average
        int total {0};
        for(std::size_t i{0}; i < rows * step; i++)
        {
            total += msg->data[i];
        }

        int avg { total / static_cast<int>(rows * step) };

        // get threshold parameter, make sure it's within range
        threshold_value_ = this->get_parameter("threshold").as_int();
        threshold_value_ = std::clamp(threshold_value_, 0, 255);

        // bool for whether or not brightness of image is above threshold
        bool bright { avg > threshold_value_ };

        // publish to topic if status changes
        if(bright != bright_old_)
        {
            bright_old_ = bright;

            std::string statement = bright ? "it is light" : "it is dark";

            auto msg = example_interfaces::msg::String();
            msg.data = statement;
            publisher_->publish(msg);

            RCLCPP_INFO(this->get_logger(), "avg is currently '%d'", avg);
        }
    }

    bool bright_old_ {};
    int threshold_value_ {};
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LightDetector>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}