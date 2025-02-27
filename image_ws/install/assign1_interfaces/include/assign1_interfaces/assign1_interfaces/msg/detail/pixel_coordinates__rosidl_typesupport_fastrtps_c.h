// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice
#ifndef ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "assign1_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "assign1_interfaces/msg/detail/pixel_coordinates__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
bool cdr_serialize_assign1_interfaces__msg__PixelCoordinates(
  const assign1_interfaces__msg__PixelCoordinates * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
bool cdr_deserialize_assign1_interfaces__msg__PixelCoordinates(
  eprosima::fastcdr::Cdr &,
  assign1_interfaces__msg__PixelCoordinates * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
size_t get_serialized_size_assign1_interfaces__msg__PixelCoordinates(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
size_t max_serialized_size_assign1_interfaces__msg__PixelCoordinates(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
bool cdr_serialize_key_assign1_interfaces__msg__PixelCoordinates(
  const assign1_interfaces__msg__PixelCoordinates * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
size_t get_serialized_size_key_assign1_interfaces__msg__PixelCoordinates(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
size_t max_serialized_size_key_assign1_interfaces__msg__PixelCoordinates(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, assign1_interfaces, msg, PixelCoordinates)();

#ifdef __cplusplus
}
#endif

#endif  // ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
