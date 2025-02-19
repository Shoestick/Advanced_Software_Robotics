#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
     
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
        int avg { total / static_cast<int>(rows * step) };

        RCLCPP_INFO(this->get_logger(), "avg pixel value is '%d'", avg);

    }

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