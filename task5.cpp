#include <iostream>
#include <string>
#include <fstream>

void initialising_game_sector_number(bool is_game_sector_number[]) {

	for (int i = 0; i < 5; ++i) {

		is_game_sector_number[i] = false;

	}
}

void offset_of_the_current_sector_on_the_reel(int& offset, bool is_game_sector_number[]) {

	std::cout << "Please, enter offset: ";
	std::cin >> offset;
	

	if (offset > 5) {

		offset = offset % 5;

	}

	while (!is_game_sector_number[offset - 1] == false) {

		++offset;

	}

	is_game_sector_number[offset - 1] = true;

	std::cout << "offset = " << offset << "\n";

}

void win(bool is_game_sector_number[], int& offset, std::ifstream& f_question, std::ifstream& f_answer) {

	int point_connoisseurs = 0;
	int point_viewers = 0;

	std::string the_answer_of_connoisseurs;

	std::string buffer_question;
	std::string buffer_answers;

	while ((point_connoisseurs != 2) || (point_viewers != 2)) {

		offset_of_the_current_sector_on_the_reel(offset, is_game_sector_number);


		for (int i = 0; i < offset; ++i) {

			getline(f_question, buffer_question);
			f_answer >> buffer_answers;

		}




		std::cout << "Attention question: " << buffer_question << std::endl;
		std::cout << "answers: " << buffer_answers << std::endl;






		std::cout << "Connoisseurs, please enter the answer: ";
		std::cin >> the_answer_of_connoisseurs;

		if (buffer_answers == the_answer_of_connoisseurs) {


			std::cout << "You answered correctly!" << std::endl;
			std::cout << "Expert team wins 1 point" << std::endl;

			++point_connoisseurs;

		}
		else {


			std::cout << "You answered incorrectly!\n";
			std::cout << "Correct answer: " << buffer_answers << std::endl;
			std::cout << "1 point goes to the viewer team" << std::endl;

			++point_viewers;
		}

		std::cout << "Game Score: " << point_connoisseurs << ":" << point_viewers << std::endl;

		if (point_connoisseurs > point_viewers) {

			std::cout << "The expert team wins\n";

		}
		else if (point_connoisseurs < point_viewers) {

			std::cout << "Viewer team wins\n";

		}
		else {

			std::cout << "Draw in the game\n";

		}



	}

}

int main() {

	bool is_game_sector_number[5];
	int offset;
	

	std::ifstream f_question;
	std::ifstream f_answer;



	initialising_game_sector_number(is_game_sector_number);	

	f_question.open("questions.txt");

	if (f_question.is_open()) {

		std::cout << "Question file is open\n";
		std::cout << std::endl;

	}
	else {

		std::cout << "WARNING!\n";
		std::cout << "ERROR!!!\n";
		std::cout << "File is not open\n";

	}

	f_answer.open("answers.txt");

	if (f_answer.is_open()) {

		std::cout << "Answer file is open\n";
		std::cout << std::endl;

	}
	else {

		std::cout << "WARNING!\n";
		std::cout << "ERROR!!!\n";
		std::cout << "File is not open\n";

	}

	

	win( is_game_sector_number, offset, f_question, f_answer);




	for (int i = 0; i < 5; ++i) {

		std::cout << is_game_sector_number[i] << " ";

	}
	



	f_question.close();
	f_answer.close();
}