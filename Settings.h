#pragma once
#include <string>

// Console Stuff
std::string CONSOLE_PREFIX = "[username]@[machine]$~[directory]>";

// Commands
std::string COMMAND_OUTPUT = "echo";
std::string COMMAND_CD = "cd";
std::string COMMAND_LOC = "loc";
std::string COMMAND_MAKE_NEW_DIRECTORY = "mkdir";
std::string COMMAND_REMOVE_DIRECTORY = "rmdir";
std::string COMMAND_LIST_DIRECTORY = "ls";
std::string COMMAND_CLEAR = "cls";

// Errors
std::string COMMAND_UNKNOWN = "'[command]' is not recognized as an internal or external command.";
std::string COMMAND_CD_INVALID_DIRECTORY = "The system cannot find the path specified.";
std::string COMMAND_INVALID_SYNTAX = "The syntax of the command is incorrect.";