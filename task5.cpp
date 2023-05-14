#include <iostream>

void initialising_game_sector_number(bool is_game_sector_number[]) {

	for (int i = 0; i < 5; ++i) {

		is_game_sector_number[i] = false;

	}


}



int main() {

	bool is_game_sector_number[5];

	initialising_game_sector_number(is_game_sector_number);


	for (int i = 0; i < 5; ++i) {

		std::cout << is_game_sector_number[i] << " ";

	}
	
}