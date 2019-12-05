#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

int main(){
	//1
	std::ifstream input("the-king-james-bible.txt");
	std::string s = " ";
	std::vector<char> bible = {};
	while (input) {
		input >> s;
		for (auto c : s) {
			bible.push_back(c);
		}
	}
	//2
	std::cout << "size = " << bible.size() << std::endl;
	
	//3
	std::cout << "amount of newlines: " <<std::count(bible.begin(), bible.end(), '\n') << std::endl;

	//4
	int count = 0;
	std::string alfabet = "abcdefghijklmnopqrstuvwxyz";
	std::for_each(alfabet.begin(), alfabet.end(), [&](char& c) { count += std::count(bible.begin(), bible.end(), c); });
	std::cout << "amount of a to z " <<count << std::endl;

	//5
	std::for_each(bible.begin(), bible.end(), [&](char& c) { c = std::tolower(c); });
	//for (auto i : bible) {
		//std::cout << i << std::endl;
	//}

	//6
	std::vector<int> letters;
	std::for_each(alfabet.begin(), alfabet.end(), [&](char& c) { letters.push_back(std::count(bible.begin(), bible.end(), c)); });

	//7.1
	std::cout << "every amount form a to z: " << std::endl;
	std::for_each(letters.begin(), letters.end(), [](int & c) {std::cout << c << std::endl; });
	//7.2
	std::cout << "every amount sorted form a to z: " << std::endl;
	std::sort(letters.begin(), letters.end());
	std::for_each(letters.begin(), letters.end(), [](int& c) {std::cout << c << std::endl; });

	//8
	std::map<std::string, int> dic;
	std::ifstream input2("the-king-james-bible.txt");
	std::string s2;
	while (input2) {
		input2 >> s2;
		if (dic.count(s2) > 0){
			dic[s2] ++;
		}else {
			dic[s2] = 1;
		}
	}
		/*auto x = std::max_element(dic.begin(), dic.end(),
			[](const decltype(dic)::value_type<std::string, int>& p1, const pair<std::string, int > & p2) {
			return p1.second < p2.second; });
		std::cout << x->first;*/
	for (auto i : dic) {
		std::cout << i.first << " " << i.second << std::endl;
	}
}
