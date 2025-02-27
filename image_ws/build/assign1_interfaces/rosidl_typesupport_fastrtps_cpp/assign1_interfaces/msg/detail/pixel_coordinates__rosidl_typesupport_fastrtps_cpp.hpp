// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice

#ifndef ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "assign1_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "assign1_interfaces/msg/detail/pixel_coordinates__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace assign1_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_assign1_interfaces
cdr_serialize(
  const assign1_interfaces::msg::PixelCoordinates & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_assign1_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  assign1_interfaces::msg::PixelCoordinates & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_assign1_interfaces
get_serialized_size(
  const assign1_interfaces::msg::PixelCoordinates & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_assign1_interfaces
max_serialized_size_PixelCoordinates(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_assign1_interfaces
cdr_serialize_key(
  const assign1_interfaces::msg::PixelCoordinates & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_assign1_interfaces
get_serialized_size_key(
  const assign1_interfaces::msg::PixelCoordinates & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_assign1_interfaces
max_serialized_size_key_PixelCoordinates(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace assign1_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_assign1_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, assign1_interfaces, msg, PixelCoordinates)();

#ifdef __cplusplus
}
#endif

#endif  // ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
