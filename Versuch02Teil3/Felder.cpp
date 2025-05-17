/*
 * Felder.cpp
 *
 *  Created on: 2025年5月15日
 *      Author: wangb
 */

#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

// 函数：生成加密查找表
void generateLookupTable(char table[2][26]) {
    // 填充第一行，从A-Z
    for (int i = 0; i < 26; ++i) {
        table[0][i] = 'A' + i;
    }
    // 用A-Z填充第二行，随机打乱顺序
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::shuffle (alphabet.begin(), alphabet.end(), rng);
    for (int i = 0; i < 26; ++i) {
        table[1][i] = alphabet[i];
    }
}

// 函数：加密单词
std::string encryptWord(const std::string& word, const char table[2][26]) {
    std::string encryptedWord;
    for (char c : word) {
        if (std::isupper(c)) {
            int index = c - 'A';
            encryptedWord += table[1][index];
        } else {
            encryptedWord += c;
        }
    }
    return encryptedWord;
}

// 函数：解密单词
std::string decryptWord(const std::string& encryptedWord, const char table[2][26]) {
    std::string decryptedWord;
    for (char c : encryptedWord) {
        if (std::isupper(c)) {
            for (int i = 0; i < 26; ++i) {
                if (table[1][i] == c) {
                    decryptedWord += table[0][i];
                    break;
                }
            }
        } else {
            decryptedWord += c;
        }
    }
    return decryptedWord;
}

int main() {
    char lookupTable[2][26];
    generateLookupTable(lookupTable);

    // 测试加密解密功能
    std::string userInput;
    std::cout << "请输入一个大写字母单词: ";
    std::cin >> userInput;

    std::string encrypted = encryptWord(userInput, lookupTable);
    std::string decrypted = decryptWord(encrypted, lookupTable);

    std::cout << "明文: " << userInput << std::endl;
    std::cout << "加密后: " << encrypted << std::endl;
    std::cout << "解密后: " << decrypted << std::endl;

    return 0;
}



