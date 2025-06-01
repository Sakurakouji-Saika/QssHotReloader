# QtStyleLoaderPro - Advanced Qt Stylesheet Loader

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

[![Qt Version](https://img.shields.io/badge/Qt-%3E%3D5.12-blue.svg?logo=qt&logoColor=white&style=flat-square)](https://www.qt.io/)

[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-blue?style=flat-square)](https://github.com/yourusername/QtStyleLoaderPro)

**QtStyleLoaderPro** 是一个强大的 Qt 样式表加载工具，支持动态热重载和调试功能，专为高效 Qt 应用程序开发而设计。

## 主要特性

* 🚀 **动态样式热重载** - 开发模式下自动检测样式文件变更并实时更新UI
* 🔍 **详细调试输出** - 可启用的详细日志记录，包含样式加载状态和内容预览
* 🌐 **双模式加载** - 支持从资源系统(qrc)和文件系统加载样式表
* 🎯 **精确作用域** - 可同时支持全局样式和单个控件样式
* 📊 **性能监控** - 记录样式大小、加载时间及变化检测
* 🧩 **无缝集成** - 简洁API设计，轻松集成到现有Qt项目中

## 使用指南

### 基本使用

```cpp
// 设置全局样式
StyleLoader::loadGlobalStyle(":/styles/global.qss");

// 为特定控件设置样式
StyleLoader::loadWidgetStyle(ui->myButton, ":/styles/button.qss");
```

### 启用调试模式

```cpp
// 在应用程序初始化时调用
StyleLoader::setDebugEnabled(true);
StyleLoader::setDebugResourceRoot("/path/to/your/styles/");
```

### 调试输出示例

```
[StyleLoader DEBUG] 为窗口加载样式 [myButton: QPushButton]: :/styles/button.qss
[StyleLoader DEBUG] 成功加载文件: 大小=542 字节 | 路径=/project/styles/button.qss
[StyleLoader DEBUG] 应用样式到: myButton [QPushButton]
[StyleLoader DEBUG] 样式预览:
  QPushButton {
    background-color: #4CAF50;
    border-radius: 4px;
    color: white;
    ...
```

## 高级功能

### 热重载机制

1. 开发模式下编辑样式文件并保存
2. 文件系统监视器检测变更
3. 自动重新加载并应用新样式
4. UI实时更新无需重启应用

### 资源路径转换

自动转换qrc路径(如`:/styles/app.qss`)到文件系统路径(如`/project/styles/app.qss`)，便于开发调试。

## 集成说明

### 依赖项

* Qt 5.12 或更高版本
* C++11 兼容编译器

### 安装步骤 (QMake)

1. 将`StyleLoader.h`和`StyleLoader.cpp`添加到项目
2. 在需要使用的地方包含头文件：
   
   ```cpp
   #include "StyleLoader.h"
   ```

### 安装步骤 (CMake)

1. 将文件添加到项目：
   
   ```cmake
   add_library(StyleLoader STATIC
       StyleLoader.h
       StyleLoader.cpp
   )
   
   target_link_libraries(your_target PRIVATE StyleLoader)
   ```
2. 在代码中包含头文件：
   
   ```cpp
   #include "StyleLoader.h"
   ```

## 调试技巧

```cpp
// 启用详细日志
StyleLoader::setDebugEnabled(true);

// 设置资源根目录（开发环境）
StyleLoader::setDebugResourceRoot("/path/to/your/project/styles/");

// 加载时显示样式预览
StyleLoader::loadWidgetStyle(ui->statusBar, ":/styles/statusbar.qss");
```

## 注意事项

1. 生产环境建议禁用调试模式：
   
   ```cpp
   #ifndef QT_DEBUG
   StyleLoader::setDebugEnabled(false);
   #endif
   ```
2. 文件监视器仅在调试模式启用
3. 确保文件系统路径正确配置
4. 资源文件需添加到.qrc资源系统

## 贡献指南

欢迎提交PR和问题报告！贡献前请阅读：

1. 遵循现有代码风格
2. 添加新功能时提供单元测试
3. 更新相关文档

## 许可证

本项目采用 **MIT 许可证** - 详情请参阅 [LICENSE](https://license/) 文件。


