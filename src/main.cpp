#include <cstring>
#include <iostream>

#include "i18n.h"
#include "input.h"
#include "scene.h"
#include "system_env.hpp"
#include "utility.inl"

static void printHelp()
{
  std::cout << std::endl;
  std::cout << "sudoku - a little game in command line" << std::endl
            << std::endl;
  std::cout << "Usage:" << std::endl;
  std::cout << "\t sudoku [-l <progressFile>]" << std::endl
            << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "\t -l <path> \t specify path of progress file to load, optional." << std::endl
            << std::endl;
}

int main(int argc, char **argv)
{
  SetSystemEnv();

  CScene scene;

  if (argc == 1)
  {
    inputLanguage();
    int eraseGridNumber = inputDifficulty();
    scene.generate();
    // 先产生一个完整的数独,然后根据难度删除指定数量的格子
    // 难度设定相对简单
    scene.eraseRandomGrids(eraseGridNumber);
  }
  else if (argc == 3 && !strcmp(argv[1], "-l"))
  {
    // load saved game progress
    if (!scene.load(argv[2]))
    {
      message(I18n::Instance().Get(I18n::Key::LOAD_PROGRESS_FAIL));
      return 0;
    }
    inputLanguage();
  }
  else
  {
    printHelp();
    return 0;
  }

  scene.setMode(inputKeyMode());

  scene.play();

  return 0;
}
