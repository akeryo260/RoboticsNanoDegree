# Robotics Nanodegree

このリポジトリは、Udacity Robotics Software Engineerナノ学位プログラムのプロジェクトコレクションです。ロボティクスの基礎から高度な自律ナビゲーションまで、5つのプロジェクトを通じて学習した内容をまとめています。

## 目次

- [概要](#概要)
- [プロジェクト一覧](#プロジェクト一覧)
  - [Project 1: Build My World](#project-1-build-my-world)
  - [Project 2: Go Chase It!](#project-2-go-chase-it)
  - [Project 3: Where Am I?](#project-3-where-am-i)
  - [Project 4: Map My World](#project-4-map-my-world)
  - [Project 5: Home Service Robot](#project-5-home-service-robot)
- [必要な環境](#必要な環境)
- [技術スタック](#技術スタック)
- [リポジトリ構成](#リポジトリ構成)
- [使用方法](#使用方法)

## 概要

このリポジトリには、ROSとGazeboを使用したロボティクスプロジェクトが含まれています。各プロジェクトは、実際のロボティクス開発で必要とされる重要なスキルと技術をカバーしています：

- **シミュレーション環境の構築**: Gazeboでのワールドとロボットモデルの作成
- **ロボット制御**: センサーデータを使用したリアルタイム制御
- **ローカライゼーション**: AMCLを使用したロボットの自己位置推定
- **マッピング**: SLAM技術を使用した環境マッピング
- **自律ナビゲーション**: ナビゲーションスタックを使用したゴール指向の移動
- **統合システム**: 複数のROSノードを統合したホームサービスロボット

## プロジェクト一覧

### Project 1: Build My World

![Project 1](Project1/project1.png)

**学習内容**: Gazeboシミュレーション環境の構築

- Gazebo Building Editorを使用したカスタムワールドの作成
- ロボットモデルの設計とSDFファイルの記述
- C++プラグインの基礎
- シミュレーション環境の構成

**主要ファイル**:
- `world/myoffice.world`: カスタムオフィス環境
- `model/`: ロボットと建物のモデル定義
- `script/hello.cpp`: 基本的なGazeboプラグイン

[詳細はこちら →](Project1/README.md)

---

### Project 2: Go Chase It!

![Project 2](Project2/project2.png)

**学習内容**: ROSノードの実装とロボット制御

- ROSノードの作成とサービス通信
- カメラセンサーデータの処理
- 画像処理によるボール検出
- ロボットの速度制御とナビゲーション
- URDF/Xacroを使用したロボットモデル設計

**主要機能**:
- `drive_bot.cpp`: ロボットの速度を制御するサービスサーバー
- `process_image.cpp`: カメラ画像から白いボールを検出し、追跡する

[詳細はこちら →](Project2/README.md)

---

### Project 3: Where Am I?

| 初期姿勢 | ナビゲーション後 |
|---------|----------------|
| ![Initial Pose](Project3/project3_initial_pose.png) | ![After Navigation](Project3/project3_after_nav.png) |

**学習内容**: 適応型モンテカルロローカライゼーション（AMCL）

- AMCLアルゴリズムを使用したロボットのローカライゼーション
- ROSナビゲーションスタックの設定
- コストマップの設定とパラメータチューニング
- 既存のマップを使用した自己位置推定
- 2D Nav Goalを使用したゴール指向ナビゲーション

**主要コンポーネント**:
- AMCL (Adaptive Monte Carlo Localization)
- ROSナビゲーションスタック
- プランナーとコストマップの設定

[詳細はこちら →](Project3/README.md)

---

### Project 4: Map My World

| RTABマップデータベース | Gazeboマップ |
|--------------------|-------------|
| ![RTAB-Map Database](Project4/project4_rtabmap-databaseViewer.png) | ![Gazebo Map](Project4/project4_gazebomap.png) |

**学習内容**: RTAB-Mapを使用したSLAM

- RTAB-Map (Real-Time Appearance-Based Mapping) の実装
- RGB-Dカメラを使用した3Dマッピング
- ループクロージャーによるマップの最適化
- リアルタイムでの環境マッピング
- データベースビューアを使用したマップの解析

**主要技術**:
- RTAB-Map: 外観ベースのSLAM
- RGB-Dカメラセンサーの統合
- ループクロージャー検出

[詳細はこちら →](Project4/README.md)

---

### Project 5: Home Service Robot

| ピックアップゾーンへ移動 | 仮想オブジェクトの配達 |
|---------------------|---------------------|
| ![Travel to Pickup](Project5/travel_to_pickup_zone.png) | ![Drop Off Object](Project5/drop_off_virtual_object.png) |

**学習内容**: 完全自律型ホームサービスロボットの実装

- 複数のROSノードの統合
- パッケージ間の通信とメッセージング
- TurtleBotシミュレーションの使用
- RVizでの仮想オブジェクトのビジュアライゼーション
- 複数ゴールへの自律ナビゲーション

**シナリオ**:
1. ロボットが初期位置から開始
2. ピックアップゾーンへ自律移動
3. 仮想オブジェクトを「ピックアップ」（RVizでマーカー消去）
4. ドロップオフゾーンへ移動
5. 仮想オブジェクトを「配達」（RVizでマーカー表示）

**カスタムパッケージ**:
- `pick_objects`: ナビゲーションスタックへゴール送信
- `add_markers`: RVizでのマーカー表示/非表示

[詳細はこちら →](Project5/README.md)

---

## 必要な環境

### ソフトウェア要件

- **Ubuntu 16.04** (推奨) または Ubuntu 18.04
- **ROS Kinetic** (Ubuntu 16.04) または ROS Melodic (Ubuntu 18.04)
- **Gazebo 7.x** (ROS Kineticに含まれる) または Gazebo 9.x (ROS Melodicに含まれる)
- **C++ コンパイラ**: g++ 5.4以上
- **CMake**: 3.5以上
- **Git**: バージョン管理

### ROSパッケージの依存関係

プロジェクトによって異なりますが、主な依存関係は以下の通りです：

```bash
# 基本パッケージ
sudo apt-get install ros-kinetic-desktop-full  # または ros-melodic-desktop-full

# ナビゲーション関連
sudo apt-get install ros-kinetic-navigation
sudo apt-get install ros-kinetic-map-server
sudo apt-get install ros-kinetic-move-base
sudo apt-get install ros-kinetic-amcl

# SLAM関連
sudo apt-get install ros-kinetic-slam-gmapping
sudo apt-get install ros-kinetic-rtabmap-ros

# TurtleBot関連（Project 5）
sudo apt-get install ros-kinetic-turtlebot
sudo apt-get install ros-kinetic-turtlebot-interactions
sudo apt-get install ros-kinetic-turtlebot-simulator

# その他のツール
sudo apt-get install ros-kinetic-teleop-twist-keyboard
```

## 技術スタック

| カテゴリ | 技術/ツール |
|---------|-----------|
| **ロボットミドルウェア** | ROS (Robot Operating System) |
| **シミュレーション** | Gazebo |
| **プログラミング言語** | C++, Python |
| **3Dモデリング** | SDF (Simulation Description Format), URDF/Xacro |
| **ビジュアライゼーション** | RViz |
| **ローカライゼーション** | AMCL (Adaptive Monte Carlo Localization) |
| **マッピング** | gmapping, RTAB-Map |
| **ナビゲーション** | ROS Navigation Stack (move_base, DWA planner) |
| **画像処理** | OpenCV, image_transport |
| **ビルドシステム** | CMake, catkin |

## リポジトリ構成

```
RoboticsNanoDegree/
├── Project1/              # Gazeboワールドとモデルの構築
│   ├── model/            # ロボットと建物のモデル
│   ├── world/            # Gazeboワールドファイル
│   └── script/           # C++プラグイン
│
├── Project2/              # ロボット制御とボール追跡
│   ├── my_robot/         # ロボット定義とワールド
│   └── ball_chaser/      # ボール検出と追跡ノード
│
├── Project3/              # AMCLローカライゼーション
│   ├── my_robot/         # ロボット、マップ、設定
│   ├── pgm_map_creator/  # マップ作成ツール
│   └── teleop_twist_keyboard/  # キーボード操作
│
├── Project4/              # RTAB-Map SLAM
│   ├── my_robot/         # ロボット定義とマッピング設定
│   └── teleop_twist_keyboard/  # キーボード操作
│
└── Project5/              # ホームサービスロボット
    ├── add_markers/      # RVizマーカー管理
    ├── pick_objects/     # ナビゲーションゴール管理
    ├── map/             # 環境マップ
    └── scripts/         # 起動スクリプト
```

## 使用方法

### 基本的なワークフロー

各プロジェクトは独立して実行できます。一般的な手順は以下の通りです：

1. **ワークスペースの作成とセットアップ**
```bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
# プロジェクトファイルをコピー
```

2. **依存関係のインストール**
```bash
cd ~/catkin_ws
rosdep install --from-paths src --ignore-src -r -y
```

3. **ビルド**
```bash
cd ~/catkin_ws
catkin_make
source devel/setup.bash
```

4. **実行**
```bash
# 各プロジェクトのREADMEに記載された起動コマンドを実行
```

### プロジェクト固有の手順

各プロジェクトには詳細な手順が記載された個別のREADMEファイルがあります：

- [Project 1の手順](Project1/README.md)
- [Project 2の手順](Project2/README.md)
- [Project 3の手順](Project3/README.md)
- [Project 4の手順](Project4/README.md)
- [Project 5の手順](Project5/README.md) - 最も詳細な手順とスクリプトを含む

## 学習ポイント

このナノ学位プログラムを通じて習得できる主なスキル：

1. **シミュレーション**: Gazeboでのリアルな環境とロボットのモデリング
2. **ROS基礎**: ノード、トピック、サービス、パラメータの理解と実装
3. **センサー統合**: カメラ、LiDAR、RGB-Dカメラの使用
4. **ローカライゼーション**: 粒子フィルタを使用した確率的位置推定
5. **マッピング**: SLAMアルゴリズムによる未知環境の地図作成
6. **経路計画**: グローバルプランナーとローカルプランナーの使用
7. **システム統合**: 複数のコンポーネントを統合した完全なロボットシステム

## ライセンス

このプロジェクトは教育目的で作成されました。

## 謝辞

- Udacity Robotics Software Engineer Nanodegree Program
- ROSとGazeboのコミュニティ
- 全てのオープンソースコントリビューター