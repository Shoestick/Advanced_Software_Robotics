#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "example_interfaces/msg/string.hpp"
     
class Brightness : public rclcpp::Node 
{
public:
    Brightness() : Node("brightness") 
    {
        
        subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
        "image", 10,
        std::bind(&Brightness::callbackImage, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "Brightness sub has begun");
    }
 
private:

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

        const int threshold = 200;
        if(avg > threshold) bright_ = 1;
        else bright_ = 0;

        const char* condition {"above"};
        if(bright_ == 0) condition = "below";

        RCLCPP_INFO(this->get_logger(), "compared to threshold, avg is '%s'", condition);
    }

    bool bright_ {0};
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