cmake_minimum_required(VERSION 3.8)
project(image_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# to help cmake find opencv
set(OpenCV_DIR "/usr/lib/x86_64-linux-gnu/cmake/opencv4")

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(assign1_interfaces REQUIRED)

add_executable(detector src/light_detector.cpp)
ament_target_dependencies(detector rclcpp sensor_msgs example_interfaces)

add_executable(position src/object_position.cpp)
target_link_libraries(position ${OpenCV_LIBS})
ament_target_dependencies(position rclcpp cv_bridge OpenCV assign1_interfaces)

install(TARGETS 
  detector
  position
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
