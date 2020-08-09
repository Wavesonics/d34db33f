//
// Created by Adam on 8/9/2020.
//

#include "ChaiOs.h"
#include <iostream>

using namespace std;
using namespace deedbeef;

ChaiOs::ChaiOs()
{
	chai.add(chaiscript::fun(&ChaiOs::printRaw, this), "printRaw	");
	chai.add(chaiscript::fun(&ChaiOs::readLine, this), "readLine");
	chai.add(chaiscript::fun(&ChaiOs::run, this), "run");
}

int ChaiOs::boot()
{
	return chai.eval_file<int>(OS_PATH);
}

string ChaiOs::readLine()
{
	string line;
	getline(cin, line);

	return line;
}

bool ChaiOs::fileExists(const string& path) {
	ifstream f(path.c_str());
	return f.good();
}

int ChaiOs::run(const string& path)
{
	if(fileExists(path))
	{
		return chai.eval_file<int>(path);
	}
	else
	{
		cout << "Program not found" << endl;
		return 1;
	}
}

void ChaiOs::printRaw(const string& str)
{
	cout << str;
}
