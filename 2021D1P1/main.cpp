// https://adventofcode.com/2021/day/1
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream inputFileRead("input.txt");             // Open "input.txt"
	std::string inputFileContent;                         // Current line's content
	int lastInput = '0';                                  // Last input
	int amountOfIncreases = -1;                           // Amount of increases (-1 because the first input has nothing before it to compare to) Only problem is if the input is lower than 0...

	while (std::getline(inputFileRead, inputFileContent)) // This should read every line in inputFileRead and save it to inputFileContent
	{
		if (lastInput < std::stoi(inputFileContent))      // If the current input (inputFileContent) is bigger than the last input...
		{
			amountOfIncreases++;                          // Then it has increased!
		}                                                 // Otherwise do nothing
		lastInput = std::stoi(inputFileContent);          // Save the current input (inputFileContent) to the last input (lastInput) so we can compare our next input
	}

	std::cout << "2021D1P1: " << amountOfIncreases;       // Display answer
	inputFileRead.close();                                // Close "input.txt" (Not needed)
}