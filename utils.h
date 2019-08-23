#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>

class Utils {
public:
	//split a string <txt> everywhere a particular <ch> character is found
	static unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch) {
		int pos = txt.find(ch);
		int initialPos = 0;
		strs.clear();
		//take that <ch> and store those substrings in a vector <strs>
		while (pos != std::string::npos) {
			strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
			//resetting positions for the next iteration
			initialPos = pos + 1;

			pos = txt.find(ch, initialPos);
		}
		//add the very last grouping
		strs.push_back(txt.substr(initialPos, std::min<int>(pos, txt.size() - (initialPos + 1))));

		return strs.size();
	}
};

#endif // !UTILS_H