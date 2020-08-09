#include <iostream>
#include <chaiscript/chaiscript.hpp>

using namespace std;

std::string loadScript(const std::string &path)
{
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();

	return buffer.str();
}

string readLine()
{
	std::string line;
	std::getline(std::cin, line);

	return line;
}

int main()
{
	chaiscript::ChaiScript chai;
	chai.add(chaiscript::fun(&readLine), "readLine");

	const string scriptFile = "test.chai";
	const auto script = loadScript("test.chai");

	int i = chai.eval_file<int>(scriptFile);
	cout << i << endl;

	return 0;
}