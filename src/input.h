#ifndef _SUDOKU_INPUT_H_
#define _SUDOKU_INPUT_H_

#include "common.h"
/**
 * @brief 输入难度,返回需要删除的格子数量
 * @return int
 */
int inputDifficulty();

/**
 * @brief 输入键盘模式,返回键盘模式
 * @return KeyMode对象
 */
KeyMode inputKeyMode();

/**
 * @brief 输入语言,返回语言
 * @return void
 */
void inputLanguage();

#endif
