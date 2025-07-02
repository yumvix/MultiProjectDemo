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




	std::cout << "Project1";
	return 0;
}
