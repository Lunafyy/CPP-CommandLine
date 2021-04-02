#pragma once
#include <iostream>
#include <string>

struct Command {
	std::string origin;
	std::string executionCommand;
};

std::ostream& operator<<(std::ostream& os, const Command& m)
{
	return os << m.origin;
}