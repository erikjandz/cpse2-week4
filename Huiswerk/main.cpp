#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>
#include <sstream> 

int main() {
	//1
	std::ifstream input("the-king-james-bible.txt");
	input >> std::noskipws;
	std::vector<char> bible{
		std::istream_iterator<char>{input},
		std::istream_iterator<char>{}
	};

	//2
	std::cout << "size = " << bible.size() << std::endl;

	//3
	std::cout << "amount of newlines: " << std::count(bible.begin(), bible.end(), '\n') << std::endl;

	//4
	int count = 0;
	std::string alfabet = "abcdefghijklmnopqrstuvwxyz";
	std::for_each(alfabet.begin(), alfabet.end(), [&](char& c) { count += std::count(bible.begin(), bible.end(), c); });
	std::cout << "amount from a to z " << count << std::endl;

	//5
	std::for_each(bible.begin(), bible.end(), [&](char& c) { c = std::tolower(c); });
	//for (auto i : bible) {
		//std::cout << i << std::endl;
	//}

	//6
	std::vector<int> letters;
	std::for_each(alfabet.begin(), alfabet.end(), [&](char& c) { letters.push_back(std::count(bible.begin(), bible.end(), c)); });

	//7.1
	std::cout << "every amount from a to z: " << std::endl;
	std::for_each(letters.begin(), letters.end(), [](int& c) {std::cout << c << std::endl; });
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
		if (dic.count(s2) > 0) {
			dic[s2] ++;
		}
		else {
			dic[s2] = 1;
		}
	}

	std::string word;
	int current_max;
	for (unsigned int i = 0; i < 10; i++) {
		current_max = 0;
		for (auto i : dic) {
			if (i.second > current_max){
				current_max = i.second;
				word = i.first;
			}
		}
		std::cout << word << "\n";
		dic.erase(word);
	}
	/*
	for (auto i : dic) {
		std::cout << i.first << " " << i.second << std::endl;
	}*/
}
