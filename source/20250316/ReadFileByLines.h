#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> // 用于按空格/逗号分割内容


// 方法1：按行读取文件，每行作为数组的一个元素
std::vector<std::string> readFileByLines(const std::string& filePath);

// 方法2：按空格/逗号等分隔符分割文件内容
std::vector<std::string> readFileByTokens(const std::string& filePath);

