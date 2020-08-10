//
// Created by Adam on 8/9/2020.
//

#ifndef D34DB33F_CHAIPROGRAM_H
#define D34DB33F_CHAIPROGRAM_H


#include <chaiscript/chaiscript.hpp>

namespace deadbeef
{
	class ChaiProgram
	{
	private:
		const std::string path;
		chaiscript::ChaiScript chai;
	public:
		explicit ChaiProgram(const std::string& programPath);

		void printRaw(const std::string& str);
		std::string readLine();
		bool fileExists(const std::string& filePath);
		int run();
	};

	int execute(const std::string& path);
}

#endif //D34DB33F_CHAIPROGRAM_H
