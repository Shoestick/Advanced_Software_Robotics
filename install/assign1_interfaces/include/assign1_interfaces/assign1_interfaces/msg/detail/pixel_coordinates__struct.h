// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "assign1_interfaces/msg/pixel_coordinates.h"


#ifndef ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__STRUCT_H_
#define ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/PixelCoordinates in the package assign1_interfaces.
typedef struct assign1_interfaces__msg__PixelCoordinates
{
  uint8_t x;
  uint8_t y;
} assign1_interfaces__msg__PixelCoordinates;

// Struct for a sequence of assign1_interfaces__msg__PixelCoordinates.
typedef struct assign1_interfaces__msg__PixelCoordinates__Sequence
{
  assign1_interfaces__msg__PixelCoordinates * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} assign1_interfaces__msg__PixelCoordinates__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__STRUCT_H_
