#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>

class FileManager {
    std::string fileName;
    std::fstream fstream;
public:
    FileManager() = default;
    ~FileManager() = default;

    void setFileName(const std::string& fileName);
    std::string getFileName();

    void createFile();
    bool isFileExists();
    void appendLineToFile(const std::string& text);
    void writeToFile(const std::string& text);
    std::string readFile();
};

#endif  // FILEMANAGER_H
