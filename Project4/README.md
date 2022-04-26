# Project 4: Map My World

Rtabmap-DatabaseViewer
![alt text](project4_rtabmap-databaseViewer.png)

Gazebo map
![alt text](project4_gazebomap.png)

## Directory Structure
```
Project4
|-- CMakeLists.txt -> /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
|-- README.md
|-- my_robot
|   |-- CMakeLists.txt
|   |-- config
|   |   |-- __MACOSX
|   |   |-- base_local_planner_params.yaml
|   |   |-- costmap_common_params.yaml
|   |   |-- global_costmap_params.yaml
|   |   `-- local_costmap_params.yaml
|   |-- launch
|   |   |-- localization.launch
|   |   |-- mapping.launch
|   |   |-- robot_description.launch
|   |   |-- teleop.launch
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
|-- project4_gazebomap.png
|-- project4_rtabmap-databaseViewer.png
`-- teleop_twist_keyboard
```
