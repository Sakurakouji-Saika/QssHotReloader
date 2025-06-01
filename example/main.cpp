#include "mainwindow.h"

#include "utils/StyleLoader.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 启用详细日志
    StyleLoader::setDebugEnabled(true);

    // 设置资源根目录（开发环境）
    StyleLoader::setDebugResourceRoot("D:/Documents/GitHub/QssHotReloader/example/example/resources");


    MainWindow w;
    w.show();
    return a.exec();
}
