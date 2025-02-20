#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;
     
class Brightness : public rclcpp::Node 
{
public:
    Brightness() : Node("brightness") 
    {
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image", 10,
        std::bind(&Brightness::callbackImage, this, std::placeholders::_1));
        
        publisher_ = this->create_publisher<example_interfaces::msg::String>("bright", 10);
        timer_ = this->create_wall_timer(0.5s, std::bind(&Brightness::publishBright, this));
        
        RCLCPP_INFO(this->get_logger(), "Brightness node has begun");
    }
 
private:
    void publishBright()
    {
        std::string statement {"it is light"};
        if(bright_ == 0) statement = "it is dark";

        auto msg = example_interfaces::msg::String();
        msg.data = statement;
        publisher_->publish(msg);
    }

    void callbackImage(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        std::uint32_t rows = msg->height;
        std::uint32_t step = msg->step;

        int total {0};
        for(std::size_t i{0}; i < rows * step; i++)
        {
            total += msg->data[i];
        }
        // I find it unlikely the camera will be more than ~32k * ~32k in pixel size
        // so I'm judging this static cast as okay
        int avg { total / static_cast<int>(rows * step) };

        const int threshold = 130;
        if(avg > threshold) bright_ = 1;
        else bright_ = 0;

        RCLCPP_INFO(this->get_logger(), "avg is currently '%d'", avg);
    }

    bool bright_ {0};
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber_;
    rclcpp::TimerBase::SharedPtr timer_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Brightness>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}