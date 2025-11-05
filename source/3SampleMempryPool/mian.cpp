#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <map>
#include <functional>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	map<int, int> memPoolLeft;
	map<int, int> memPoolUsed;
	memPoolLeft.insert(make_pair(0, 100));


	string input;
	int cmdCount;
	fstream file;
	file.open(("input.txt"));

	file >> cmdCount;
	for (int i = 0; i < cmdCount; i++)
	{
		string cmd;
		file >> cmd;

		string cmdPrefixcmd = cmd.substr(0, 7);
		string spaceCountStr = cmd.substr(8, cmd.size());
		if (cmdPrefixcmd == "REQUEST")
		{
			int spaceCount = stol(spaceCountStr);
			if (spaceCount<= 0)
			{
				cout << "error" << endl;
			}
			bool finded = false;
			int firstAddr = 100;
			for (auto& kv : memPoolLeft)
			{
				if (kv.second >= spaceCount)
				{
					finded = true;
					firstAddr = kv.first;
					cout << firstAddr << endl;
					break;
				}
			}
			if (finded)
			{	
				int newfirst = firstAddr + spaceCount;
				int spaceLeft = memPoolLeft[firstAddr] - spaceCount;
				memPoolLeft.erase(firstAddr);
				memPoolLeft.insert(make_pair(newfirst, spaceLeft));
				memPoolUsed.insert(make_pair(firstAddr, spaceCount));
			}
			else
			{
				cout << "error" << endl;
			}
		}
		else if (cmdPrefixcmd == "RELEASE")
		{
			int firstAddr = stol(spaceCountStr);
			if (memPoolUsed.find(firstAddr) == memPoolUsed.end())
			{
				cout << "error" << endl;
			}
			int spaceCount = memPoolUsed[firstAddr];
			memPoolUsed.erase(firstAddr);

			auto it = memPoolLeft.find(firstAddr + spaceCount);

			if (it != memPoolLeft.end())
			{
				int newCount = memPoolLeft[firstAddr + spaceCount] + spaceCount;
				memPoolLeft.erase(firstAddr + spaceCount);
				memPoolLeft.insert(std::make_pair(firstAddr, newCount));
			}
			else
			{
				memPoolLeft.insert(make_pair(firstAddr, spaceCount));
			}

			auto it2 = memPoolLeft.find(firstAddr);
			if (it2 != memPoolLeft.begin())
			{
				it2--;
				if (it2->first + it2->second == firstAddr)
				{
					int newCount = it2->second + memPoolLeft[firstAddr];
					memPoolLeft.erase(firstAddr);
					it2->second = newCount;
				}
			}

		}
		else
		{
			cout << "error";
		}


	}

}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<pair<int, int>> free_blocks; // 空闲块列表（按起始地址升序）
//    free_blocks.emplace_back(0, 100);   // 初始内存池：0~99
//    unordered_map<int, int> allocated;  // 已分配块字典 {起始地址: 大小}
//
//    for (int i = 0; i < n; ++i) {
//        string line;
//        cin >> line;
//        size_t eq_pos = line.find('=');
//        string cmd = line.substr(0, eq_pos);
//        int param = stoi(line.substr(eq_pos + 1));
//
//        if (cmd == "REQUEST") {
//            int size = param;
//            if (size <= 0) {
//                cout << "error" << endl;
//                continue;
//            }
//            bool found = false;
//            // 遍历空闲块列表，找到第一个足够大的块
//            for (auto it = free_blocks.begin(); it != free_blocks.end();) {
//                int start = it->first;
//                int block_size = it->second;
//                if (block_size >= size) {
//                    // 分配该块
//                    cout << start << endl;
//                    allocated[start] = size;
//                    // 处理剩余空间
//                    int remaining = block_size - size;
//                    if (remaining > 0) {
//                        *it = { start + size, remaining }; // 修改当前块为剩余部分
//                    }
//                    else {
//                        free_blocks.erase(it); // 无剩余则删除该块
//                    }
//                    found = true;
//                    break;
//                }
//                else {
//                    ++it; // 继续查找下一个块
//                }
//            }
//            if (!found) {
//                cout << "error" << endl;
//            }
//        }
//        else if (cmd == "RELEASE") {
//            int addr = param;
//            auto it = allocated.find(addr);
//            if (it == allocated.end()) {
//                cout << "error" << endl;
//                continue;
//            }
//            int size = it->second;
//            allocated.erase(it); // 从已分配字典中删除
//
//            // 将释放的块插入到空闲列表的正确位置
//            pair<int, int> new_block = { addr, size };
//            auto insert_it = lower_bound(
//                free_blocks.begin(), free_blocks.end(), new_block,
//                [](const pair<int, int>& a, const pair<int, int>& b) {
//                    return a.first < b.first;
//                }
//            );
//            int pos = insert_it - free_blocks.begin();
//            free_blocks.insert(insert_it, new_block);
//
//            // 合并左侧相邻块
//            while (pos > 0 && free_blocks[pos - 1].first + free_blocks[pos - 1].second == free_blocks[pos].first) {
//                free_blocks[pos - 1].second += free_blocks[pos].second;
//                free_blocks.erase(free_blocks.begin() + pos);
//                pos--;
//            }
//
//            // 合并右侧相邻块
//            while (pos < free_blocks.size() - 1 && free_blocks[pos].first + free_blocks[pos].second == free_blocks[pos + 1].first) {
//                free_blocks[pos].second += free_blocks[pos + 1].second;
//                free_blocks.erase(free_blocks.begin() + pos + 1);
//            }
//        }
//    }
//
//    return 0;
//}
