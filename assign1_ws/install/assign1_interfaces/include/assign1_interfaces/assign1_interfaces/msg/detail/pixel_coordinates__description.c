// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice

#include "assign1_interfaces/msg/detail/pixel_coordinates__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
const rosidl_type_hash_t *
assign1_interfaces__msg__PixelCoordinates__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc6, 0xc8, 0xb5, 0x8b, 0x62, 0x18, 0x9b, 0x9d,
      0xdc, 0xdc, 0x10, 0x7d, 0xf7, 0x4e, 0xc0, 0x0f,
      0x8b, 0xec, 0x6e, 0xa2, 0x4f, 0xb8, 0xc9, 0x42,
      0x49, 0x36, 0x31, 0x4d, 0x42, 0x7f, 0xf0, 0x01,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char assign1_interfaces__msg__PixelCoordinates__TYPE_NAME[] = "assign1_interfaces/msg/PixelCoordinates";

// Define type names, field names, and default values
static char assign1_interfaces__msg__PixelCoordinates__FIELD_NAME__x[] = "x";
static char assign1_interfaces__msg__PixelCoordinates__FIELD_NAME__y[] = "y";

static rosidl_runtime_c__type_description__Field assign1_interfaces__msg__PixelCoordinates__FIELDS[] = {
  {
    {assign1_interfaces__msg__PixelCoordinates__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {assign1_interfaces__msg__PixelCoordinates__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
assign1_interfaces__msg__PixelCoordinates__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {assign1_interfaces__msg__PixelCoordinates__TYPE_NAME, 39, 39},
      {assign1_interfaces__msg__PixelCoordinates__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int16 x\n"
  "int16 y";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
assign1_interfaces__msg__PixelCoordinates__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {assign1_interfaces__msg__PixelCoordinates__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 15, 15},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
assign1_interfaces__msg__PixelCoordinates__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *assign1_interfaces__msg__PixelCoordinates__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
