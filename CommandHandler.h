#pragma once
#include "Command.h"
#include "Settings.h"
#include "SessionInfo.h"
#include <filesystem>
#include <vector>

std::vector<std::string> Parse(Command cmd);

void Execute(std::vector<std::string> tokens, Command cmd);
