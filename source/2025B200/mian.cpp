#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string strline;
	getline(cin, strline);

	stringstream ss(strline);

	vector<int> cards(16, 0);

	string card; // 
	while (ss >> card)
	{
		int value;
		if (card == "A")
		{
			value = 14;
		}
		else if ( card == "2")
		{
			value = 15;
		}
		else if (card == "J")
		{
			value = 11;
		}
		else if (card == "Q")
		{
			value = 12;
		}
		else if (card == "K")
		{
			value = 13;
		}
		else
		{
			value = stoi(card);
		}
		cards[value]++;
	}
	card[15] = 0;
	vector<int> seg;
	for (int index = 3; index < 15; index++)
	{
		if(card[index] > 0)
		{
			seg.emplace_back(card[index]);
		}
		else
		{
			vector<int> rst;
			if (seg.size() < 5)
			{
				continue;
			}

			for (int i = 0; i +4 < seg.size(); i++)
			{
				for (int j = i; j< seg.size(); j++)
				{
					rst.emplace_back(seg[j]);
					if (j - i < 4)
					{
						continue;
					}
					else
					{
						for (int k = i;k <= j; k++)
						{
							if (rst[k] == 14)
							{
								cout << "A" ;
							}
							else if (rst[k] == 15)
							{
								cout << "Error";
									return 0;
							}
							else if (rst[k] == 11)
							{
								cout << "J" ;
							}
							else if (rst[k] == 12)
							{
								cout << "Q";
							}
							else if (rst[k] == 13)
							{
								cout << "K";
							}
							else
							{
								cout << rst[k] << " ";
							}

							if (k == rst.size()-1)
							{
								cout << endl;
							}
							else
							{
								cout << " ";
							}
						}
					}
				}
			}
			seg.clear();
		}
	}
	return 0;
}
