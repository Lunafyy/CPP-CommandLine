#include <iostream>
#include <Windows.h>
#include <Lmcons.h>
#include "Command.h"
#include "Settings.h"
#include "CommandHandler.h"


int main()
{
    DWORD usernameLen = UNLEN + 1;
    char username[UNLEN+1];
    
    GetUserName(username, &usernameLen);

    DWORD computerNameLen = UNCLEN + 1;
    char computerName[UNCLEN + 1];

    GetComputerName(computerName, &computerNameLen);

    std::string currentDirectory = "C:\\Users\\" + std::string(username);

    CONSOLE_PREFIX = CONSOLE_PREFIX.replace(CONSOLE_PREFIX.find("[username]"), 10, username);
    CONSOLE_PREFIX = CONSOLE_PREFIX.replace(CONSOLE_PREFIX.find("[machine]"), 9, computerName);
    CONSOLE_PREFIX = CONSOLE_PREFIX.replace(CONSOLE_PREFIX.find("[directory]"), 11, currentDirectory);
    while (true) {
        Command command;
        std::cout << CONSOLE_PREFIX << " ";
        std::getline(std::cin, command.origin);
        std::vector<std::string> tokens = Parse(command);
        Execute(tokens, command);
    }
}
