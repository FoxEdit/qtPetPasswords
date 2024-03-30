#ifndef PASSWORDHANDLER_H
#define PASSWORDHANDLER_H

#include <QString>

class PasswordHandler {
public:
    PasswordHandler() = default;
    ~PasswordHandler() = default;

    std::string encryptPassword(const std::string& password, const std::string& keyword);
    std::string decryptPassword(const std::string& password, const std::string& keyword);
};

#endif  // PASSWORDHANDLER_H
