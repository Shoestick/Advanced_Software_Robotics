#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "example_interfaces/msg/string.hpp"

// equal to the threshold means dark

class Brightness : public rclcpp::Node 
{
public:
    Brightness() : Node("brightness") 
    {
        // declare parameter to later get
        this->declare_parameter("threshold", 130);

        // begin subscriber to /image, call callbackImage when recieving something from the topic
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image", 10,
        std::bind(&Brightness::callbackImage, this, std::placeholders::_1));
        
        // create a publisher called /bright, publish publishBright every half second
        publisher_ = this->create_publisher<example_interfaces::msg::String>("bright", 10);
        
        // text to terminal when starting
        RCLCPP_INFO(this->get_logger(), "Brightness node has begun");
    }
 
private:
    // 
    void callbackImage(const sensor_msgs::msg::Image::SharedPtr msg)
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
        // I find it unlikely the camera will be more than ~32k * ~32k in pixel size
        // so I'm judging this static cast as okay
        int avg { total / static_cast<int>(rows * step) };

        // get threshold parameter
        threshold_ = this->get_parameter("threshold").as_int();

        // bool for whether or not brightness of image is above threshold
        bool bright { 0 };
        if(avg > threshold_) bright = 1;

        // if the avg changes to being above/below threshold, publish to topic
        if(bright != bright_old_)
        {
            bright_old_ = bright;

            std::string statement {"it is dark"};
            if(bright == 1) statement = "it is light";

            auto msg = example_interfaces::msg::String();
            msg.data = statement;
            publisher_->publish(msg);

            RCLCPP_INFO(this->get_logger(), "avg is currently '%d'", avg);
        }
    }

    bool bright_old_ {0};
    int threshold_ {0};
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Brightness>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}