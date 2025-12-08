cmake_minimum_required(VERSION 3.8)
project(examples)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(addverb_cobot_msgs REQUIRED)
find_package(control_msgs REQUIRED)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

add_executable(demo_velocity src/demo_velocity.cpp)
ament_target_dependencies(demo_velocity rclcpp std_msgs)

add_executable(demo_effort src/demo_effort.cpp)
ament_target_dependencies(demo_effort rclcpp geometry_msgs)

add_executable(demo_gravity_comp_effort src/demo_gravity_comp_effort.cpp)
ament_target_dependencies(demo_gravity_comp_effort rclcpp geometry_msgs)

add_executable(demo_joint_jogging src/demo_joint_jogging.cpp)
ament_target_dependencies(demo_joint_jogging rclcpp addverb_cobot_msgs)

add_executable(demo_cartesian_jogging src/demo_cartesian_jogging.cpp)
ament_target_dependencies(demo_cartesian_jogging rclcpp addverb_cobot_msgs geometry_msgs)

add_executable(demo_gripper src/demo_gripper.cpp)
ament_target_dependencies(demo_gripper rclcpp addverb_cobot_msgs geometry_msgs)

add_executable(demo_joint_impedance src/demo_joint_impedance.cpp)
ament_target_dependencies(demo_joint_impedance rclcpp rclcpp_action rclcpp_components addverb_cobot_msgs control_msgs)

add_executable(demo_cartesian_impedance src/demo_cartesian_impedance.cpp)
ament_target_dependencies(demo_cartesian_impedance rclcpp rclcpp_action rclcpp_components addverb_cobot_msgs control_msgs)

add_executable(demo_ptp_tcp src/demo_ptp_tcp.cpp)
ament_target_dependencies(demo_ptp_tcp rclcpp rclcpp_action rclcpp_components addverb_cobot_msgs)

add_executable(demo_recorder src/demo_recorder.cpp)
ament_target_dependencies(demo_recorder rclcpp rclcpp_action rclcpp_components addverb_cobot_msgs)

############## PTP 
add_library(ptp_demo_client SHARED src/demo_ptp_joint.cpp)

ament_target_dependencies(ptp_demo_client
  "rclcpp"
  "rclcpp_action"
  "rclcpp_components"
  "trajectory_msgs"
  "control_msgs")

rclcpp_components_register_node(ptp_demo_client PLUGIN "ptp::DemoClient" EXECUTABLE demo_ptp_joint)

install(TARGETS
  demo_velocity
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  demo_effort
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  demo_gravity_comp_effort
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  demo_joint_jogging
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  demo_cartesian_jogging
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  demo_joint_impedance
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  demo_gripper
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  demo_recorder
  DESTINATION lib/${PROJECT_NAME})

  install(TARGETS
  demo_ptp_tcp
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
  demo_cartesian_impedance
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS
ptp_demo_client
ARCHIVE DESTINATION lib
LIBRARY DESTINATION lib
RUNTIME DESTINATION bin)


ament_package()
