#include "ReadFileByLines.h" // ���ڰ��ո�/���ŷָ�����


// ����1�����ж�ȡ�ļ���ÿ����Ϊ�����һ��Ԫ��
std::vector<std::string> readFileByLines(const std::string& filePath) {
    std::vector<std::string> lines;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return lines; // ���ؿ�����
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) { // ���Կ���
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

// ����2�����ո�/���ŵȷָ����ָ��ļ�����
std::vector<std::string> readFileByTokens(const std::string& filePath) {
    std::vector<std::string> tokens;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return tokens;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        while (iss >> token) { // Ĭ�ϰ��ո�ָ���滻Ϊ���ŷָ�
            tokens.push_back(token);
        }
    }
    file.close();
    return tokens;
}



