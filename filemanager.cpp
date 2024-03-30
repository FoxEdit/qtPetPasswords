#include "filemanager.h"

#include <QDebug>
#include <fstream>
#include <sstream>

void FileManager::setFileName(const std::string& fileName) {
    if (fileName.length() < 256)
        this->fileName = fileName;
    else
        qDebug() << "Unsuccessful attempt to create a file! (fileName has >255 "
                    "length)";
};

std::string FileManager::getFileName() { return this->fileName; };

void FileManager::createFile() {
    if (!isFileExists() && !fileName.empty()) {
        fstream.open(fileName, std::ios::out);
        fstream.close();
    }
};

std::string FileManager::readFile() {
    if (isFileExists()) {
        fstream.open(fileName, std::ios::in);
        std::stringstream sstream;
        sstream << fstream.rdbuf();
        fstream.close();
        return sstream.str();

    }
    qDebug() << "Unsuccessful attempt to read a file! (file does not exists)";
    return "";
}

bool FileManager::isFileExists() {
    if (!fileName.empty()) {
        fstream.open(fileName, std::ios::in);
        bool isExists = fstream.good();
        fstream.close();
        return isExists;
    }
    qDebug() << "Unsuccessful attempt to check a file! (fileName is empty)";
    return false;
}

void FileManager::appendLineToFile(const std::string& text) {
    if (isFileExists()) {
        fstream.open(fileName, std::ios::app);
        fstream << '\n' + text;
        fstream.close();
    } else
        qDebug()
            << "Unsuccessful attempt to append a file! (file does not exists)";
}
