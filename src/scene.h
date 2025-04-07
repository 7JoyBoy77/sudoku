#ifndef _SUDOKU_SCENE_H_
#define _SUDOKU_SCENE_H_

#include <iostream>
#include <vector>
#include "common.h"
#include "block.h"
#include "command.h"

// 数独场景类
class CScene
{
public:
  CScene(int index = 3);
  virtual ~CScene();

  void generate();
  void show() const;

  bool setCurValue(const int nCurValue, int &nLastValue);
  bool setPointValue(const point_t &, const int);
  point_t getCurPoint();

  void eraseRandomGrids(const int count);
  bool isComplete();

  void play();
  bool save(const char *filename);
  bool load(const char *filename);

  void setMode(KeyMode mode);

private:
  void init(); // 将每个格子的指针放到block里面
  void setValue(const int);
  void setValue(const point_t &, const int);
  void printUnderline(int line_no = -1) const;

private:
  // 指向按键映射对象的指针，初始化为空指针
  KeyMap *keyMap{};
  // 最大列数
  int _max_column;
  // 当前点的坐标，使用 point_t 类型表示
  point_t _cur_point;
  // 列块数组，包含 9 个 CBlock 类型的对象，用于管理列相关的逻辑
  CBlock _column_block[9];
  // 行块数组，包含 9 个 CBlock 类型的对象，用于管理行相关的逻辑
  CBlock _row_block[9];
  // 3x3 宫块的二维数组，用于管理数独中 3x3 区域的相关逻辑
  CBlock _xy_block[3][3];
  // 数独地图数组，存储数独每个格子的值，共 81 个元素
  point_value_t _map[81];

  // 命令向量，用于存储一系列的 CCommand 类型的命令，可用于实现撤销、重做等功能
  std::vector<CCommand> _vCommand;
};

#endif