//
// Created by Adam on 8/9/2020.
//

#include "ChaiProgram.h"
#include <iostream>
#include "chaiscript/extras/string_methods.hpp"
#include "chaiscript/extras/math.hpp"

using namespace std;
using namespace deadbeef;

ChaiProgram::ChaiProgram(const std::string &programPath) : path(programPath)
{
	auto mathlib = chaiscript::extras::math::bootstrap();
	chai.add(mathlib);

	auto stringlib = chaiscript::extras::string_methods::bootstrap();
	chai.add(stringlib);

	chai.add(chaiscript::fun(&ChaiProgram::printRaw, this), "printRaw");
	chai.add(chaiscript::fun(&ChaiProgram::readLine, this), "readLine");
	chai.add(chaiscript::fun(&execute), "execute");
	chai.add(chaiscript::fun(&ChaiProgram::fileExists, this), "fileExists");
	chai.add(chaiscript::fun(&ChaiProgram::srand, this), "srand");
	chai.add(chaiscript::fun(&ChaiProgram::rand, this), "rand");
}

string ChaiProgram::readLine()
{
	string line;
	getline(cin, line);

	return line;
}

bool ChaiProgram::fileExists(const string& filePath) {
	ifstream f(filePath.c_str());
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

void ChaiProgram::srand(int seed)
{
	std::srand(seed);
}

int ChaiProgram::rand()
{
	return std::rand();
}

int deadbeef::execute(const string& str)
{
	auto program = ChaiProgram(str);
	return program.run();
}