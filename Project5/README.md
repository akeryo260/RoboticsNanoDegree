# Project 5: Home Service Robot

Gazebo上のTurtleBotが、指定されたピックアップ地点と受け渡し地点へ順番に移動するホームサービスロボットのシミュレーションです。RViz上では、仮想オブジェクトをマーカーとして表示します。

## ビルド

ROSとcatkinがインストールされている環境で、以下のコマンドを実行します。

```bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
git clone https://github.com/akeryo260/RoboticsNanoDegree.git
cp -R RoboticsNanoDegree/Project5/. .

# TurtleBotとSLAM関連のパッケージを取得
git clone https://github.com/ros-perception/slam_gmapping
git clone https://github.com/turtlebot/turtlebot
git clone https://github.com/turtlebot/turtlebot_interactions
git clone https://github.com/turtlebot/turtlebot_simulator

cd ~/catkin_ws
rosdep install --from-paths src --ignore-src -r -y
catkin_make
source devel/setup.bash
```

## 実行

各スクリプトはcatkinワークスペースのルートから実行します。新しいターミナルを開いた場合は、実行前に `source ~/catkin_ws/devel/setup.bash` を実行してください。

### SLAMのテスト

Gazeboで環境を地図にするSLAMを試します。キーボードでロボットを操作し、RVizで地図を確認できます。

```bash
cd ~/catkin_ws
./src/scripts/test_slam.sh
```

使用する主なパッケージ:

- `turtlebot_gazebo`: Gazebo上にロボットと環境を起動し、SLAMを実行
- `turtlebot_rviz_launchers`: RVizで地図を表示
- `turtlebot_teleop`: キーボードでロボットを操作

### 自己位置推定とナビゲーションのテスト

保存済みの地図を使い、ROS Navigationスタックでロボットが目標地点へ移動できることを確認します。

```bash
cd ~/catkin_ws
./src/scripts/test_navigation.sh
```

使用する主なパッケージ:

- `turtlebot_gazebo`: Gazebo上にロボットと環境を起動し、自己位置を推定
- `turtlebot_rviz_launchers`: RVizで地図とナビゲーション状態を表示

### 複数の目標地点への移動

`pick_objects`ノードからROS Navigationスタックへ、ピックアップ地点と受け渡し地点を順番に送信します。

```bash
cd ~/catkin_ws
./src/scripts/pick_objects.sh
```

使用する主なパッケージ:

- `turtlebot_gazebo`: Gazebo上にロボットと環境を起動し、自己位置を推定
- `turtlebot_rviz_launchers`: RVizで地図とナビゲーション状態を表示
- `pick_objects`: ピックアップ地点と受け渡し地点をナビゲーションスタックに送信

### 仮想オブジェクトの表示

`add_markers`ノードがRViz上にピックアップ地点と受け渡し地点をマーカーで表示します。

```bash
cd ~/catkin_ws
./src/scripts/add_markers.sh
```

使用する主なパッケージ:

- `turtlebot_gazebo`: Gazebo上にロボットと環境を起動し、自己位置を推定
- `add_markers`: RViz上にピックアップ地点と受け渡し地点を表示

### ホームサービスロボットのシミュレーション

ロボットが仮想オブジェクトをピックアップ地点まで取りに行き、受け渡し地点へ運ぶ一連の動作を実行します。

```bash
cd ~/catkin_ws
./src/scripts/home_service.sh
```

使用する主なパッケージ:

- `turtlebot_gazebo`: Gazebo上にロボットと環境を起動し、自己位置を推定
- `pick_objects`: ピックアップ地点と受け渡し地点への移動を指示
- `add_markers`: 仮想オブジェクトをRViz上に表示

ピックアップ地点への移動:

![ピックアップ地点へ移動するロボット](travel_to_pickup_zone.png)

受け渡し地点:

![受け渡し地点の仮想オブジェクト](drop_off_virtual_object.png)
