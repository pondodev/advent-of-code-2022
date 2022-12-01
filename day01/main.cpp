#include <iostream>

#include "helpers.hpp"

int main() {
	const auto input = Helpers::ReadInput();

	uint32_t max = 0;
	uint32_t current = 0;

	for ( const auto& item : input ) {
		if ( item == "" ) { // end of current inventory
			if ( current > max ) max = current;
			current = 0;
		} else { // add to current inventory
			auto calories = std::stoi(item);
			current += calories;
		}
	}

	std::cout << "max is: " << max << std::endl;

	return 0;
}
