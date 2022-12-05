#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>

void about()
{
	std::cout << "Advent calendar 2022: day 1" << std::endl;
}

int sumOfElfFood(std::vector<int>& elfFood)
{
	int sumElfFood{};

	for (auto& it : elfFood)
	{
		std::cout << it << std::endl;
		sumElfFood += it;
	}

	return sumElfFood;
}

int greaterElfCalories(std::vector<int>& elfFood)
{
	int maxCalories = *std::max_element(elfFood.begin(), elfFood.end());
	return maxCalories;
}

int main()
{
	about();
	std::fstream file;
	file.open("elfFood.txt", std::ios::in);

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
			std::cout << "read Elf calories from a file" << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "problem with opening of a file" << std::endl;
	}

	std::vector<int> readElfFood{};

	int calories{};
	int lineNumber{};
	int emptyLine{};

	while (!file.eof())
	{
		file >> calories;
		lineNumber++;

		if (calories == 0)
		{
			std::cout << "empty line" << std::endl;
			emptyLine++;
		}
		else
		{
			readElfFood.push_back(calories);
		}
	}

	std::cout << "Sum of Elf food - calories: " << sumOfElfFood(readElfFood) << std::endl;
	std::cout << "Max value of food calories: " << greaterElfCalories(readElfFood) << ", is in line " << lineNumber << std::endl;

	file.close();

	return 0;
}