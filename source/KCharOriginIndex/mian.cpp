#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <map>
#include <functional>
#include <iterator>
using namespace std;


struct CharAndIndex
{
	char c;
	int index;

	bool operator < (const CharAndIndex& r) const
	{
		if (this->c == r.c)
		{
			return this->index < r.index;
		}
		else
		{
			return this->c < r.c;
		}
	}


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
	function compare = [=](const CharAndIndex& l, const CharAndIndex& r) -> bool {
		if (l.c == r.c)
		{
			return l.index < r.index;
		}
		else
		{
			return l.c < r.c;
		}
		};
	set<CharAndIndex> sorted;
	for (int i = 0; i < input.size(); i++)
	{
		CharAndIndex temp;
		temp.c = input[i];
		temp.index = i;
		sorted.insert(temp);
	}

	for (const auto& c : sorted)
	{
		cout << c.c << " " << c.index << endl;
	}

	auto beg = sorted.cbegin();

	for (int i = 0; i < index-1; i++)
	{
		 beg++;
	}

	auto c = beg;
	for (int i = 0; i < index-1; i++)
	{
		if (beg !=sorted.cbegin())
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

