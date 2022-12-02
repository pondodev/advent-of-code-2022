#include <iostream>
#include <vector>

#include "helpers.hpp"

int main() {
	const auto input = Helpers::ReadInput();

	// part 1
	{

	uint32_t max = 0;
	uint32_t current = 0;

	for ( const auto& item : input ) {
		if ( item == "" ) { // end of current inventory
			if ( current > max ) max = current;
			current = 0;
		} else { // add to current inventory
			auto calories = std::stoi( item );
			current += calories;
		}
	}

	std::cout << "max is: " << max << std::endl;

	}

	// part 2
	{

	uint32_t current = 0;
	std::vector<uint32_t> inventories;

	for ( const auto& item : input ) {
		if ( item == "" ) { // end of current inventory
			inventories.push_back( current );
			current = 0;
		} else { // add to current inventory
			auto calories = std::stoi( item );
			current += calories;
		}
	}

	std::sort( inventories.begin(), inventories.end(), [](const uint32_t& a, const uint32_t& b) -> bool { return a > b; } );

	uint32_t sum = 0;
	constexpr uint32_t kTopCount = 3;
	for ( size_t i = 0; i < kTopCount; ++i ) sum += inventories[ i ];

	std::cout << "sum is: " << sum << std::endl;

	}

	return 0;
}
