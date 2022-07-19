// https://adventofcode.com/2021/day/1
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream inputFileRead("input.txt");                                                                 // Open "input.txt"
	std::string inputFileContent;                                                                             // Current line's content
	int lastInputA = { 0 };                                                                                   // Last input A
	int lastInputB = { 0 };                                                                                   // Last input B
	int lastInputC = { 0 };                                                                                   // Last input C
	int amountOfIncreases = { -3 };                                                                           // Amount of increases (-3 because the first three inputs have nothing before it to compare to) Only problem is if the input is lower than 0...

	while (std::getline(inputFileRead, inputFileContent))                                                     // This should read every line in inputFileRead and save it to inputFileContent
	{
		if ((lastInputA + lastInputB + lastInputC) < (std::stoi(inputFileContent) + lastInputB + lastInputC)) // If the current input (inputFileContent) is bigger than the last input...
		{
			amountOfIncreases++;                                                                              // Then it has increased!
		}                                                                                                     // Otherwise do nothing
		lastInputA = { lastInputB };
		lastInputB = { lastInputC };
		lastInputC = { std::stoi(inputFileContent)};
	}
	std::cout << "2021D1P2: " << amountOfIncreases;                                                           // Display answer
	inputFileRead.close();                                                                                    // Close "input.txt"
}