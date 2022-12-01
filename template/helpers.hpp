#ifndef HELPERS_H
#define HELPERS_H

#include <fstream>
#include <string>
#include <vector>

namespace Helpers {
	constexpr char kFileName[] = "input.txt";

	std::vector<std::string> ReadInput() {
		std::vector<std::string> to_return;
		std::string line;
		std::ifstream f(kFileName);

		while ( std::getline( f, line ) )
			to_return.push_back( line );

		f.close();

		return to_return;
	}
}

#endif // #define HELPERS_H
