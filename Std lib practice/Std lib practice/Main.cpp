#include <iostream>
#include <string>
#include <vector> //dynamic array

int main()
{

	std::vector<int> numbers;
	numbers.reserve(10);

	/*numbers.push_back(100);
	numbers.push_back(200);
	numbers.push_back(300);
	numbers.push_back(400);
	numbers.push_back(500);

	numbers.pop_back();*/ //takes away last one

	bool isAppRunning = true;

	while (isAppRunning)
	{
		auto num = 0;
		std::cout << "Enter a number" << std::endl;
		std::cin >> num;

		std::cout << numbers.size() << std::endl;
		std::cout << numbers.capacity() << std::endl;

		if (num == 0)
		{
			isAppRunning = false;
		}
	}
	for (auto it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	/*for (size_t i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << std::endl;
	}

	for (const auto& i : numbers)
	{
		std::cout << i << std::endl;
	}

	numbers[0] = 10;

	int n = numbers[2];*/

	system("pause");
	return 0;
}