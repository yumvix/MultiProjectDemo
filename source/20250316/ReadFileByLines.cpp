#include "ReadFileByLines.h" // 用于按空格/逗号分割内容


// 方法1：按行读取文件，每行作为数组的一个元素
std::vector<std::string> readFileByLines(const std::string& filePath) {
    std::vector<std::string> lines;
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return lines; // 返回空数组
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) { // 忽略空行
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

// 方法2：按空格/逗号等分隔符分割文件内容
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
        while (iss >> token) { // 默认按空格分割，可替换为逗号分割
            tokens.push_back(token);
        }
    }
    file.close();
    return tokens;
}



