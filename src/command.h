#ifndef _SUDOKU_COMMAND_H_
#define _SUDOKU_COMMAND_H_

#include <memory>
#include "common.h"
// 类的前向声明
class CScene;

/**
 * @class CCommand
 * @brief 表示一个数独游戏中的命令，用于执行和撤销操作。
 *
 * 该类封装了数独游戏中的操作，如在特定位置设置值，并提供了执行和撤销这些操作的方法。
 */
class CCommand
{
public:
    /**
     * @brief 构造函数，初始化命令对象。
     * @param pOwner 指向拥有此命令的场景对象的指针。
     */
    CCommand(CScene *pOwner);

    /**
     * @brief 构造函数，初始化命令对象，同时指定操作的位置和值。
     * @param pOwner 指向拥有此命令的场景对象的指针。
     * @param point 操作的位置。
     * @param preValue 操作前的旧值。
     * @param curValue 操作后的新值。
     */
    CCommand(CScene *pOwner, const point_t &point, int preValue, int curValue);

    /**
     * @brief 拷贝构造函数，复制一个命令对象。
     * @param other 要复制的命令对象。
     */
    CCommand(const CCommand &);

    /**
     * @brief 析构函数，释放命令对象占用的资源。
     */
    ~CCommand();

    /**
     * @brief 执行命令，设置指定位置的值。
     * @param nInputValue 要设置的新值。
     * @return 如果执行成功返回 true，否则返回 false。
     */
    bool execute(int nInputValue);

    /**
     * @brief 撤销命令，将指定位置的值恢复为操作前的值。
     */
    void undo();

    /**
     * @brief 获取操作的位置。
     * @return 操作的位置。
     */
    point_t getPoint() { return _stPoint; }

    /**
     * @brief 获取操作前的旧值。
     * @return 操作前的旧值。
     */
    int getPreValue() { return _nPreValue; }

    /**
     * @brief 获取操作后的新值。
     * @return 操作后的新值。
     */
    int getCurValue() { return _nCurValue; }

    /**
     * @brief 设置操作的位置。
     * @param point 要设置的新位置。
     */
    void setPoint(const point_t &point) { _stPoint = point; }

    /**
     * @brief 设置操作前的旧值。
     * @param preValue 要设置的旧值。
     */
    void setPreValue(int preValue) { _nPreValue = preValue; }

    /**
     * @brief 设置操作后的新值。
     * @param curValue 要设置的新值。
     */
    void setCurValue(int curValue) { _nCurValue = curValue; }

private:
    // 指向拥有此命令的场景对象的指针
    CScene *_pOwner;
    // 操作的位置
    point_t _stPoint;
    // 操作前的旧值
    int _nPreValue;
    // 操作后的新值，实际上该成员从未被使用
    int _nCurValue;
};
#endif