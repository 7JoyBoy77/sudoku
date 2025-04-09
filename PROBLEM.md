- [ ] 项目跑起来再debug 程序
- [ ] enum class 和 enum
- [ ] generator()如何保证打乱之后九宫格元素不重复
- [ ] std::less<Key> 是什么？
- [ ] std::remove()
- [ ] 单例模式
- [ ] memoryset()
- [ ] KeyMap继承vim和normal的理解
- [ ] 为什么要有指向按键映射的指针  play中的代码表示利用指针映射的按键操作
```
  // 指向按键映射对象的指针，初始化为空指针
  KeyMap *keyMap{};
```

- [ ] 行列块，存储的意义
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