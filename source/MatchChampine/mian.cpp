#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;




int main() {
	string strline;
	getline(cin, strline);

	int count;
	std::vector<int> strength;
	vector<int> indexs;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int temp;
		cin >> temp;
		strength.push_back(temp);
		indexs.emplace_back(i);
	}

	while (indexs.size()>4)
	{
		vector<int> newIndexs;
		// size = 3 i = 0 1
		// size = 4 i = 0 1
		// size = 5 i = 0 1 2
		// size = 6 i = 0 1 2
		for (int i = 0; i * 2+1 < indexs.size(); i++)
		{
			int rst = strength[indexs[2*i]] >= strength[indexs[2*i + 1]] ?indexs[ 2*i] : indexs[2*i + 1];
			newIndexs.emplace_back(rst);
			if ((indexs.size()%2))
			{
				indexs.emplace_back(indexs.size() - 1);
			}
		}
		indexs = newIndexs;
	}

	if (indexs.size() == 4)
	{
		int candi0 = strength[indexs[0]];
		int candi1 = strength[indexs[1]];
		int candi2 = strength[indexs[2]];
		int candi3 = strength[indexs[3]];

		


	}


	return 0;
}
