// https://adventofcode.com/2021/day/3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream inputFileRead("input.txt");                 // Open "input.txt"
	std::string inputFileContent;                             // Current file line
	std::getline(inputFileRead, inputFileContent);
	std::string gammaRate = {};                               // gammaRate
	std::string epsilonRate = {};                             // epsilonRate

	for (int i = 0; i < inputFileContent.length(); i++)       // While there is another bit row to read
	{
		std::ifstream inputFileRead("input.txt");             // Open "input.txt"
		int zeroBits = 0;                                     // How many zeros in the current row
		int oneBits = 0;                                      // How many ones in the current row
		while (std::getline(inputFileRead, inputFileContent)) // This should read every line in inputFileRead and save it to inputFileContent
		{
			if (inputFileContent[i] == '0')                   // If the content is 0, then...
			{
				zeroBits += 1;                                // Add one to zeroBits
			}
			if (inputFileContent[i] == '1')                   // If the content is 1, then...
			{
				oneBits += 1;                                 // Add one to oneBits
			}
		}
		inputFileRead.close();                                // Close "input.txt"
		if (zeroBits > oneBits)                               // If there are more zeroBits in the row, then...
		{
			gammaRate += "0";                                 // gammaRate adds a zero to the string
			epsilonRate += "1";                               // elipsonRate adds a one to the string
		}
		if (zeroBits < oneBits)                               // If there are more oneBits in the row, then...
		{
			gammaRate += "1";                                 // gammaRate adds a one to the string
			epsilonRate += "0";                               // elipsonRate adds a zero to the string
		}
	}

	std::cout << "2021D3P1: " << std::stoi(gammaRate, NULL, 2) * std::stoi(epsilonRate, NULL, 2); // Display answer
}

/* AN ATTEMPT USING STD::VECTOR (It failed and took me too long)

	std::ifstream inputFileRead("input.txt");
	std::string inputFileContent;
	std::vector<std::vector<int>> data;
	std::string gammaRate = {};
	std::string epsilonRate = {};

	while (std::getline(inputFileRead, inputFileContent))
	{
		for (int i = 0; i < inputFileContent.size(); i++)
		{
			//data.resize(i + 1);
			data.resize(inputFileContent.size());
			data[i].push_back(inputFileContent[i] - 48);
		}
		// TODO: Check all the rows in the data vector, if there are more 1s then append 1 to the gammaRate and 0 to the epsilonRate. If there are more 0s then append 0 to the gammaRate and 1 to the epsilonRate.
	}
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			std::cout << data[i][j];
		}
		std::cout << '\n';
	}

	std::cout << "2021D3P1: " << "0"; // Display answer
	inputFileRead.close(); // Close "input.txt"

*/
