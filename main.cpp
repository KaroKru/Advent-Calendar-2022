#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void about()
{
	std::cout << "Advent calendar 2022: day 4" << std::endl;
	std::cout << "Camp Cleanup" << std::endl;
}

int checking(std::vector<int>& firstPart, std::vector<int>& secondPart)
{
	int sum{};

	if (firstPart[0] <= secondPart[0] and firstPart[1] >= secondPart[1])
	{
		std::cout << "pair in range of other" << std::endl;
		sum++;
	}
	else if (secondPart[0] <= firstPart[0] and secondPart[1] >= firstPart[1])
	{
		std::cout << "pair in range of other" << std::endl;
		sum++;
	}
	else
	{
		std::cout << "different ranges or partialy in range" << std::endl;
	}

	return sum;
}


int main()
{
	about();

	std::fstream file;
	file.open("camp.txt", std::ios::in);

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

	std::string line{};
	std::string firstPart{};
	std::string secondPart{};
	int sum{};

	while (!file.eof())
	{
		file >> line;

		std::cout << line << std::endl;
		std::string firstPart;
		std::string secondPart;

		auto lineLength = line.length();
		auto divideLine = lineLength / 2;

		firstPart = line.substr(0, divideLine);
		secondPart = line.substr(divideLine + 1, line.back());

		std::cout << firstPart << " " << secondPart << std::endl;

		auto firstPartOne = firstPart.substr(0, 1);
		auto firstPartTwo = firstPart.substr(2, 3);

		int onePartFirst = stoi(firstPartOne);
		int onePartSecond = stoi(firstPartTwo);

		std::vector<int> firstPartOfLine{};
		firstPartOfLine.push_back(onePartFirst);
		firstPartOfLine.push_back(onePartSecond);

		for (auto& it : firstPartOfLine)
		{
			std::cout << it << " ";
		}

		auto secondPartOne = secondPart.substr(0, 1);
		auto secondPartTwo = secondPart.substr(2, 3);

		int secondPartFirst = stoi(secondPartOne);
		int secondPartSecond = stoi(secondPartTwo);

		std::vector<int> secondPartOfLine{};
		secondPartOfLine.push_back(secondPartFirst);
		secondPartOfLine.push_back(secondPartSecond);

		for (auto& it : secondPartOfLine)
		{
			std::cout << it << " ";
		}

		checking(firstPartOfLine, secondPartOfLine);
		std::cout << std::endl;
	}

	std::cout << "Fully contain to each other: " << sum << std::endl;

	return 0;
}