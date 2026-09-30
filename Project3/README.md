# Project 3: Where Am I?

Initial pose
![alt text](project3_initial_pose.png)

After navigation
![alt text](project3_after_nav.png)

## Overview
Localize the differential-drive robot (`my_robot`) in a Gazebo office world (`myoffice.world`) using the ROS AMCL (Adaptive Monte Carlo Localization) package, then drive it to a goal with the ROS navigation stack (`move_base`).

- Map: created with `pgm_map_creator` from the Gazebo world (`my_robot/maps/map.pgm`, resolution 0.01 m/pixel, origin `[-15, -15, 0]`).
- Localization: `amcl` (`diff-corrected` odometry model, 10-500 particles).
- Planning: `move_base` with `navfn/NavfnROS` (global) and `base_local_planner/TrajectoryPlannerROS` (local).
- Parameters: `my_robot/config/*.yaml` (costmaps and local planner).

## Environment
- Ubuntu 16.04 / ROS Kinetic
- Gazebo, RViz
- ROS packages: `amcl`, `map_server`, `move_base`, `navfn`, `xacro`, `robot_state_publisher`, `joint_state_publisher`

## Build
```bash
cd Project3
catkin_make
source devel/setup.bash
```

## Run
1. Launch Gazebo, RViz and the robot (spawned at x=-4.0, y=-2.0):
   ```bash
   roslaunch my_robot world.launch
   ```
2. In a new terminal, launch the map server, AMCL and `move_base`:
   ```bash
   source devel/setup.bash
   roslaunch my_robot amcl.launch
   ```
3. In RViz, set the Fixed Frame to `map` and add the Map, LaserScan, PoseArray (`/particlecloud`), RobotModel and costmap displays.
4. Give a goal with the `2D Nav Goal` button in RViz, or move the robot manually with teleop to make the particles converge:
   ```bash
   rosrun teleop_twist_keyboard teleop_twist_keyboard.py
   ```

## Generate the map (optional)
Use `pgm_map_creator` with `myoffice.world` (see [pgm_map_creator/README.md](pgm_map_creator/README.md)). Copy the resulting `map.pgm` to `my_robot/maps/` and edit `map.yaml` as needed.

## Directory Structure
```
Project3
|-- CMakeLists.txt -> /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
|-- my_robot
|   |-- CMakeLists.txt
|   |-- config
|   |   |-- __MACOSX
|   |   |-- base_local_planner_params.yaml
|   |   |-- costmap_common_params.yaml
|   |   |-- global_costmap_params.yaml
|   |   `-- local_costmap_params.yaml
|   |-- launch
|   |   |-- amcl.launch
|   |   |-- robot_description.launch
|   |   `-- world.launch
|   |-- maps
|   |   |-- map.pgm
|   |   `-- map.yaml
|   |-- meshes
|   |   `-- hokuyo.dae
|   |-- package.xml
|   |-- urdf
|   |   |-- my_robot.gazebo
|   |   |-- my_robot.xacro
|   |   `-- mybuilding
|   |       |-- model.config
|   |       `-- model.sdf
|   `-- worlds
|       `-- myoffice.world
|-- pgm_map_creator
|   |-- CMakeLists.txt
|   |-- CODEOWNERS
|   |-- LICENSE
|   |-- README.md
|   |-- launch
|   |   `-- request_publisher.launch
|   |-- maps
|   |   `-- map.pgm
|   |-- msgs
|   |   |-- CMakeLists.txt
|   |   `-- collision_map_request.proto
|   |-- package.xml
|   |-- src
|   |   |-- collision_map_creator.cc
|   |   `-- request_publisher.cc
|   `-- world
|       |-- myoffice.world
|       `-- udacity_mtv
`-- teleop_twist_keyboard
    |-- CHANGELOG.rst
    |-- CMakeLists.txt
    |-- README.md
    |-- package.xml
    `-- teleop_twist_keyboard.py
```
