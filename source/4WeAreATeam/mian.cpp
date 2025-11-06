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
//
//int main()
//{
//	fstream file;
//	file.open("input.txt");
//
//	int n;
//	int m;
//	{
//		string input;
//		getline(file, input);
//		stringstream ss(input);
//		ss >> n;
//		ss >> m;
//	}
//
//	if (n < 1 || n > 100000 || m < 1 || m > 100000)
//	{
//		cout << "Null" << endl;;
//		return 0;
//	}
//	map<int, set<int>> teams;
//	for (int i = 0; i < m; i++)
//	{
//		int a, b, c;;
//		string input;
//		getline(file, input);
//		stringstream ss(input);
//		ss >> a;
//		ss >> b;
//		ss >> c;
//		if ((c != 0 && c != 1)|| a < 1 || a> n || b<1 || b > n)
//		{
//			cout << "da pian zi" << endl;
//			continue;
//		}
//		if (c == 0)
//		{
//			if (teams.find(a) != teams.end())
//			{
//				set<int> teamates = teams[a];
//				for (const auto& mem : teamates)
//				{
//					teams[mem].insert(b);
//				}
//				teams[a].insert(b);
//				teams.insert(make_pair(b, teamates));
//				teams[b].insert(a);
//			}
//			else if(teams.find(b) != teams.end())
//			{
//				set<int> teamates = teams[b];
//				for (const auto& mem : teamates)
//				{
//					teams[mem].insert(a);
//				}
//				teams[b].insert(a);
//				teams.insert(make_pair(b, teamates));
//				teams[a].insert(b);
//			}
//			else
//			{
//				teams.insert(make_pair(b, set{a}));
//				teams.insert(make_pair(a, set{ b }));
//			}
//		}
//		if (c == 1)
//		{
//			if (teams.find(a) != teams.end())
//			{
//				if (teams[a].find(b) != teams[a].end())
//				{
//					cout << "we are a team" << endl;
//					continue;
//				}
//			}
//			cout << "we are not a team" << endl;
//		}
//
//	}
//	return 0 ;
//}

#include <iostream>
#include <vector>
using namespace std;

// 并查集类
class UnionFind {
private:
    vector<int> parent;  // 存储每个元素的父节点

public:
    // 构造函数，初始化并查集
    UnionFind(int n) {
        parent.resize(n + 1);
        // 初始化，每个人最初是自己的代表
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // 查找元素x所属团队的根节点，使用路径压缩优化
    int find(int x) {
        if (parent[x] != x) {
            // 路径压缩：将x的父节点直接设置为根节点
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 将元素a和元素b所在的团队合并
    void unionSet(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            // 将rootA的父节点设置为rootB
            parent[rootA] = rootB;
        }
    }
};

int main() {
    int n, m;

    // 读取n和m
    cin >> n >> m;

    // 检查n和m是否在有效范围内
    if (n < 1 || n >= 100000 || m < 1 || m >= 100000) {
        cout << "Null" << endl;
        return 0;
    }

    // 创建并查集实例
    UnionFind uf(n);

    // 处理m条消息
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        // 检查a和b是否在有效范围内
        if (a < 1 || a > n || b < 1 || b > n) {
            cout << "da pian zi" << endl;
            continue;
        }

        // 根据指令c的值进行不同操作
        if (c == 0) {
            // c=0，将a和b合并到同一个团队
            uf.unionSet(a, b);
        }
        else if (c == 1) {
            // c=1，查询a和b是否在同一个团队
            if (uf.find(a) == uf.find(b)) {
                cout << "we are a team" << endl;
            }
            else {
                cout << "we are not a team" << endl;
            }
        }
        else {
            // c为其他值，输出错误信息
            cout << "da pian zi" << endl;
        }
    }

    return 0;
}

