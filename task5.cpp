#include <iostream>

void initialising_game_sector_number(bool is_game_sector_number[]) {

	for (int i = 0; i < 5; ++i) {

		is_game_sector_number[i] = false;

	}


}

void offset_of_the_current_sector_on_the_reel(int& offset, bool is_game_sector_number[]) {

	

}

int main() {

	bool is_game_sector_number[5];

	initialising_game_sector_number(is_game_sector_number);

	int offset;

	std::cout << "Please, enter offset: ";
	std::cin >> offset;

	is_game_sector_number[0] = true;

	if (offset > 5) {

		offset = offset % 5;

	}
	
	while (!is_game_sector_number[offset - 1] == false) {

		++offset;

	}

	is_game_sector_number[offset - 1] = true;

	std::cout << "offset = " << offset << "\n";


	for (int i = 0; i < 5; ++i) {

		std::cout << is_game_sector_number[i] << " ";

	}
	
}