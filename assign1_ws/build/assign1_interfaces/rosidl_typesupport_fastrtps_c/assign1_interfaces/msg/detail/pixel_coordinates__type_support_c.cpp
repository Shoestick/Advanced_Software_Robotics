// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice
#include "assign1_interfaces/msg/detail/pixel_coordinates__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "assign1_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "assign1_interfaces/msg/detail/pixel_coordinates__struct.h"
#include "assign1_interfaces/msg/detail/pixel_coordinates__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _PixelCoordinates__ros_msg_type = assign1_interfaces__msg__PixelCoordinates;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
bool cdr_serialize_assign1_interfaces__msg__PixelCoordinates(
  const assign1_interfaces__msg__PixelCoordinates * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
bool cdr_deserialize_assign1_interfaces__msg__PixelCoordinates(
  eprosima::fastcdr::Cdr & cdr,
  assign1_interfaces__msg__PixelCoordinates * ros_message)
{
  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
size_t get_serialized_size_assign1_interfaces__msg__PixelCoordinates(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PixelCoordinates__ros_msg_type * ros_message = static_cast<const _PixelCoordinates__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
size_t max_serialized_size_assign1_interfaces__msg__PixelCoordinates(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = assign1_interfaces__msg__PixelCoordinates;
    is_plain =
      (
      offsetof(DataType, y) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
bool cdr_serialize_key_assign1_interfaces__msg__PixelCoordinates(
  const assign1_interfaces__msg__PixelCoordinates * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
size_t get_serialized_size_key_assign1_interfaces__msg__PixelCoordinates(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PixelCoordinates__ros_msg_type * ros_message = static_cast<const _PixelCoordinates__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_assign1_interfaces
size_t max_serialized_size_key_assign1_interfaces__msg__PixelCoordinates(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = assign1_interfaces__msg__PixelCoordinates;
    is_plain =
      (
      offsetof(DataType, y) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _PixelCoordinates__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const assign1_interfaces__msg__PixelCoordinates * ros_message = static_cast<const assign1_interfaces__msg__PixelCoordinates *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_assign1_interfaces__msg__PixelCoordinates(ros_message, cdr);
}

static bool _PixelCoordinates__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  assign1_interfaces__msg__PixelCoordinates * ros_message = static_cast<assign1_interfaces__msg__PixelCoordinates *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_assign1_interfaces__msg__PixelCoordinates(cdr, ros_message);
}

static uint32_t _PixelCoordinates__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_assign1_interfaces__msg__PixelCoordinates(
      untyped_ros_message, 0));
}

static size_t _PixelCoordinates__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_assign1_interfaces__msg__PixelCoordinates(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PixelCoordinates = {
  "assign1_interfaces::msg",
  "PixelCoordinates",
  _PixelCoordinates__cdr_serialize,
  _PixelCoordinates__cdr_deserialize,
  _PixelCoordinates__get_serialized_size,
  _PixelCoordinates__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _PixelCoordinates__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PixelCoordinates,
  get_message_typesupport_handle_function,
  &assign1_interfaces__msg__PixelCoordinates__get_type_hash,
  &assign1_interfaces__msg__PixelCoordinates__get_type_description,
  &assign1_interfaces__msg__PixelCoordinates__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, assign1_interfaces, msg, PixelCoordinates)() {
  return &_PixelCoordinates__type_support;
}

#if defined(__cplusplus)
}
#endif
