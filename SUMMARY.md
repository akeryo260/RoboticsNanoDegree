# RoboticsNanoDegree リポジトリまとめ

Udacity Robotics Software Engineer Nanodegree のプロジェクト集です。  
ROS（Robot Operating System）と Gazebo シミュレーターを活用した、ロボティクスの基礎から応用までを学ぶ5つのプロジェクトで構成されています。

---

## 目次

1. [Project 1: Build My World](#project-1-build-my-world)
2. [Project 2: Go Chase It!](#project-2-go-chase-it)
3. [Project 3: Where Am I?](#project-3-where-am-i)
4. [Project 4: Map My World](#project-4-map-my-world)
5. [Project 5: Home Service Robot](#project-5-home-service-robot)
6. [共通セットアップ手順](#共通セットアップ手順)
7. [使用技術一覧](#使用技術一覧)

---

## Project 1: Build My World

**テーマ:** Gazebo を使用した仮想世界とロボットモデルの構築

### 概要

Gazebo シミュレーター上でカスタムの建物モデルとロボットモデルを作成し、仮想世界を構築する入門プロジェクトです。

### 主な内容

| 要素 | 説明 |
|------|------|
| `world/myoffice.world` | カスタムオフィス環境のワールドファイル |
| `model/mybuilding` | 建物の SDF モデル |
| `model/simplerobot` / `simplerobot2` | シンプルなロボットモデル |
| `script/hello.cpp` | Gazebo プラグインのサンプルスクリプト |

### 学習ポイント

- Gazebo Building Editor を使った環境構築
- SDF（Simulation Description Format）によるモデル定義
- Gazebo プラグインの基礎

---

## Project 2: Go Chase It!

**テーマ:** 白いボールを検出して追跡する ROS ロボットの実装

### 概要

カメラ画像から白いボールを検出し、そのボールに向かって自律的に移動するロボットを ROS ノードとサービスを使って実装します。

### ROS パッケージ構成

#### `my_robot` パッケージ
- URDF/Xacro でのロボット定義（カメラ・LiDAR センサー搭載）
- Gazebo シミュレーション環境

#### `ball_chaser` パッケージ

| ノード / ファイル | 役割 |
|------------------|------|
| `drive_bot.cpp` | ロボットの車輪速度を制御するサービスサーバー |
| `process_image.cpp` | カメラ画像を処理してボールを検出し、移動方向を決定するクライアント |
| `DriveToTarget.srv` | 速度コマンドを受け渡すカスタムサービス定義 |

### 学習ポイント

- ROS ノードの作成と通信（Publisher / Subscriber / Service）
- カメラ画像処理による物体検出
- URDF/Xacro によるロボットモデル定義

---

## Project 3: Where Am I?

**テーマ:** AMCL を使用したロボットの自己位置推定（ローカライゼーション）

### 概要

既知のマップ上で AMCL（Adaptive Monte Carlo Localization）パッケージを使用し、ロボットが自身の位置を推定しながらナビゲーションを行います。

### パッケージ構成

| パッケージ | 説明 |
|------------|------|
| `my_robot` | ロボット定義・AMCLローンチファイル・マップファイル・ナビゲーション設定 |
| `pgm_map_creator` | Gazebo ワールドから PGM マップを生成するツール |
| `teleop_twist_keyboard` | キーボードによる手動操作パッケージ |

### 主要ファイル

- `my_robot/launch/amcl.launch` — AMCL・マップサーバー・ナビゲーションスタック起動
- `my_robot/maps/map.pgm` / `map.yaml` — 事前に生成した占有格子マップ
- `my_robot/config/*.yaml` — コストマップ・局所計画のパラメーター設定

### 学習ポイント

- AMCL を使ったモンテカルロローカライゼーション
- ROS Navigation Stack の設定と使用
- pgm_map_creator によるマップ生成

---

## Project 4: Map My World

**テーマ:** RTAB-Map を使用した 3D SLAM の実装

### 概要

RTAB-Map（Real-Time Appearance-Based Mapping）を使い、ロボットが未知の環境を探索しながら 3D マップを構築する SLAM（Simultaneous Localization and Mapping）を実装します。

### パッケージ構成

| パッケージ | 説明 |
|------------|------|
| `my_robot` | RGB-D カメラ・LiDAR 搭載のロボット、RTAB-Map ローンチファイル |
| `teleop_twist_keyboard` | キーボードによる手動操作 |

### 主要ローンチファイル

| ファイル | 役割 |
|----------|------|
| `mapping.launch` | RTAB-Map によるマッピングモードの起動 |
| `localization.launch` | 生成済みマップを使ったローカライゼーション |
| `teleop.launch` | テレオペレーション（遠隔操作）の起動 |

### 学習ポイント

- RTAB-Map を使った 3D SLAM
- ループクロージャによる累積誤差の補正
- RTAB-Map Database Viewer によるマップの確認・評価

---

## Project 5: Home Service Robot

**テーマ:** 自律的にオブジェクトをピックアップ・配達するホームサービスロボット

### 概要

Turtlebot をベースに、SLAM・ローカライゼーション・ナビゲーション・Rviz マーカーを組み合わせた、複数の目標地点へ自律移動し仮想オブジェクトを運搬するロボットを実装します。

### パッケージ構成

| パッケージ | 説明 |
|------------|------|
| `pick_objects` | ピックアップ・ドロップオフ地点へのナビゲーション命令を送るノード |
| `add_markers` | Rviz 上でピックアップ・ドロップオフゾーンを表示するマーカーノード |
| `map/` | 事前生成マップ（PGM + YAML） |
| `scripts/` | 各テストシナリオを起動するシェルスクリプト群 |

### 実行シナリオ

| スクリプト | 内容 |
|------------|------|
| `test_slam.sh` | SLAM テスト（Gmapping + テレオペ） |
| `test_navigation.sh` | ナビゲーションテスト（AMCL + ゴール設定） |
| `pick_objects.sh` | 複数ゴールへの自律移動テスト |
| `add_markers.sh` | 仮想オブジェクトマーカーの表示テスト |
| `home_service.sh` | ホームサービスロボットのフルデモ |

### 依存パッケージ（別途クローン必要）

- `slam_gmapping` — Gmapping SLAM
- `turtlebot` — Turtlebot ベースパッケージ
- `turtlebot_interactions` — Rviz ランチャー
- `turtlebot_simulator` — Gazebo シミュレーター

### 学習ポイント

- SLAM・ローカライゼーション・ナビゲーションの統合
- ROS Navigation Stack と Action ライブラリの使用
- Rviz マーカーによる仮想オブジェクト可視化

---

## 共通セットアップ手順

### 必要な環境

| ソフトウェア | バージョン |
|-------------|------------|
| OS | Ubuntu 16.04 / 18.04 / 20.04 |
| ROS | Kinetic / Melodic / Noetic |
| Gazebo | 7.0 以上 |
| CMake | 3.0 以上 |

### ビルド手順

```bash
# ワークスペースの作成
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src

# リポジトリのクローン
git clone https://github.com/akeryo260/RoboticsNanoDegree.git

# 依存関係のインストール
cd ~/catkin_ws
rosdep install --from-paths src --ignore-src -r -y

# ビルド
catkin_make
source devel/setup.bash
```

### Project 5 の追加セットアップ

```bash
cd ~/catkin_ws/src
cp -Rf RoboticsNanoDegree/Project5/* .
git clone https://github.com/ros-perception/slam_gmapping
git clone https://github.com/turtlebot/turtlebot
git clone https://github.com/turtlebot/turtlebot_interactions
git clone https://github.com/turtlebot/turtlebot_simulator
cd ~/catkin_ws
catkin_make
source devel/setup.bash
rosdep -i install gmapping
rosdep -i install turtlebot_teleop
rosdep -i install turtlebot_rviz_launchers
rosdep -i install turtlebot_gazebo
```

---

## 使用技術一覧

| 技術 / ツール | 用途 |
|--------------|------|
| **ROS (Robot Operating System)** | ロボットソフトウェアフレームワーク全般 |
| **Gazebo** | 物理シミュレーション・ワールド構築 |
| **URDF / Xacro** | ロボットモデル定義 |
| **SDF** | Gazebo モデル・ワールド定義 |
| **AMCL** | 適応型モンテカルロローカライゼーション |
| **RTAB-Map** | RGB-D ベース 3D SLAM |
| **Gmapping** | レーザースキャンベース 2D SLAM |
| **ROS Navigation Stack** | 自律ナビゲーション |
| **Turtlebot** | 差動二輪ロボットプラットフォーム |
| **Rviz** | ROS 可視化ツール |
| **C++** | ROSノード・プラグインの実装言語 |
| **Python** | テレオペレーションスクリプト |
| **CMake / catkin** | ROS プロジェクトのビルドシステム |

---

## プロジェクト学習の流れ

```
Project 1          Project 2          Project 3          Project 4          Project 5
Gazebo 環境  →  ROS ノード通信  →  ローカライゼーション  →  3D SLAM  →  統合デモ
  構築          センサー処理         (AMCL)            (RTAB-Map)     ホームサービス
```

各プロジェクトは前のプロジェクトで学んだ知識を積み重ねる構成になっており、  
最終的に Project 5 で全技術を統合したホームサービスロボットを実現します。
