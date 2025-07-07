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
	cards[15] = 0;
	vector<int> seg;
	for (int index = 3; index < 15; index++)
	{
		if(cards[index] > 0)
		{
			seg.emplace_back(index);
			if (seg.size() < 5)
			{
				continue;
			}

			for (int i = 0; i + 4 < seg.size(); i++)
			{
				for (int j = i; j < seg.size(); j++)
				{
					if (seg[j] == 14)
					{
						cout << "A";
					}
					else if (seg[j] == 15)
					{
						cout << "Error";
						return 0;
					}
					else if (seg[j] == 11)
					{
						cout << "J";
					}
					else if (seg[j] == 12)
					{
						cout << "Q";
					}
					else if (seg[j] == 13)
					{
						cout << "K";
					}
					else
					{
						cout << seg[j] << " ";
					}

					if (j == seg.size() - 1)
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
		else
		{
			seg.clear();
		}
	}
	return 0;
}
