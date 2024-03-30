#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qstandarditemmodel.h>

#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QMovie>
#include <QString>

#include "filemanager.h"
#include "passwordhandler.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
private:
    PasswordHandler passwordHandler;
    FileManager fileManager;

    std::unique_ptr<QStandardItemModel> standardItemModel =
        std::make_unique<QStandardItemModel>();
    std::vector<std::unique_ptr<QStandardItem>> items;

    std::unique_ptr<QMovie> movie =
        std::make_unique<QMovie>("damn");

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void displayPasswords();

public slots:
    void savePasswordButtonClicked();
    void showPasswordButtonClicked();

private:
    Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
