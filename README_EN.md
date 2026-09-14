# RoboticsNanoDegree

Collection of projects from the Udacity Robotics Software Engineer Nanodegree.

## Projects

### Project 1: Build My World
Introduction to world building using Gazebo. Covers creation of custom models and world files.

### Project 2: Go Chase It!
Implementation of a robot that detects and chases a white ball using ROS nodes and services.

### Project 3: Where Am I?
Robot localization using the AMCL package. Estimates the robot's position on a known map.

### Project 4: Map My World
3D SLAM (Simultaneous Localization and Mapping) implementation using RTAB-Map.

### Project 5: Home Service Robot
A home service robot that navigates to multiple goal locations and performs object pick-up and drop-off.

## Setup

### Requirements
- Ubuntu 16.04 / 18.04 / 20.04
- ROS Kinetic / Melodic / Noetic
- Gazebo 7.0+
- CMake 3.0+

### Build Instructions
```bash
# Set up the workspace
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
git clone https://github.com/akeryo260/RoboticsNanoDegree.git

# Install dependencies
cd ~/catkin_ws
rosdep install --from-paths src --ignore-src -r -y

# Build
catkin_make
source devel/setup.bash
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
See the individual project directories for their respective licenses.
