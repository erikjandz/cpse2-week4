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
	std::map<char, int> letters;
	std::for_each(alfabet.begin(), alfabet.end(), [&](const char& c) {letters[c] = std::count(bible.begin(), bible.end(), c); });

	//7.1
	std::cout << "every indivudual amount from a to z: " << std::endl;
	std::for_each(letters.begin(), letters.end(), [](const auto & letter ) {std::cout << letter.first << ": " << letter.second << std::endl; });
	//7.2
	std::cout << "every amount sorted form a to z: " << std::endl;
	char c;
	while(letters.size() != 0) {
		int current_max = 99999999;
		for (auto i : letters) {
			if (i.second < current_max) {
				current_max = i.second;
				c = i.first;
			}
		}
		std::cout << c << ": " << current_max << "\n";
		letters.erase(c);
	}
	//std::sort(letters.begin(), letters.end());
	//std::for_each(letters.begin(), letters.end(), [](const auto & letter) { std::cout << letter.first << ": " << letter.second << std::endl; });

	//8
	std::map<std::string, int> words;
	std::string temp;
	bool flaag = false;
	for(auto c : bible) {
		if ('a' <= c && c <= 'z') {
			flaag = true;
			temp += c;
		}else if (flaag) {
			if (words.count(temp) > 0) {
				words[temp] ++;
			}
			else {
				words[temp] = 1;
			}
			flaag = false;
			temp = "";
		}
	}
	if (flaag) {
		if (words.count(temp) > 0) {
			words[temp] ++;
		}
		else {
			words[temp] = 1;
		}
		flaag = false;
		temp = "";
	}

	std::cout << "the ten most occuring words are: \n";
	std::string word;
	int current_max;
	for (unsigned int i = 0; i < 10; i++) {
		current_max = 0;
		for (auto i : words) {
			if (i.second > current_max) {
				current_max = i.second;
				word = i.first;
			}
		}
		std::cout << word << ": " << current_max << "\n";
		words.erase(word);
	}
	
	/*for (auto i : words) {
		std::cout << i.first << " " << i.second << std::endl;
	}*/
}