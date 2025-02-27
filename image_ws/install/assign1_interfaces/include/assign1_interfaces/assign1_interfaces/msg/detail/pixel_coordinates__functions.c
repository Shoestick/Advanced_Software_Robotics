// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from assign1_interfaces:msg/PixelCoordinates.idl
// generated code does not contain a copyright notice
#include "assign1_interfaces/msg/detail/pixel_coordinates__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
assign1_interfaces__msg__PixelCoordinates__init(assign1_interfaces__msg__PixelCoordinates * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
assign1_interfaces__msg__PixelCoordinates__fini(assign1_interfaces__msg__PixelCoordinates * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
assign1_interfaces__msg__PixelCoordinates__are_equal(const assign1_interfaces__msg__PixelCoordinates * lhs, const assign1_interfaces__msg__PixelCoordinates * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
assign1_interfaces__msg__PixelCoordinates__copy(
  const assign1_interfaces__msg__PixelCoordinates * input,
  assign1_interfaces__msg__PixelCoordinates * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

assign1_interfaces__msg__PixelCoordinates *
assign1_interfaces__msg__PixelCoordinates__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  assign1_interfaces__msg__PixelCoordinates * msg = (assign1_interfaces__msg__PixelCoordinates *)allocator.allocate(sizeof(assign1_interfaces__msg__PixelCoordinates), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(assign1_interfaces__msg__PixelCoordinates));
  bool success = assign1_interfaces__msg__PixelCoordinates__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
assign1_interfaces__msg__PixelCoordinates__destroy(assign1_interfaces__msg__PixelCoordinates * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    assign1_interfaces__msg__PixelCoordinates__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
assign1_interfaces__msg__PixelCoordinates__Sequence__init(assign1_interfaces__msg__PixelCoordinates__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  assign1_interfaces__msg__PixelCoordinates * data = NULL;

  if (size) {
    data = (assign1_interfaces__msg__PixelCoordinates *)allocator.zero_allocate(size, sizeof(assign1_interfaces__msg__PixelCoordinates), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = assign1_interfaces__msg__PixelCoordinates__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        assign1_interfaces__msg__PixelCoordinates__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
assign1_interfaces__msg__PixelCoordinates__Sequence__fini(assign1_interfaces__msg__PixelCoordinates__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      assign1_interfaces__msg__PixelCoordinates__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

assign1_interfaces__msg__PixelCoordinates__Sequence *
assign1_interfaces__msg__PixelCoordinates__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  assign1_interfaces__msg__PixelCoordinates__Sequence * array = (assign1_interfaces__msg__PixelCoordinates__Sequence *)allocator.allocate(sizeof(assign1_interfaces__msg__PixelCoordinates__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = assign1_interfaces__msg__PixelCoordinates__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
assign1_interfaces__msg__PixelCoordinates__Sequence__destroy(assign1_interfaces__msg__PixelCoordinates__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    assign1_interfaces__msg__PixelCoordinates__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
assign1_interfaces__msg__PixelCoordinates__Sequence__are_equal(const assign1_interfaces__msg__PixelCoordinates__Sequence * lhs, const assign1_interfaces__msg__PixelCoordinates__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!assign1_interfaces__msg__PixelCoordinates__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
assign1_interfaces__msg__PixelCoordinates__Sequence__copy(
  const assign1_interfaces__msg__PixelCoordinates__Sequence * input,
  assign1_interfaces__msg__PixelCoordinates__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(assign1_interfaces__msg__PixelCoordinates);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    assign1_interfaces__msg__PixelCoordinates * data =
      (assign1_interfaces__msg__PixelCoordinates *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!assign1_interfaces__msg__PixelCoordinates__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          assign1_interfaces__msg__PixelCoordinates__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!assign1_interfaces__msg__PixelCoordinates__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
