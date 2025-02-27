// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "assign1_interfaces/msg/detail/pixel_coordinates__functions.h"
#include "assign1_interfaces/msg/detail/pixel_coordinates__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace assign1_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void PixelCoordinates_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) assign1_interfaces::msg::PixelCoordinates(_init);
}

void PixelCoordinates_fini_function(void * message_memory)
{
  auto typed_message = static_cast<assign1_interfaces::msg::PixelCoordinates *>(message_memory);
  typed_message->~PixelCoordinates();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PixelCoordinates_message_member_array[2] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(assign1_interfaces::msg::PixelCoordinates, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(assign1_interfaces::msg::PixelCoordinates, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PixelCoordinates_message_members = {
  "assign1_interfaces::msg",  // message namespace
  "PixelCoordinates",  // message name
  2,  // number of fields
  sizeof(assign1_interfaces::msg::PixelCoordinates),
  false,  // has_any_key_member_
  PixelCoordinates_message_member_array,  // message members
  PixelCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  PixelCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PixelCoordinates_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PixelCoordinates_message_members,
  get_message_typesupport_handle_function,
  &assign1_interfaces__msg__PixelCoordinates__get_type_hash,
  &assign1_interfaces__msg__PixelCoordinates__get_type_description,
  &assign1_interfaces__msg__PixelCoordinates__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace assign1_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<assign1_interfaces::msg::PixelCoordinates>()
{
  return &::assign1_interfaces::msg::rosidl_typesupport_introspection_cpp::PixelCoordinates_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, assign1_interfaces, msg, PixelCoordinates)() {
  return &::assign1_interfaces::msg::rosidl_typesupport_introspection_cpp::PixelCoordinates_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
