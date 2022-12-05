#include <iostream>
#include <fstream>
#include <vector>

void about()
{
	std::cout << "Advent calendar 2022: day 2" << std::endl;
	std::cout << "Rock Paper Scissors tournament" << std::endl;
}

int main()
{
	std::fstream file;
	file.open("rockPaperScissors.txt", std::ios::in);

	try
	{
		if (!file.is_open())
		{
			std::cout << "Problem with opening of a file" << std::endl;
			std::cout << "File does not exist" << std::endl;
			throw 0;
		}
		else
		{
			std::cout << "file is open" << std::endl;
			std::cout << "read players strategy from a file" << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "problem with opening of a file" << std::endl;
	}

	char firstPlayer{};
	char secondPlayer{};

	int scoreFirstPlayer{ 0 };
	int scoreSecondPlayer{ 0 };

	while (!file.eof())
	{
		file >> firstPlayer >> secondPlayer;

		//points: 1 for Rock (A, X), 2 for Paper(B, Y), and 3 for Scissors(C, Z)
		//plus the score for the outcome of the round 
		//(0 if you lost, 3 if the round was a draw, and 6 if you won

		if (firstPlayer == 'A' and secondPlayer == 'Y')
		{
			std::cout << "second player win" << std::endl;
			scoreFirstPlayer += (1 + 0);
			scoreSecondPlayer += (2 + 6);
		}
		else if (firstPlayer == 'A' and secondPlayer == 'X')
		{
			std::cout << "draw" << std::endl;
			scoreFirstPlayer += (3 + 1);
			scoreSecondPlayer += (3 + 1);
		}
		else if (firstPlayer == 'A' and secondPlayer == 'Z')
		{
			std::cout << "firs player win" << std::endl;
			scoreFirstPlayer += (6 + 1);
			scoreSecondPlayer += (0 + 3);
		}
		else if (firstPlayer == 'B' and secondPlayer == 'X')
		{
			std::cout << "first player win" << std::endl;
			scoreFirstPlayer += (6 + 2);
			scoreSecondPlayer += (1 + 0);
		}
		else if (firstPlayer == 'B' and secondPlayer == 'Y')
		{
			std::cout << "draw" << std::endl;
			scoreFirstPlayer += (3 + 2);
			scoreSecondPlayer += (3 + 2);
		}
		else if (firstPlayer == 'B' and secondPlayer == 'Z')
		{
			std::cout << "second player win" << std::endl;
			scoreFirstPlayer += (0 + 2);
			scoreSecondPlayer += (6 + 3);
		}
		else if (firstPlayer == 'C' and secondPlayer == 'Z')
		{
			std::cout << "draw" << std::endl;
			scoreFirstPlayer += (3 + 0);
			scoreSecondPlayer += (3 + 0);
		}
		else if (firstPlayer == 'C' and secondPlayer == 'X')
		{
			std::cout << "second player win" << std::endl;
			scoreFirstPlayer += (0 + 3);
			scoreSecondPlayer += (6 + 1);
		}
		else if (firstPlayer == 'C' and secondPlayer == 'Y')
		{
			std::cout << "first player win" << std::endl;
			scoreFirstPlayer += (6 + 3);
			scoreSecondPlayer += (0 + 2);
		}
		else
		{
			std::cout << "other values than rock, paper or scissors" << std::endl;
		}
	}

	std::cout << "__________________________" << std::endl;

	std::cout << std::endl;
	std::cout << "points of first player: " << scoreFirstPlayer << std::endl;
	std::cout << "points of second player: " << scoreSecondPlayer << std::endl;
	std::cout << scoreFirstPlayer << " : " << scoreSecondPlayer << std::endl;

	if (scoreFirstPlayer > scoreSecondPlayer)
	{
		std::cout << "first player win match" << std::endl;
	}
	else if (scoreFirstPlayer == scoreSecondPlayer)
	{
		std::cout << "match draw" << std::endl;
	}
	else
	{
		std::cout << "second player win" << std::endl;
	}

	std::cout << std::endl;


	file.close();
	return 0;
}