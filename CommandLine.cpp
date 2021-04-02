#include <iostream>
#include <Windows.h>
#include <Lmcons.h>
#include "Command.h"
#include "Settings.h"
#include "CommandHandler.h"
#include "SessionInfo.h"

int main()
{
    while (true) {
        Command command;

        std::string commandLinePrefix = CONSOLE_PREFIX;
        commandLinePrefix = commandLinePrefix.replace(commandLinePrefix.find("[username]"), 10, getUsername());
        commandLinePrefix = commandLinePrefix.replace(commandLinePrefix.find("[machine]"), 9, getComputerName());
        commandLinePrefix = commandLinePrefix.replace(commandLinePrefix.find("[directory]"), 11, getCWD());

        std::cout << commandLinePrefix << " ";
        std::getline(std::cin, command.origin);
        std::vector<std::string> tokens = Parse(command);
        Execute(tokens, command);
    }
}
