#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Создаем модель
    model = new ParameterModel(this);

    // 2. Привязываем её к таблице
    ui->tableView->setModel(model);

    // 3. Добавляем тестовую строку
    model->addItem({1, "Температура", 25.5, "°C"});
}

MainWindow::~MainWindow()
{
    delete ui;
}
