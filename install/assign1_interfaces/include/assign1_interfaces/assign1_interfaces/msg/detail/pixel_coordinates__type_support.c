// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "assign1_interfaces/msg/detail/pixel_coordinates__rosidl_typesupport_introspection_c.h"
#include "assign1_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "assign1_interfaces/msg/detail/pixel_coordinates__functions.h"
#include "assign1_interfaces/msg/detail/pixel_coordinates__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  assign1_interfaces__msg__PixelCoordinates__init(message_memory);
}

void assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_fini_function(void * message_memory)
{
  assign1_interfaces__msg__PixelCoordinates__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_message_member_array[2] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(assign1_interfaces__msg__PixelCoordinates, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(assign1_interfaces__msg__PixelCoordinates, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_message_members = {
  "assign1_interfaces__msg",  // message namespace
  "PixelCoordinates",  // message name
  2,  // number of fields
  sizeof(assign1_interfaces__msg__PixelCoordinates),
  false,  // has_any_key_member_
  assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_message_member_array,  // message members
  assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_init_function,  // function to initialize message memory (memory has to be allocated)
  assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_message_type_support_handle = {
  0,
  &assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_message_members,
  get_message_typesupport_handle_function,
  &assign1_interfaces__msg__PixelCoordinates__get_type_hash,
  &assign1_interfaces__msg__PixelCoordinates__get_type_description,
  &assign1_interfaces__msg__PixelCoordinates__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_assign1_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, assign1_interfaces, msg, PixelCoordinates)() {
  if (!assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_message_type_support_handle.typesupport_identifier) {
    assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &assign1_interfaces__msg__PixelCoordinates__rosidl_typesupport_introspection_c__PixelCoordinates_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
