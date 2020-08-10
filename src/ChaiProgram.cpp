//
// Created by Adam on 8/9/2020.
//

#include "ChaiProgram.h"
#include <iostream>
#include <utility>

using namespace std;
using namespace deadbeef;

ChaiProgram::ChaiProgram(std::string _path) : path(std::move(_path))
{
	chai.add(chaiscript::fun(&ChaiProgram::printRaw, this), "printRaw");
	chai.add(chaiscript::fun(&ChaiProgram::readLine, this), "readLine");
	chai.add(chaiscript::fun(&execute), "execute");
	chai.add(chaiscript::fun(&ChaiProgram::fileExists, this), "fileExists");
}

string ChaiProgram::readLine()
{
	string line;
	getline(cin, line);

	return line;
}

bool ChaiProgram::fileExists(const string& path) {
	ifstream f(path.c_str());
	return f.good();
}

std::string loadScript(const std::string &path)
{
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();

	return buffer.str();
}

int ChaiProgram::run()
{
	if(fileExists(path))
	{
		try
		{
			return chai.eval_file<int>(path);
		}
		catch(chaiscript::exception::eval_error& e)
		{
			cout << "eval_error: " << endl << e.pretty_print();
			return -4;
		}
		catch(chaiscript::exception::bad_boxed_cast& e)
		{
			cout << "bad_boxed_cast" << endl << e.what();
			return -3;
		}
		catch(std::exception& e)
		{
			cout << "std::exception" << endl << e.what() << endl;
			return -2;
		}
	}
	else
	{
		//cout << "Program not found" << endl;
		return -1;
	}
}

void ChaiProgram::printRaw(const string& str)
{
	cout << str;
}

int deadbeef::execute(const string& str)
{
	auto program = ChaiProgram(str);
	return program.run();
}