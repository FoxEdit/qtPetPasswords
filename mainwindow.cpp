#include "mainwindow.h"

#include <QDebug>
#include <QLabel>
#include <QStandardItemModel>
#include <sstream>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->animeGifQLabel->setMovie(movie.get());
    movie->start();

    ui->passwordsQListView->setModel(standardItemModel.get());

    fileManager.setFileName("passwords.txt");
    fileManager.createFile();

    connect(ui->savePassQPushButton, &QPushButton::clicked, this,
            &MainWindow::savePasswordButtonClicked);
    connect(ui->showPasswordQPushButton, &QPushButton::clicked, this,
            &MainWindow::showPasswordButtonClicked);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::savePasswordButtonClicked() {
    std::string password =
        ui->passwordInputQPlainTextEdit->toPlainText().toStdString();
    std::string keyword =
        ui->keywordInputQPlainTextEdit->toPlainText().toStdString();
    std::string encrypedPassword =
        passwordHandler.encryptPassword(password, keyword);

    fileManager.appendLineToFile(encrypedPassword);
}

void MainWindow::showPasswordButtonClicked() {
    for (auto It = items.begin(); It != items.end(); ++It) {
        delete It->release();
    }
    standardItemModel->clear();

    std::string data = fileManager.readFile();

    std::istringstream iss(data);
    std::string line;
    while (std::getline(iss, line, '\n')) {
        if (!line.empty()) {
            line = passwordHandler.decryptPassword(
                line, ui->decryptionKeywordQPlainTextEdit->toPlainText()
                          .toStdString());
            items.push_back(
                std::make_unique<QStandardItem>(QString::fromStdString(line)));
            standardItemModel->appendRow(items.back().get());
        }
    }
}
