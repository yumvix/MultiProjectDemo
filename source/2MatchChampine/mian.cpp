#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//int main() {
//	string strline;
//	getline(cin, strline);
//
//	int count;
//	std::vector<int> strength;
//	vector<int> indexs;
//	cin >> count;
//	for (int i = 0; i < count; i++)
//	{
//		int temp;
//		cin >> temp;
//		strength.push_back(temp);
//		indexs.emplace_back(i);
//	}
//
//	while (indexs.size()>4)
//	{
//		vector<int> newIndexs;
//		// size = 3 i = 0 1
//		// size = 4 i = 0 1
//		// size = 5 i = 0 1 2
//		// size = 6 i = 0 1 2
//		for (int i = 0; i * 2+1 < indexs.size(); i++)
//		{
//			int rst = strength[indexs[2*i]] >= strength[indexs[2*i + 1]] ?indexs[ 2*i] : indexs[2*i + 1];
//			newIndexs.emplace_back(rst);
//			if ((indexs.size()%2))
//			{
//				indexs.emplace_back(indexs.size() - 1);
//			}
//		}
//		indexs = newIndexs;
//	}
//
//	if (indexs.size() == 4)
//	{
//		int candi0 = strength[indexs[0]];
//		int candi1 = strength[indexs[1]];
//		int candi2 = strength[indexs[2]];
//		int candi3 = strength[indexs[3]];
//	}
//	return 0;
//}

struct Candidate
{
	int strength;
	int index;
};

void Match(const vector<Candidate>& input, vector<Candidate>& winer, vector<Candidate>&loser)
{
	for (int i = 0; i*2+1 < input.size(); i++)
	{
		Candidate candi1 = input[2 * i];
		Candidate candi2 = input[2 * i + 1];
		candi1.strength < candi2.strength ? (winer.push_back(candi2), loser.push_back(candi1)) : (winer.push_back(candi1), loser.push_back(candi2));
	}
	if (input.size()%2)
	{
		winer.push_back(input[input.size() - 1]);
	}
}

void MatchFinal(const vector<Candidate>& input, int& first, int& second, int& third)
{
	vector<Candidate> winerNew = input;
	vector<Candidate>loserNew;

	while (winerNew.size()>2)
	{
		vector<Candidate> rstWiner;
		vector<Candidate> rstLoser;
		Match(winerNew, rstWiner, rstLoser);
		winerNew = rstWiner;
		loserNew = rstLoser;
	}
	if (winerNew[0].strength >= winerNew[1].strength)
	{
		first = winerNew[0].index;
		second = winerNew[1].index;
	}
	else
	{
		first = winerNew[1].index;
		second = winerNew[0].index;
	}
	if (loserNew.size() ==1)
	{
		third = loserNew[0].index;
	}
	else
	{
		if (loserNew[0].strength >= loserNew[1].strength)
		{
			third = loserNew[0].index;
		}
		else
		{
			third = loserNew[1].index;
		}
	}

}
// 方法2：按空格/逗号等分隔符分割文件内容
std::vector<Candidate> readFileByTokens(const std::string& filePath) {
	std::vector<Candidate> tokens;
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filePath << std::endl;
		return tokens;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		int token;
		int index = 0;
		while (iss >> token) { // 默认按空格分割，可替换为逗号分割
			Candidate c;
			c.strength = token;
			c.index = index;
			tokens.push_back(c);
			index++;
		}
	}
	file.close();
	return tokens;
}
int main()
{
	std::vector<Candidate> input = readFileByTokens("input.txt");
	int first, second, third;
	MatchFinal(input, first, second, third);
	cout << first << " " << second << " " << third;
}


// 给的答案是错的 https://blog.csdn.net/guorui_java/article/details/145382325
//#include <iostream>
//#include <vector>
//
//class Sportsman {
//public:
//	int id;
//	long strength;
//	Sportsman(int id, long strength) : id(id), strength(strength) {}
//};



//void promotionCompetition(std::vector<Sportsman>& sportsmanList, std::vector<std::vector<Sportsman>>& trophyList) {
//	std::vector<Sportsman> winList;
//	std::vector<Sportsman> failList;
//
//	for (size_t i = 0; i < sportsmanList.size(); i += 2) {
//		if (i == sportsmanList.size() - 1) {
//			winList.push_back(sportsmanList[i]);
//			continue;
//		}
//		Sportsman current = sportsmanList[i];
//		Sportsman next = sportsmanList[i + 1];
//
//		if (next.strength > current.strength) {
//			winList.push_back(next);
//			failList.push_back(current);
//		}
//		else if (next.strength < current.strength) {
//			winList.push_back(current);
//			failList.push_back(next);
//		}
//		else {
//			winList.push_back(current);
//			failList.push_back(next);
//		}
//	}
//
//	trophyList.push_back(failList);
//	trophyList.push_back(winList);
//}
//
//int main() {
//	int N;
//	std::cin >> N;
//	std::vector<Sportsman> sportsmanList;
//	for (int i = 0; i < N; i++) {
//		long strength;
//		std::cin >> strength;
//		sportsmanList.push_back(Sportsman(i, strength));
//	}
//
//	std::vector<std::vector<Sportsman>> trophyList;
//	promotionCompetition(sportsmanList, trophyList);
//
//	while (trophyList.back().size() > 1) {
//		promotionCompetition(trophyList[0], trophyList);
//	}
//
//	std::cout << trophyList[0][0].id << " " << trophyList[1][0].id << " " << trophyList[2][0].id << std::endl;
//
//	return 0;
//}
//
