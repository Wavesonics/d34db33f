//
// Created by Adam on 8/9/2020.
//

#ifndef D34DB33F_CHAIOS_H
#define D34DB33F_CHAIOS_H


#include <chaiscript/chaiscript.hpp>

namespace deedbeef
{
	class ChaiOs
	{
	private:
		const std::string OS_PATH = "os.chai";
		chaiscript::ChaiScript chai;
	public:
		ChaiOs();

		int boot();
		void printRaw(const std::string& str);
		std::string readLine();
		bool fileExists(const std::string& path);
		int run(const std::string& path);
	};
}

#endif //D34DB33F_CHAIOS_H
