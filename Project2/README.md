# プロジェクト2：Go Chase It!
![Gazebo上でボールを追跡するロボット](project2.png)

## 概要
Udacity Robotics Software Engineer Nanodegreeの第2プロジェクトです。Gazeboのワールドに差動二輪ロボットを配置し、搭載カメラで白いボールを検出して追いかけます。ロボットのモデルとワールドを含む`my_robot`と、ボールを追跡する処理を含む`ball_chaser`の2つのROSパッケージを使用します。

## ディレクトリ構成
```
Project2
├── ball_chaser
│   ├── CMakeLists.txt
│   ├── package.xml
│   ├── launch
│   │   └── ball_chaser.launch
│   ├── src
│   │   ├── drive_bot.cpp
│   │   └── process_image.cpp
│   └── srv
│       └── DriveToTarget.srv
├── my_robot
│   ├── CMakeLists.txt
│   ├── package.xml
│   ├── launch
│   │   ├── robot_description.launch
│   │   └── world.launch
│   ├── meshes
│   ├── urdf
│   │   ├── my_robot.gazebo
│   │   ├── my_robot.xacro
│   │   └── mybuilding
│   │       ├── model.config
│   │       └── model.sdf
│   └── worlds
│       └── myoffice.world
└── README.md
```

## 内容

### パッケージ：`my_robot/`
カメラとHokuyo LiDARを搭載した差動二輪ロボットのモデル（`urdf/my_robot.xacro`、`urdf/my_robot.gazebo`）と、ロボットを配置するGazeboワールド`myoffice.world`を含みます。

### パッケージ：`ball_chaser/`
- **`drive_bot.cpp`** — `/ball_chaser/command_robot`サービス（`DriveToTarget.srv`）を提供します。リクエストを受け取ると、指定された並進速度と角速度を設定した`geometry_msgs/Twist`メッセージを`/cmd_vel`に送信します。
- **`process_image.cpp`** — `/camera/rgb/image_raw`を購読し、画像内の白い画素からボールの位置を検出します。`/ball_chaser/command_robot`を呼び出してロボットを左右または前方へ動かし、ボールが検出されない場合は停止します。
- **`DriveToTarget.srv`** — サービス定義です。リクエストは`linear_x`と`angular_z`、レスポンスは`msg_feedback`です。

## 必要環境
- ROS (Kinetic/Melodic)
- Gazebo
- catkinワークスペース

## ビルドと実行
```bash
# Project2のパッケージをcatkinワークスペースにコピー
cp -r Project2/my_robot Project2/ball_chaser ~/catkin_ws/src/

# ビルド
cd ~/catkin_ws
catkin_make
source devel/setup.bash

# Gazeboワールドでロボットを起動
roslaunch my_robot world.launch

# 別のターミナルでボール追跡ノードを起動
roslaunch ball_chaser ball_chaser.launch
```
