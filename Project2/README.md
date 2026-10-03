# プロジェクト2：Go Chase It!
![プロジェクト2の実行画面](project2.png)

## 概要
Udacity Robotics Software Engineer Nanodegreeの第2プロジェクトです。Gazebo上の差動二輪ロボットが搭載カメラで白いボールを検出し、その方向へ移動します。ロボットのモデルとワールドを定義する`my_robot`と、ボール追跡処理を行う`ball_chaser`の2つのROSパッケージで構成されています。

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
カメラとHokuyo LiDARを搭載した差動二輪ロボットのモデル（`urdf/my_robot.xacro`、`urdf/my_robot.gazebo`）と、ロボットを起動するGazeboワールド`myoffice.world`が含まれています。

### パッケージ：`ball_chaser/`
- **`drive_bot.cpp`** — `/ball_chaser/command_robot`サービス（`DriveToTarget.srv`）を提供します。要求された並進・回転速度を含む`geometry_msgs/Twist`メッセージを`/cmd_vel`トピックに配信します。
- **`process_image.cpp`** — `/camera/rgb/image_raw`を購読し、画像内の白い画素からボールの位置を検出します。検出位置に応じて`/ball_chaser/command_robot`を呼び出し、ロボットを左右または前進させます。ボールが検出されない場合は停止します。
- **`DriveToTarget.srv`** — サービス定義です。要求は`linear_x`と`angular_z`、応答は`msg_feedback`です。

## 必要環境
- ROS（Kinetic/Melodic）
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
