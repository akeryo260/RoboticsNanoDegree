#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:="$(pwd)/src/map/myoffice.world" " &
sleep 5
xterm  -e  " roslaunch turtlebot_gazebo amcl_demo.launch map_file:="$(pwd)/src/map/myMap.yaml" " &
sleep 5
xterm  -e  " rosrun rviz rviz -d "$(pwd)/src/home_service.rviz" " &
sleep 5
xterm  -e  " rosrun add_markers add_markers_timer " &
