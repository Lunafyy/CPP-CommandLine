#pragma once
#include <iostream>
#include <Windows.h>
#include <Lmcons.h>
#include <string>
#include "SessionInfo.h"

std::string cwd = "C:\\Users\\" + getUsername();

std::string getUsername() {
	DWORD usernameLen = UNLEN + 1;
	char username[UNLEN + 1];

	GetUserName(username, &usernameLen);

	return std::string(username);

}

std::string getComputerName() {
	DWORD computerNameLen = UNCLEN + 1;
	char computerName[UNCLEN + 1];

	GetComputerName(computerName, &computerNameLen);

	return std::string(computerName);
}

std::string getCWD() {
	return cwd;
}

void setCWD(std::string newCWD) {
	cwd = newCWD;
}
