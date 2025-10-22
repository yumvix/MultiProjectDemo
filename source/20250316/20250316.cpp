// 20250316.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


using namespace std;

enum class Color
{
	undefined =0,
	black,
	red
};

//
//struct Node
//{
//	Node(int i, const vector<int>& n)
//	{
//		index = i;
//		color = Color::undefined;
//		naberhoodIndexs = n;
//	}
//	int index;
//	Color color;
//	vector<int> naberhoodIndexs;
//	bool ColorNode(Color c, vector<Node>& totalNodes)
//	{
//		if (color != Color::undefined)
//		{
//			return false;
//		}
//		if (c == Color::red)
//		{
//			for (int i = 0; i < naberhoodIndexs.size(); i++)
//			{
//				if (totalNodes[naberhoodIndexs[i]].color == Color::red)
//				{
//					return false;
//				}
//			}
//		}
//		color = c;
//		return true;
//	}
//
//};
//
//vector<Node> totalNodes;
//
//namespace
//{
//
//}
//
//void ColorNodeRecursive(int index, int& trace)
//{
//	if (index == totalNodes.size()-1)
//	{
//		// 黑色必成功 红色可以成功 这边 +2 或者+1
//		trace += totalNodes[index].ColorNode(Color::red, totalNodes) + 1;
//		return;
//	}
//	bool success = totalNodes[index].ColorNode(Color::red, totalNodes);
//	if (success)
//	{
//		for (int i = 0; i< totalNodes[index].naberhoodIndexs.size(); i++)
//		{
//			ColorNodeRecursive(totalNodes[index].naberhoodIndexs[i], trace);
//		}
//	}
//	else
//	{
//		return;
//	}
//	totalNodes[index].color = Color::black;
//	for (int i = 0; i < totalNodes[index].naberhoodIndexs.size(); i++)
//	{
//		ColorNodeRecursive(totalNodes[index].naberhoodIndexs[i], trace);
//	}
//}
//
////int main()
////{
////	
////	Color c0 = Color(0,vector<int>({ 1,2 });
////
////	int find = 0;
////
////	0 1
////	1 3
////	2 3
////	0 2
////
////	for (int i = 0; i < totalNodes.size(); i++)
////	{
////		ColorNodeRecursive(i, find);
////	}
////
////	return find;
////}
//

struct Node
{
	Node() { color = Color::undefined; };
	Color color;
};
vector<Node> totalNodes;
vector<vector<int>> nabers;
int mcount = 0;
bool Visit(int deep)
{
	if (deep == totalNodes.size())
	{
		return false;
	}
	totalNodes[deep].color = Color::black;
	if (deep == totalNodes.size()-1)
	{
		mcount++;
	}
	Visit(deep + 1);
	totalNodes[deep].color = Color::undefined;

	for (const auto& i: nabers[deep])
	{
		if (totalNodes[i].color == Color::red)
		{
			return false;
		}
	}
	totalNodes[deep].color = Color::red;
	if (deep == totalNodes.size() - 1)
	{
		mcount++;
	}
	Visit(deep + 1);
	totalNodes[deep].color = Color::undefined;
	return true;
}

void main()
{
	totalNodes = vector<Node>(4);
	/*
	12  01
	24  13
	34  23
  	13  02
	*/
	nabers = vector<vector<int>>(7, vector<int>());
	nabers[0].emplace_back(1);
	nabers[1].emplace_back(0);
	nabers[1].emplace_back(3);
	nabers[3].emplace_back(1);
	nabers[2].emplace_back(3);
	nabers[3].emplace_back(2);
	nabers[0].emplace_back(2);
	nabers[2].emplace_back(0);
	Visit(0);
}


int Test(std::vector<int> input)
{
	int score = 0;

	//[1, 2, 3, 4, 5, 6, 7] ;
	int nowCount = 0;

	for (int to = 0; to < input.size(); to++)
	{
		int newScore = 0;
		nowCount += input[to];
		for (int from = 0; from <= to; from++)
		{
			//得分 扣分
			if (nowCount >= 100 && from == to)
			{
				newScore += input[to] - (nowCount - 100);
			}
			else
			{
				newScore += input[from] + input[from] * (-1) * (to - from);

			}
		}
		if (newScore >= score)
		{
			score = newScore;
		}
	}

	return score;
}



