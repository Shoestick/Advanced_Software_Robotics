// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "assign1_interfaces/msg/pixel_coordinates.hpp"


#ifndef ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__STRUCT_HPP_
#define ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__assign1_interfaces__msg__PixelCoordinates __attribute__((deprecated))
#else
# define DEPRECATED__assign1_interfaces__msg__PixelCoordinates __declspec(deprecated)
#endif

namespace assign1_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PixelCoordinates_
{
  using Type = PixelCoordinates_<ContainerAllocator>;

  explicit PixelCoordinates_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0;
      this->y = 0;
    }
  }

  explicit PixelCoordinates_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0;
      this->y = 0;
    }
  }

  // field types and members
  using _x_type =
    int16_t;
  _x_type x;
  using _y_type =
    int16_t;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const int16_t & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const int16_t & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator> *;
  using ConstRawPtr =
    const assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__assign1_interfaces__msg__PixelCoordinates
    std::shared_ptr<assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__assign1_interfaces__msg__PixelCoordinates
    std::shared_ptr<assign1_interfaces::msg::PixelCoordinates_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PixelCoordinates_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const PixelCoordinates_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PixelCoordinates_

// alias to use template instance with default allocator
using PixelCoordinates =
  assign1_interfaces::msg::PixelCoordinates_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace assign1_interfaces

#endif  // ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__STRUCT_HPP_
