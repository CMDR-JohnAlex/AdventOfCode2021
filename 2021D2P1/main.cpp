// https://adventofcode.com/2021/day/2
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
	std::ifstream inputFileRead{ "input.txt" };                 // Open "input.txt"
	std::string inputFileContent;                               // Current line's content
	int horizontalPosition = { 0 };                             // Horizontal position
	int depth = { 0 };                                          // Depth (anything less than 0 is in the air)
	
	while (std::getline(inputFileRead, inputFileContent))       // This should read every line in inputFileRead and save it to inputFileContent
	{
		std::istringstream stringSplitResult(inputFileContent); // istringstream (#include sstream) should break apart anything with a space, aka the direction and the amount
		std::string direction;
		int amount;
		stringSplitResult >> direction >> amount;               // Split "forward 5" into "forward" and '5' and store them to their string and int
		std::cout << direction << " " << amount << '\n';
		if (direction == "forward")                             // If the word is forward...
		{
			horizontalPosition += amount;                       // Then add amount to horizontal
		}
		if (direction == "down")                                // If the word is down...
		{
			depth += amount;                                    // Then add amount to depth
		}
		if (direction == "up")                                  // If the word is up...
		{
			depth -= amount;                                    // Then subtract amount to depth
		}
	}

	std::cout << "2021D2P1: " << horizontalPosition * depth;    // Display answer
	inputFileRead.close();                                      // Close "input.txt" (Not needed)

	return 0;
}
