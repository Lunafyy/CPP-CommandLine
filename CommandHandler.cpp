#include "CommandHandler.h"
#include "SessionInfo.h"
#include <Windows.h>

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
	else if (cmd.executionCommand == COMMAND_LOC) {
		std::cout << getCWD() << std::endl;
	}
	else if(cmd.executionCommand == COMMAND_CD) {
		try {
			if (tokens.size() == 0) {
				std::cout << getCWD() << std::endl;
				return;
			}

			if (std::string(tokens[0]) == "..") {
				if (getCWD().find('\\') > tokens[0].length()) return;
				int index = 0;
				std::string cwd = getCWD();
				for (int i = 0; i < cwd.length(); i++) {
					if (cwd[i] == '\\') {
						index = i;
					}
				}
				cwd.erase(cwd.begin() + index, cwd.end());
				setCWD(cwd);
			}
			else {
				std::string cwd = getCWD() + "\\" + tokens[0];
				LPCSTR newDirectory = cwd.c_str();
				if (GetFileAttributes(newDirectory) != INVALID_FILE_ATTRIBUTES) {
					setCWD(cwd);
				}
				else {
					std::cout << COMMAND_CD_INVALID_DIRECTORY << std::endl;
				}
			}
		}
		catch (...){
			std::cout << getCWD() << std::endl;
		}
	}
	else if(cmd.executionCommand == COMMAND_MAKE_NEW_DIRECTORY) {
		if (tokens.size() == 0) {
			std::cout << COMMAND_INVALID_SYNTAX << std::endl;
			return;
		}
		for (std::string token : tokens) {
			std::string cwd = getCWD() + "\\" + token;
			CreateDirectory(cwd.c_str(), NULL);
		}
		
		
	}
	else if (cmd.executionCommand == COMMAND_REMOVE_DIRECTORY) {
		if (tokens.size() == 0) {
			std::cout << COMMAND_INVALID_SYNTAX << std::endl;
			return;
		}
		for (std::string token : tokens) {
			std::string cwd = getCWD() + "\\" + token;
			RemoveDirectory(cwd.c_str());
		}
	}
	else if (cmd.executionCommand == COMMAND_LIST_DIRECTORY) {
		WIN32_FIND_DATAA data;
		HANDLE hFind = INVALID_HANDLE_VALUE;
		std::string scanPath = getCWD() + "\\*";

		hFind = FindFirstFileA(scanPath.c_str(), &data);

		if (hFind == INVALID_HANDLE_VALUE) {
			std::cout << "Internal HANDLE Error" << std::endl;
		}

		while (FindNextFileA(hFind, &data) != 0) {
			std::cout << std::string(data.cFileName) << " - " << data.nFileSizeLow << "B" << std::endl;
		}

		FindClose(hFind);
	}
	else if (cmd.executionCommand == COMMAND_CLEAR) {
		system("cls");
	}
	else {
		std::string unknownCommand = COMMAND_UNKNOWN;
		unknownCommand = unknownCommand.replace(unknownCommand.find("[command]"), 9, cmd.executionCommand);
		std::cout << unknownCommand << std::endl;
	}
	std::cout << std::endl;
}