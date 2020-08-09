#include <iostream>
#include <sstream>
#include <fstream>
#include "wren.hpp"

using namespace std;

static void writeFn(WrenVM *vm, const char *text)
{
	cout << text << endl;
}

void errorFn(WrenVM *vm, WrenErrorType errorType,
			 const char *module, const int line,
			 const char *msg)
{
	switch(errorType)
	{
		case WREN_ERROR_COMPILE:
		{
			printf("[%s line %d] [Error] %s\n", module, line, msg);
		}
			break;
		case WREN_ERROR_STACK_TRACE:
		{
			printf("[%s line %d] in %s\n", module, line, msg);
		}
			break;
		case WREN_ERROR_RUNTIME:
		{
			printf("[Runtime Error] %s\n", msg);
		}
			break;
	}
}

std::string loadScript(const std::string& path)
{
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();

	return buffer.str();
}

int main()
{
	WrenConfiguration config;
	wrenInitConfiguration(&config);
	config.writeFn = &writeFn;
	config.errorFn = &errorFn;
	WrenVM *vm = wrenNewVM(&config);

	const char *module = "main";
	const std::string script = loadScript("test.wren");

	WrenInterpretResult result = wrenInterpret(vm, module, script.c_str());

	switch(result)
	{
		case WREN_RESULT_COMPILE_ERROR:
		{
			printf("Compile Error!\n");
		}
			break;
		case WREN_RESULT_RUNTIME_ERROR:
		{
			printf("Runtime Error!\n");
		}
			break;
		case WREN_RESULT_SUCCESS:
		{
			printf("Success!\n");
		}
			break;
	}

	wrenFreeVM(vm);

	return 0;
}