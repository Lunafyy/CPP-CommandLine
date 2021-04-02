#include "CommandHandler.h"

std::vector<std::string> Parse(Command cmd) {
	std::vector<std::string> tokens;

	std::string currentWord;

	for (char c : cmd.origin) {
		if (c != ' ') {
			currentWord += c;
		}
		else {
			tokens.push_back(currentWord);
			currentWord = "";
			
		}
	}
	if (currentWord != "") {
		tokens.push_back(currentWord);
	}


	return tokens;
}

void Execute(std::vector<std::string> tokens, Command cmd) {
	if (tokens.size() == 0) return;

	cmd.executionCommand = tokens[0];

	tokens.erase(tokens.begin());
	if (cmd.executionCommand == COMMAND_OUTPUT) {
		std::string outputMessage;
		for (std::string word : tokens) {
			outputMessage += word + " ";
		}

		std::cout << outputMessage << std::endl;
	}
	else {
		std::cout << "That is not a command!" << std::endl;
	}
}