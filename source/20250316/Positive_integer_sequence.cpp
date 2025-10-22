#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> // 用于按空格/逗号分割内容


#include "Positive_integer_sequence.h"
#include "ReadFileByLines.h" // 用于按空格/逗号分割内容



#if 0
std::vector<int> Positive_integer_sequence(int sum, int count)
{
    std::vector<int> e = std::vector<int>(1, -1);
    if (sum <0 || count< 0)
    {
        return e;
    }

    std::vector<int> rst = std::vector<int>(count, 0);

    if (count % 2 == 1)
    {
        if (sum% count == 0)
        {

            int midVal = sum / count;
            int beginDiff = count / 2;
            int midIndex = count / 2;

            if (midVal - beginDiff < 1)
            {
                return e;
            }
            for (int i = 0; i <= midIndex; i++)
            {
                rst[midIndex - i] = midVal - i;
                rst[midIndex + i] = midVal + i;
            }
            return rst;
        }
    }
    else
    {
        if (sum*2 % count == 0)
        {
            int midValL = sum / count;
            int midValR = sum / count + 1;

            int midIndexL = count / 2 - 1;
            int midIndexR = count / 2;


            int beginDiff = midIndexL;

            if (midValL - beginDiff < 1)
            {
                return e;
            }
            for (int i = 0; i <= midIndexL; i++)
            {
                rst[midIndexL - i] = midValL - i;
                rst[midIndexR + i] = midValR + i;
            }
            return rst;
        }
    }

    return e;
}

#elif 1


//
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    int S, N;
//    // 读取输入
//    cin >> S >> N;
//
//    // 计算起始数x
//    double x = ((double)S / N) - ((double)(N - 1) / 2);
//    int xInt = round(x);
//
//    // 检查x是否为正整数且满足总和为S
//    if (xInt > 0 && (xInt * N + N * (N - 1) / 2) == S) {
//        for (int i = 0; i < N; i++) {
//            cout << (xInt + i) << " ";
//        }
//    }
//    else {
//        cout << "-1";
//    }
//
//    return 0;
//}

std::vector<int> Positive_integer_sequence(int sum, int count)
{
    std::vector<int> rst;
    double start = (double)sum / count - double(count-1) / 2;
    int begin = std::round(start);


    if (start > 0 && sum == (start*count + count*(count-1)/2))
    {
        for (int i = 0; i < count; i++)
        {
            rst.emplace_back(begin + 1);
        }
        return rst;
    }
    return std::vector<int>(1, -1);

}

#endif

//int main() {
//    // 1. 获取当前程序运行目录（C++17 可用 std::filesystem）
//    std::string currentDir = "./"; // 默认当前目录
//    std::string inputFile = currentDir + "input.txt";
//
//    // 2. 读取文件内容并转换为数组
//    //std::vector<std::string> lines = readFileByLines(inputFile);
//    //或按空格/逗号分割：
//    std::vector<std::string> tokens = readFileByTokens(inputFile);
//
//    int sum = std::stoi(tokens[0]);
//    int count = std::stoi(tokens[1]);
//
//
//    std::vector<int> rst = Positive_integer_sequence(sum, count);
//
//    // 3. 打印结果
//    std::cout << "File content as array:\n";
//    for (const auto& val : rst) {
//        std::cout << val << "\n";
//    }
//
//    return 0;
//}



