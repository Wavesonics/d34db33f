#include <iostream>
#include <chaiscript/chaiscript.hpp>
#include "ChaiProgram.h"


int main()
{
	const std::string OS_PATH = "os.chai";

	deadbeef::ChaiProgram os(OS_PATH);
	int exitCode = os.run();

	return exitCode;
}