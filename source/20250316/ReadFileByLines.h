#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> // ���ڰ��ո�/���ŷָ�����


// ����1�����ж�ȡ�ļ���ÿ����Ϊ�����һ��Ԫ��
std::vector<std::string> readFileByLines(const std::string& filePath);

// ����2�����ո�/���ŵȷָ����ָ��ļ�����
std::vector<std::string> readFileByTokens(const std::string& filePath);

