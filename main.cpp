#include <iostream>
#include <string>
#include <vector>
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
	std::ifstream inFile(path);
	if(inFile.is_open())
	{
		std::string line;
		while(std::getline(inFile, line))
		{
			if(line.substr(0, myline.size()) == myline)
			{
				inFile.close();
				return line;
			}
		}
		inFile.close();
	}
	else{
		std::cerr << "file was not opened correctly" << "\n";
	}
	return "f";
}


std::string addPassword()
{
	std::string platform;

	std::cout << "Enter the name of the platform: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, platform);

	std::string password = generateRandomPassword();
	writeNewPassword("test.txt", platform, password);

	return password;
}

std::string readPassword()
{
	std::string platform;

	std::cout << "Enter the name of the platform: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, platform);

	std::string line;
	line = findLineInFile("test.txt", platform);

	return line.substr(platform.size()+1, line.size());

		

}


void updateFile(std::string path, std::string platform, std::string newpassword)
{
	std::ifstream fileIn(path);
	if(! fileIn.is_open())
	{
		std::cerr << "Unable to open file";
		return;
	}

	std::vector<std::string> lines;
	std::string line;

	while(std::getline(fileIn, line))
	{
		if(line.substr(0, platform.size()) == platform)
		{
			lines.push_back(platform + "|" + newpassword);
		}	
		else
		{
		lines.push_back(line);
		}
	}
	
	fileIn.close();

	std::ofstream fileOut(path);
	if(! fileOut.is_open())
	{
		std::cerr << "Unable to open file";
	}

	for (const auto& updatedLine : lines)
	{
		fileOut << updatedLine << "\n";
	}
	
	fileOut.close();

	return;

	
}


std::string updatePassword()
{
	std::string platform;

	std::cout << "Enter the name of the platform: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, platform);

	std::string line;
	line = findLineInFile("test.txt", platform);

	std::string newpassword = generateRandomPassword();

	
	updateFile("test.txt", platform, newpassword);


	return newpassword;
	


}

void deletePassword()
{
	return;
}



void baseFunction()
{
	std::cout << "Welcome to your password manager, what task do you want to perform:\n"
		     "1-Add password\n"
		     "2-Read an existing password\n"
		     "3-Update a password\n"
		     "4-Delete a password\n"
		     "(1-4), or 'q' to quit: ";
	char c;
	std::cin >> c;
	
	switch (c)
	{
		case '1':
			std::cout << "generated password: " << addPassword() << "\n";
			break;
		case '2':
			std::cout << readPassword() << "\n";
			break;

		case '3':
			std::cout << updatePassword() << "\n";
			break;
		case '4':
			deletePassword();
			break;
		case 'q':
			return;
			break;
		default:
			std::cout << "Invalid input, try again\n";
			baseFunction();
			break;
	}
}

int main()
{
	baseFunction();
	return 0;
}
