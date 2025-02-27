// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "assign1_interfaces/msg/pixel_coordinates.h"


#ifndef ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__FUNCTIONS_H_
#define ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "assign1_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "assign1_interfaces/msg/detail/pixel_coordinates__struct.h"

/// Initialize msg/PixelCoordinates message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * assign1_interfaces__msg__PixelCoordinates
 * )) before or use
 * assign1_interfaces__msg__PixelCoordinates__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
bool
assign1_interfaces__msg__PixelCoordinates__init(assign1_interfaces__msg__PixelCoordinates * msg);

/// Finalize msg/PixelCoordinates message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
void
assign1_interfaces__msg__PixelCoordinates__fini(assign1_interfaces__msg__PixelCoordinates * msg);

/// Create msg/PixelCoordinates message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * assign1_interfaces__msg__PixelCoordinates__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
assign1_interfaces__msg__PixelCoordinates *
assign1_interfaces__msg__PixelCoordinates__create(void);

/// Destroy msg/PixelCoordinates message.
/**
 * It calls
 * assign1_interfaces__msg__PixelCoordinates__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
void
assign1_interfaces__msg__PixelCoordinates__destroy(assign1_interfaces__msg__PixelCoordinates * msg);

/// Check for msg/PixelCoordinates message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
bool
assign1_interfaces__msg__PixelCoordinates__are_equal(const assign1_interfaces__msg__PixelCoordinates * lhs, const assign1_interfaces__msg__PixelCoordinates * rhs);

/// Copy a msg/PixelCoordinates message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
bool
assign1_interfaces__msg__PixelCoordinates__copy(
  const assign1_interfaces__msg__PixelCoordinates * input,
  assign1_interfaces__msg__PixelCoordinates * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
const rosidl_type_hash_t *
assign1_interfaces__msg__PixelCoordinates__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
assign1_interfaces__msg__PixelCoordinates__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
const rosidl_runtime_c__type_description__TypeSource *
assign1_interfaces__msg__PixelCoordinates__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
assign1_interfaces__msg__PixelCoordinates__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/PixelCoordinates messages.
/**
 * It allocates the memory for the number of elements and calls
 * assign1_interfaces__msg__PixelCoordinates__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
bool
assign1_interfaces__msg__PixelCoordinates__Sequence__init(assign1_interfaces__msg__PixelCoordinates__Sequence * array, size_t size);

/// Finalize array of msg/PixelCoordinates messages.
/**
 * It calls
 * assign1_interfaces__msg__PixelCoordinates__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
void
assign1_interfaces__msg__PixelCoordinates__Sequence__fini(assign1_interfaces__msg__PixelCoordinates__Sequence * array);

/// Create array of msg/PixelCoordinates messages.
/**
 * It allocates the memory for the array and calls
 * assign1_interfaces__msg__PixelCoordinates__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
assign1_interfaces__msg__PixelCoordinates__Sequence *
assign1_interfaces__msg__PixelCoordinates__Sequence__create(size_t size);

/// Destroy array of msg/PixelCoordinates messages.
/**
 * It calls
 * assign1_interfaces__msg__PixelCoordinates__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
void
assign1_interfaces__msg__PixelCoordinates__Sequence__destroy(assign1_interfaces__msg__PixelCoordinates__Sequence * array);

/// Check for msg/PixelCoordinates message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
bool
assign1_interfaces__msg__PixelCoordinates__Sequence__are_equal(const assign1_interfaces__msg__PixelCoordinates__Sequence * lhs, const assign1_interfaces__msg__PixelCoordinates__Sequence * rhs);

/// Copy an array of msg/PixelCoordinates messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_assign1_interfaces
bool
assign1_interfaces__msg__PixelCoordinates__Sequence__copy(
  const assign1_interfaces__msg__PixelCoordinates__Sequence * input,
  assign1_interfaces__msg__PixelCoordinates__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ASSIGN1_INTERFACES__MSG__DETAIL__PIXEL_COORDINATES__FUNCTIONS_H_
