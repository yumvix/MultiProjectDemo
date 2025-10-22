#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> // ���ڰ��ո�/���ŷָ�����


#include "Positive_integer_sequence.h"
#include "ReadFileByLines.h" // ���ڰ��ո�/���ŷָ�����



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
//    // ��ȡ����
//    cin >> S >> N;
//
//    // ������ʼ��x
//    double x = ((double)S / N) - ((double)(N - 1) / 2);
//    int xInt = round(x);
//
//    // ���x�Ƿ�Ϊ�������������ܺ�ΪS
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
//    // 1. ��ȡ��ǰ��������Ŀ¼��C++17 ���� std::filesystem��
//    std::string currentDir = "./"; // Ĭ�ϵ�ǰĿ¼
//    std::string inputFile = currentDir + "input.txt";
//
//    // 2. ��ȡ�ļ����ݲ�ת��Ϊ����
//    //std::vector<std::string> lines = readFileByLines(inputFile);
//    //�򰴿ո�/���ŷָ
//    std::vector<std::string> tokens = readFileByTokens(inputFile);
//
//    int sum = std::stoi(tokens[0]);
//    int count = std::stoi(tokens[1]);
//
//
//    std::vector<int> rst = Positive_integer_sequence(sum, count);
//
//    // 3. ��ӡ���
//    std::cout << "File content as array:\n";
//    for (const auto& val : rst) {
//        std::cout << val << "\n";
//    }
//
//    return 0;
//}



