#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "utils/StyleLoader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 自定义 css 加载
    StyleLoader::loadWidgetStyle(this, "://css/mainwindow.css");
}

MainWindow::~MainWindow()
{
    delete ui;
}
