#pragma once
#include "Command.h"
#include "Settings.h"
#include <vector>

std::vector<std::string> Parse(Command cmd);

void Execute(std::vector<std::string> tokens, Command cmd);
