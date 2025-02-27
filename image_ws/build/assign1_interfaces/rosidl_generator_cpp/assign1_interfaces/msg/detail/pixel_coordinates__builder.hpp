// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "assign1_interfaces/msg/pixel_coordinates.hpp"


#ifndef ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__BUILDER_HPP_
#define ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "assign1_interfaces/msg/detail/pixel_coordinates__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace assign1_interfaces
{

namespace msg
{

namespace builder
{

class Init_PixelCoordinates_y
{
public:
  explicit Init_PixelCoordinates_y(::assign1_interfaces::msg::PixelCoordinates & msg)
  : msg_(msg)
  {}
  ::assign1_interfaces::msg::PixelCoordinates y(::assign1_interfaces::msg::PixelCoordinates::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::assign1_interfaces::msg::PixelCoordinates msg_;
};

class Init_PixelCoordinates_x
{
public:
  Init_PixelCoordinates_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PixelCoordinates_y x(::assign1_interfaces::msg::PixelCoordinates::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PixelCoordinates_y(msg_);
  }

private:
  ::assign1_interfaces::msg::PixelCoordinates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::assign1_interfaces::msg::PixelCoordinates>()
{
  return assign1_interfaces::msg::builder::Init_PixelCoordinates_x();
}

}  // namespace assign1_interfaces

#endif  // ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__BUILDER_HPP_
