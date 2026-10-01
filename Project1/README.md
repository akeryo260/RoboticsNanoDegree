# Project 1: 自分の世界を作ろう
![画像](project1.png)

## 概要
UdacityのRobotics Software Engineer Nanodegreeの最初のプロジェクトです。Gazeboでカスタムシミュレーション環境を構築します。Gazeboのモデルデータベースにあるオブジェクトを配置したオフィス風のワールド、2つのカスタムロボットモデル、ワールドの読み込み時に実行されるワールドプラグインを作成します。

## ディレクトリ構成
```
├── Project1
│   ├── CMakeLists.txt
│   ├── model
│   │   ├── mybuilding
│   │   │   ├── model.config
│   │   │   └── model.sdf
│   │   ├── simplerobot
│   │   │   ├── model.config
│   │   │   └── model.sdf
│   │   └── simplerobot2
│   │       ├── model.config
│   │       └── model.sdf
│   ├── project1.png
│   ├── README.md
│   ├── script
│   │   └── hello.cpp
│   └── world
│       └── myoffice.world
└── README.md
```

## 内容

### ワールド: `world/myoffice.world`
地面の上に構築したオフィス環境です。本棚、カフェテーブル、車のモデルが配置されています。起動時に`hello`ワールドプラグインを読み込みます。

### モデル: `model/`
- **mybuilding** — オフィスの建物として使用するカスタムモデルです。
- **simplerobot** / **simplerobot2** — ワールドに配置する、シンプルな箱型ロボットのモデルです。

### プラグイン: `script/hello.cpp`
ワールドの読み込み時にコンソールへ挨拶メッセージを表示する、シンプルなGazeboの`WorldPlugin`です。`libhello.so`という名前の共有ライブラリとしてビルドされます。

## 必要な環境
- Gazebo 7.0+
- CMake 2.8+

## ビルドと実行
```bash
# ワールドプラグインをビルド
cd Project1
mkdir -p build && cd build
cmake ..
make

# Gazeboからプラグインを読み込めるようにする
export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$(pwd)

# ワールドを起動
cd ..
gazebo world/myoffice.world
```
