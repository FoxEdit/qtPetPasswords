#include "passwordhandler.h"

#include <cmath>

std::string PasswordHandler::encryptPassword(const std::string& password,
                                             const std::string& keyword) {
    std::string encrypedPassword;
    for (int i = 0, j = 0; i < password.length(); ++i, ++j) {
        if (j == keyword.length()) j = 0;
        int encrypedCharInt = (password[i] - 32) + (keyword[j] - 32);
        char encrypedChar = encrypedCharInt % 95 + 32;
        encrypedPassword.push_back(encrypedChar);
    }
    return encrypedPassword;
}

std::string PasswordHandler::decryptPassword(const std::string& password,
                                             const std::string& keyword) {
    std::string decrypedPassword;
    for (int i = 0, j = 0; i < password.length(); ++i, ++j) {
        if (j == keyword.length()) j = 0;
        int decrypedCharInt = (password[i] - 32) - (keyword[j] - 32) + 95;
        char decrypedChar = decrypedCharInt % 95 + 32;
        decrypedPassword.push_back(decrypedChar);
    }
    return decrypedPassword;
}
