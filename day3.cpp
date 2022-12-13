#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void about()
{
	std::cout << "Advent calendar 2022: day 3" << std::endl;
	std::cout << "Rucksacks" << std::endl;
}

int lineScore(std::string &part)
{
	int totalScore{ 0 };
	std::vector<int> score;
	for (auto c1 = part.begin(); c1 != part.end(); c1++)
	{
		std::cout << *c1 << " ";

		if (*c1 >= 'a' and *c1 <= 'z')
		{
			totalScore = ((*c1 - 'a') + 1);
			score.push_back(totalScore);
		}
		else if (*c1 >= 'A' and *c1 <= 'Z')
		{
			totalScore = (*c1 - 'A') + 27;
			score.push_back(totalScore);
		}
		else
		{
			std::cout << "Something other" << std::endl;
		}
	}

	std::cout << std::endl;
	
	int sum{ 0 };

	for (auto i = score.begin(); i != score.end(); i++)
	{
		std::cout << *i << " ";
		sum += *i;
	}
	std::cout << std::endl;
	std::cout << "Sum: " << sum << std::endl;

	return totalScore;
}


int main()
{
	about();

	std::string firstPart;
	std::string secondPart;

	std::fstream file;
	file.open("rucksacks.txt", std::ios::in);

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
			std::cout << "read from a file" << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "problem with opening of a file" << std::endl;
	}

	std::string line{};
	int totalScoreFirsLine{0};
	int totalScoreSecondLine{0};

	while (!file.eof())
	{
		file >> line;
		std::cout << line << std::endl;

		auto lineLength = line.length();
		auto divideLine = lineLength / 2;

		firstPart = line.substr(0, divideLine);
		secondPart = line.substr(divideLine, line.back());
	}
	
	std::cout << std::endl;
	std::cout << "Line: " << lineScore(line) << std::endl;
	std::cout << "First part of line: " << lineScore(firstPart) << std::endl;
	std::cout << "Second part of line: " << lineScore(secondPart) << std::endl;

	file.close();

	return 0;
}