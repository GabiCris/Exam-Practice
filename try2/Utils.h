#pragma once
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> tokenize(const std::string& text, char delimiter) {
	std::vector<std::string> result;
	std::stringstream stream(text);
	std::string word;
	while (getline(stream, word, delimiter))
		result.push_back(word);
	return result;
}