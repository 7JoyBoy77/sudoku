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
  /**
   * @brief 获取I18n类的单例实例
   * 该方法遵循单例设计模式，确保整个程序中只有一个I18n类的实例存在。
   * 通过调用此方法，可以在任何需要的地方访问该单例实例。
   *
   * @return I18n& 返回I18n类单例实例的引用
   */
  static I18n &Instance();
  void SetLanguage(Language);
  std::string Get(Key) const;

private:
  I18n();

  Dict *dict_;
};
