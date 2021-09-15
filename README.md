# ROS Packages for Scout Mini in PolyU VICON

## Packages

This repository contains minimal packages to control the scout robot using ROS.

* scout_bringup: launch and configuration files to start ROS nodes 
* scout_base: a ROS wrapper around [ugv_sdk](https://github.com/agilexrobotics/ugv_sdk) to monitor and control the scout robot
* scout_description: URDF model for the mobile base, a sample urdf (scout_description/sample/scout_v2_nav.xacro) is provided for customized robot with addtional sensors
* scout_msgs: scout related message definitions

## Basic usage of the ROS packages

1. Install dependent libraries

    ```
    $ sudo apt install -y libasio-dev
    $ sudo apt install -y ros-$ROS_DISTRO-teleop-twist-keyboard
    ```

2. Clone the packages into your catkin workspace and compile

    (the following instructions assume your catkin workspace is at: ~/scout_ws/src)

    ```
    $ mkdir -p ~/scout_ws/src
    $ cd ~/scout_ws/src
    $ git clone https://github.com/agilexrobotics/ugv_sdk.git  
    $ git clone https://github.com/st88018/scout_ros.git
    $ cd ..
    $ catkin_make
    ```
    
3. Setup CAN-To-USB adapter

* Enable gs_usb kernel module(If you have already added this module, you do not need to add it)
    ```
    $ sudo modprobe gs_usb
    ```

* Source the workspace
   ```
   $ source ~/scout_ws/devel/setup.bash
   ```

* first time use gh034-scout-ros package
   ```
   $ rosrun scout_bringup setup_can2usb.bash
   ```
   
* if not the first time use gh034-scout-ros package (Run this command every time you turn off the power)
   ```
   $ rosrun scout_bringup bringup_can2usb.bash
   ```
   
* Testing canbus command
    ```
    # receiving data from can0
    $ candump can0
    ```

4. Launch ROS nodes

* Start the base node for scout-mini

    ```
    $ roslaunch scout_bringup scout_robot_base.launch 
    ```

    The [scout_bringup/scout_mini_robot_base.launch](scout_bringup/launch/scout_mini_robot_base.launch) has 5 parameters:

    - port_name: specifies the port used to communicate with the robot, default = "can0"
    - simulated_robot: indicates if launching with a simulation, default = "false"
    - model_xacro: specifies the target ".xacro" file for the publishing of tf frames, default = [scout_v2.xacro](scout_base/description/scout_v2.xacro)
    - odom_topic_name: sets the name of the topic which calculated odometry is published to, defaults = "odom"
    - is_scout_mini:Suitable for chassis of type scout_mini,defaults = "false"

* Start the keyboard tele-op node

    ```
    $ roslaunch scout_bringup scout_teleop_keyboard.launch
    ```

    **SAFETY PRECAUSION**: 

    The default command values of the keyboard teleop node are high, make sure you decrease the speed commands before starting to control the robot with your keyboard! Have your remote controller ready to take over the control whenever necessary. 

## Using the robot in VICON room

1. Install VRPN 
    ```
    $ sudo apt install -y ros-$ROS_DISTRO--vrpn
    $ sudo apt install -y ros-$ROS_DISTRO--vrpn-client-ros
    ```

2. Launch the VRPN sample.launch node
    ```
    $ roslaunch vrpn_client_ros sample.launch
    ```

3. Check the position is correct from the VRPN node
    ```
    $ rostopic echo /vrpn_client_node/gh034_car/pose
    ``` 

4. Check the mission file

    The [scout_base/src/utils/ugv_mission.hpp](scout_base/src/utils/ugv_mission.hpp) stores the mission waypoints of the FSM module.
    
5. Start the mission with scout_mini_vicon.launch
    
    ```
    $ roslaunch scout_base scout_mini_vicon.launch 
    ```

    The [scout_base/scout_mini_vicon.launch](scout_base/launch/scout_mini_vicon.launch) has 2 parameters:
    (Under preparing)


