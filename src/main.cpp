#include <iostream>
#include <chaiscript/chaiscript.hpp>
#include "ChaiOs.h"


int main()
{
	deedbeef::ChaiOs os;
	int exitCode = os.boot();

	return exitCode;
}