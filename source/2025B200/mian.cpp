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
	for (int i = 3; i < 15; i++)
	{
		if(card[i] > 0)
		{
			seg.emplace_back(card[i]);
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
						for (int k = 0;k < rst.size(); k++)
						{
							if (rst[i] == 14)
							{
								cout << "A" ;
							}
							else if (rst[i] == 15)
							{
								cout << "Error";
									return 0;
							}
							else if (rst[i] == 11)
							{
								cout << "J" ;
							}
							else if (rst[i] == 12)
							{
								cout << "Q";
							}
							else if (rst[i] == 13)
							{
								cout << "K";
							}
							else
							{
								cout << rst[i] << " ";
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
