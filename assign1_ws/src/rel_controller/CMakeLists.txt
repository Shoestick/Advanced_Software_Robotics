cmake_minimum_required(VERSION 3.8)
project(rel_controller)

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
find_package(geometry_msgs REQUIRED)
find_package(assign1_interfaces REQUIRED)

add_executable(controller src/controller.cpp)
ament_target_dependencies(controller rclcpp sensor_msgs example_interfaces geometry_msgs assign1_interfaces) 

#add_executable(controller src/controller.cpp)
#target_link_libraries(controller ${OpenCV_LIBS})
#ament_target_dependencies(controller rclcpp cv_bridge OpenCV)

install(TARGETS 
  controller
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
