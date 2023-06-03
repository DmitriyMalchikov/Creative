#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // Проверьте, соответствуют ли введенные логин и пароль требованиям вашего проекта
    if (username == "Dmitriy" && password == "Malchikov") {
    // Если логин и пароль прошли проверку, откройте главное окно
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->hide();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Неправильный логин/пароль");
    }
}

