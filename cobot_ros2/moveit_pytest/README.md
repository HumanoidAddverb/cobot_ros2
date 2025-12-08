MoveIt Python Interface – moveit_pytest
=======================================

This package provides Python-based testing and example scripts to interface with MoveIt using ROS 2 

---------------------------------------
CONTROLLER SETUP
---------------------------------------
Before running MoveIt commands, ensure the ptp_joint_controller is activated on the robot, else the motion will not be executed on the robot.

Use the following command to switch controllers:

    ros2 service call /controller_manager/switch_controller controller_manager_msgs/srv/SwitchController "{ activate_controllers: ['ptp_joint_controller'], deactivate_controllers: ['<YOUR_ACTIVE_CONTROLLER>'], start_controllers: [], stop_controllers: [], strictness: 0, start_asap: false, activate_asap: false, timeout: {sec: 0, nanosec: 0}}"

Replace <YOUR_ACTIVE_CONTROLLER> with the currently active controller (e.g., a trajectory controller or another joint controller).  
Please Note: Any one contoroller should be active at a given time! Ensure that the previously active controllers are inactive.


---------------------------------------
HOW TO USE
---------------------------------------

# 1. Using MoveIt with RViz Simulation:

To run MoveIt in simulation mode with RViz, launch:

    ros2 launch syncro_5_moveit_config demo.launch.py

This will launch:
- MoveIt
- RViz with robot model
- A simulated joint controller

# 2. Using MoveIt with Real Robot (No Simulation):

First, launch MoveIt without simulation:

    ros2 launch syncro_5_moveit_config move_group.launch.py

To view the robot and planning in RViz (optional), open a new terminal and run:

    ros2 launch syncro_5_moveit_config moveit_rviz.launch.py


# 3. Testing MoveIt Functionality:

An example script is provided in the moveit_pytest package to test basic planning and execution:

    ros2 run moveit_pytest plan_and_execute

This script:
- Randomly generates joint-space goal points
- Plans motion trajectories using MoveIt
- Executes the planned motion on the robot and simulation if active
