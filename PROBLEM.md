 - [ ] 一个非常重要的问题，这个项目如何做出来，需要怎样的步骤，然后再如何抽象成代码，我只会实现单一功能。
***不要一头钻到死，自己边写边去看代码学习，不要死弄懂一个项目而浪费时间*** 回头再看

- [ ] 项目跑起来再debug 程序
- [x] enum class 和 enum
- [x] generator()如何保证打乱之后九宫格元素不重复
- [ ] std::less<Key> 是什么？
- [ ] std::remove()
- [ ] 单例模式
- [ ] memset()  抽象东西，我难以理解
- [x] I18创建english 和 chinese对象是要做什么，为什么可以这样创建 
```
english 和 chinese 是两个容器，方便传递给dictionary对象，dictionary对象是一个字典，存储了键值对，键是Key类型，值是
std::string类型。
```

- [x] KeyMap继承vim和normal的理解
`派生出键盘类，工具不同的键盘类创建对象`
- [ ] 为什么要有指向按键映射的指针  play中的代码表示利用指针映射的按键操作 ***日后再论，有点模糊***
```
  // 指向按键映射对象的指针，初始化为空指针
  KeyMap *keyMap{};
```

- [x] 行列块，存储的意义
```
  // 列块数组，包含 9 个 CBlock 类型的对象，用于管理列相关的逻辑
  CBlock _column_block[9];
  // 行块数组，包含 9 个 CBlock 类型的对象，用于管理行相关的逻辑
  CBlock _row_block[9];
  // 3x3 宫块的二维数组，用于管理数独中 3x3 区域的相关逻辑
  CBlock _xy_block[3][3];
  // 数独地图数组，存储数独每个格子的值，共 81 个元素
  point_value_t _map[81];
```
- [ ] C++enum class 和 enum, namespace
- [ ] 模块化设计，命令模式，单例模式
- [ ] command.h 命令模式做了些什么
- [ ] 在 C++ 中，enum class （强类型枚举）默认的底层类型是 int，但具体的大小和符号取决于编译器和平台。通过指定 : uint32_t，可以明确指定枚举的底层类型为 32 位无符号整数。这样可以避免不同平台上 int 类型大小不一致的问题，确保枚举的底层存储在所有平台上都是一致的。
- [ ] color 和 modifier 的组合使用
- [x] 场景初始化时，界面如何输出出来
- [ ]  CScene中 keyMap *keyMap scene和keymap的关系，两者耦合
- [ ] memset初始化
- [x] I18n的别名定义在类中，但实例创建后是全局的,为什么要这么做，没有理解
***如果后续需要修改 std::map<Key, std::string> 类型，比如将 std::map 替换为 std::unordered_map，就需要在所有使用该类型的地方进行修改，容易遗漏且工作量较大。***
```
  using Dict = std::map<Key, std::string>;
```
- [ ] 为什么别名要定义在i18n.h中，而不是i18n.cpp中，只有i18n.cpp中才会用到别名
__如果后续有其他源文件需要使用 std::map<Key, std::string> 这种类型，那么将 Dict 定义在 i18n.h 中，其他源文件只需包含 i18n.h 头文件，就可以直接使用 Dict 别名，而不需要重复定义类型别名。这样可以避免代码重复，提高代码的复用性。__
- [ ] std::get()的类模板
- [ ] 填充数字的逻辑还有些混淆,理解填充空格的逻辑
- [ ] algorithm库中的remove()函数的使用
- [ ] 类型不安全意味着编译器无法在编译阶段有效地检查和阻止不恰当的类型使用
- [ ] 使用if_else语句控制play逻辑，处理play逻辑的方式
- [ ] command类的设计是怎样的
- [ ] std::move
```
CCommand oCommand(this);
 _vCommand.push_back(std::move(oCommand));
```
- [ ] Vscode + Cmake 的学习
- [ ] Doxygen注释规范
- [ ] 为什么要重载setValue()
- [ ] 学习如何从头开始一个项目
