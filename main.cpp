#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>


std::string generateRandomPassword(int length=8)
{
	const std::string characters = 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopwrstuvwxyz"
		"0123456789"
		"!@#$%^&*()_";
	std::string password;
	std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
	std::uniform_int_distribution<> distribution(0, characters.size() - 1);
	for(int i=0; i<length; i++)
	{
		password += characters[distribution(generator)];
	}
	return password;
			
}



void writeNewPassword(std::string path, std::string platform, std::string password)
{
	std::ofstream outFile(path, std::ios::app);
	if(outFile.is_open())
	{
		outFile << platform << "|"<<password << "\n";
		outFile.close();
	}
	else
	{
		std::cerr << "Failed to open the file" << "\n";
	}

}




std::string findLineInFile(std::string path, std::string myline)

{
	std::ifstream inFile("myfile.txt");
	if(inFile.is_open())
	{
		std::string line;
		while(std::getline(inFile, line))
		{
			if(line.substr(0, myline.size()) == myline)
			{
				return line;
			}
		}
		inFile.close();

	}
	else{
		std::cerr << "file was not opened correctly" << "\n";
	}
	return myline;
}

int main()
{
	std::cout << generateRandomPassword(16);
	return 0;
}
