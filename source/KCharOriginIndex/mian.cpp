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


struct CharAndIndex
{
	char c;
	int index;
	// 1
	//bool operator < (const CharAndIndex& r) const
	//{
	//	if (this->c == r.c)
	//	{
	//		return this->index < r.index;
	//	}
	//	else
	//	{
	//		return this->c < r.c;
	//	}
	//}


};

int main()
{
	ifstream file;
	file.open("input.txt");

	string s;

	getline(file, s);
	stringstream ss(s);

	string input;
	int index;

	ss >> input;
	ss >> index;


	//map<char, int> sorted;
	//for (int i = 0; i < input.size(); i++)
	//{

	//	sorted.insert(std::make_pair(input[i], i));
	//}

	//for (const auto& c: sorted)
	//{
	//	cout << c.first << " " << c.second << endl;
	//}

	//auto beg = sorted.begin();
	//for (int i = 0; i < index; i ++)
	//{
	//	beg;
	//}

	//cout << beg->second;
	// 2
	struct Compare
	{
		// 自定义比较函数 需要const 限定符 标准要求
		//Severity	Code	Description	Project	File	Line	Suppression State	Details
		//Error	C3848	expression having type 'const main::Compare' would lose some const - volatile qualifiers in order to call 'bool main::Compare::operator ()(const CharAndIndex &,const CharAndIndex &)'	KCharOriginIndex	C : \Program Files\Microsoft Visual Studio\2022\Professional\VC\Tools\MSVC\14.39.33519\include\xutility	1382
		bool operator()(const CharAndIndex& l, const CharAndIndex& r) const
		{
			if (l.c == r.c)
			{
				return l.index < r.index;
			}
			else
			{
				return l.c < r.c;
			}
		}
	};

	const auto& pre = [&](const CharAndIndex& l, const CharAndIndex& r) -> bool
		{
			if (l.c == r.c)
			{
				return l.index < r.index;
			}
			else
			{
				return l.c < r.c;
			}
		};

	// set 和 multiset 默认使用 less<T> 进行比较，产生升序排列。
	set<CharAndIndex, decltype(pre) > sorted(pre);
	vector<CharAndIndex> toSort;
	for (int i = 0; i < input.size(); i++)
	{
		CharAndIndex temp;
		temp.c = input[i];
		temp.index = i;
		sorted.insert(temp);
		toSort.emplace_back(temp);
	}
	std::stable_sort(toSort.begin(), toSort.end(), pre);

	{
		//for (const auto& c : sorted)
		//{
		//	cout << c.c << " " << c.index << endl;
		//}

		//auto beg = sorted.cbegin();

		//for (int i = 0; i < index - 1; i++)
		//{
		//	beg++;
		//}

		//auto c = beg;
		//for (int i = 0; i < index - 1; i++)
		//{
		//	if (beg != sorted.cbegin())
		//	{
		//		beg--;
		//	}
		//	else {
		//		break;
		//	}
		//	if (c->c != beg->c)
		//	{
		//		break;
		//	}
		//	c = beg;
		//}
	}
	for (const auto& c : toSort)
	{
		cout << c.c << " " << c.index << endl;
	}

	auto beg = toSort.cbegin();
	//3 迭代器移动操作
	advance(beg, index - 1);

	//for (int i = 0; i < index - 1; i++)
	//{
	//	beg++;
	//}

	auto c = beg;
	for (int i = 0; i < index - 1; i++)
	{
		if (beg != toSort.cbegin())
		{
			beg--;
		}
		else {
			break;
		}
		if (c->c != beg->c)
		{
			break;
		}
		c = beg;
	}

	cout << c->index;
}

