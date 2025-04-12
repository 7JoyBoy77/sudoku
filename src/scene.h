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
  /**
   * @brief 构造函数，用于创建 CScene 对象。
   * @param index 一个可选参数，默认值为 3，具体用途取决于类的实现逻辑。
   */
  CScene(int index = 3);

  /**
   * @brief 析构函数，由于是虚析构函数，确保在删除指向 CScene 对象的基类指针时能正确释放资源。
   */
  virtual ~CScene();

  /**
   * @brief 生成数独谜题的方法。
   * 该方法负责生成一个新的数独谜题，具体生成逻辑取决于类的实现。
   */
  void generate();

  /**
   * @brief 显示数独场景的方法。
   * 该方法以只读方式显示当前数独场景的状态，不会修改对象的任何成员变量。
   */
  void show() const;

  /**
   * @brief 设置当前点的值。
   * @param nCurValue 要设置的值。
   * @param nLastValue 存储上一个值的变量，用于记录上一个值。
   * @return 如果设置成功返回 true，否则返回 false。
   * @note 为什么要这样设置值，然后保存前一个值？
   */
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
  /**
   * @brief 初始化函数，用于初始化 CScene 对象的成员变量。
   * 将每个格子的指针放到block里面
   * @return void 无返回值。
   */
  void init();

  /**
   * @brief 设置值的方法，通过整数参数设置值。
   * 该方法具体如何设置值取决于类的实现，可能会修改数独地图中某个默认位置的值。
   * @param value 要设置的值。
   */
  void setValue(const int);

  void setValue(const point_t &, const int);

  /**
   * @brief 打印下划线的方法，用于在显示数独场景时可能的格式化输出。
   * 该方法以只读方式执行，不会修改对象的任何成员变量。
   * @param line_no 可选参数，指定要打印下划线的行号，默认值为 -1。
   * 当 line_no 为 -1 时，可能会有默认的打印逻辑；否则，根据指定行号打印下划线。
   */
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