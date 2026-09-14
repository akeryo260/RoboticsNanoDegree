# RoboticsNanoDegree

A collection of projects from the Udacity Robotics Software Engineer Nanodegree

This repository brings together the five projects completed in Udacity's Robotics Software Engineer Nanodegree. It covers a representative set of core mobile robotics techniques, from building simulation environments in Gazebo, to ROS-based image processing and tracking, self-localization with AMCL, 3D SLAM with RTAB-Map, and a home service robot that integrates multiple ROS technologies. Each project is managed in its own directory, complete with detailed setup instructions and source code.

## Project List

### Project 1: Build My World
A first world-building project using Gazebo. Learn to create custom models and world files.

### Project 2: Go Chase It!
A robot implementation that detects and tracks a white ball using ROS nodes and services.

### Project 3: Where Am I?
Robot localization using the AMCL package. Estimate the robot's position on a known map.

### Project 4: Map My World
An implementation of 3D SLAM (Simultaneous Localization and Mapping) using RTAB-Map.

### Project 5: Home Service Robot
A home service robot that navigates to multiple goal locations and performs object pickup and drop-off.

## Areas for Improvement

### Common to all projects
- [ ] **Introduce a CI/CD pipeline**: Set up automated builds and tests using GitHub Actions
- [ ] **Dockerize**: Create Dockerfiles to resolve environment dependencies and improve reproducibility
- [ ] **Document dependencies**: Clarify the required ROS packages and versions for each project
- [ ] **Unify code style**: Standardize C++ code formatting (using clang-format)
- [ ] **Add unit tests**: Improve test coverage using Google Test

### Project 1: Build My World
- [ ] Add more complex environments (stairs, ramps, etc.)
- [ ] Optimize model physical properties (friction, inertia adjustments)
- [ ] Add dynamic objects using plugins

### Project 2: Go Chase It!
- [ ] **Optimize image processing**: More robust ball detection using the HSV color space
- [ ] **Implement PID control**: Achieve smoother robot motion
- [ ] **Support multiple ball colors**: Color selection via command-line parameters
- [ ] **Add safety features**: Obstacle detection and collision avoidance
- [ ] **Debug visualization**: Display detection markers in Rviz

### Project 3: Where Am I?
- [ ] **Optimize AMCL parameters**: Faster and more accurate localization
- [ ] **Dynamic reconfiguration**: Runtime parameter tuning
- [ ] **Multi-sensor fusion**: Improve accuracy by integrating IMU data
- [ ] **Add performance metrics**: Quantitative evaluation of localization accuracy

### Project 4: Map My World
- [ ] **Optimize loop closure**: Improve memory usage and processing speed
- [ ] **Map save/load feature**: Efficient database management
- [ ] **Increase 3D point cloud density**: Optimize sensor settings
- [ ] **Support multi-floor mapping**: Proper handling of height information

### Project 5: Home Service Robot
- [ ] **Dynamic path planning**: Replanning in response to environment changes
- [ ] **Task scheduling**: Priority-based multi-task management
- [ ] **Battery management**: Automatic return to charging station
- [ ] **Voice feedback**: Audio notification on task completion
- [ ] **Web interface**: Robot control and monitoring from a browser
- [ ] **Machine learning integration**: Advanced pickup via object recognition

### Documentation
- [ ] Detailed setup guide for each project
- [ ] Add a troubleshooting section
- [ ] Create demo videos and GIFs
- [ ] Add architecture diagrams and ROS node graphs
- [ ] Create an English version of the README

### Infrastructure
- [ ] **Continuous integration**: Automated builds and tests
- [ ] **Code coverage reports**: Visualize test coverage
- [ ] **Static analysis**: Introduce cppcheck and clang-tidy
- [ ] **Performance profiling**: Identify and optimize bottlenecks

## Setup

### Requirements
- Ubuntu 16.04 / 18.04 / 20.04
- ROS Kinetic / Melodic / Noetic
- Gazebo 7.0+
- CMake 3.0+

### Build steps
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
See each project's individual directory for its license information.