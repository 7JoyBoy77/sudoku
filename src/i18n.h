#pragma once

#include <cstdint>
#include <map>
#include <string>

enum class Language : uint32_t
{
  ENGLISH,
  CHINESE,
  MAX,
};

class I18n
{
public:
  enum class Key
  {
    ASK_KEY_MAP,
    INPUT_ERROR,
    LOAD_PROGRESS_FAIL,
    ASK_QUIT,
    ASK_SAVE,
    ASK_SAVE_PATH,
    FILE_EXIST_ERROR,
    CONTINUE,
    UNDO_ERROR,
    CONGRATULATION,
    NOT_COMPLETED,
    ASK_DIFFICULTY,
  };
  // 此处map容器的作用是什么，定义了english和chinese两个map容器
  using Dict = std::map<Key, std::string>;
  // 此处单例模式是什么
  // 此处应该就是全局访问点
  static I18n &Instance();
  void SetLanguage(Language);
  std::string Get(Key) const;

private:
  I18n();

  Dict *dict_;
};
