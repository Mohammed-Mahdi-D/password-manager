#include <iostream>
#include <string>
#include <fstream>

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
	writeNewPassword("test.txt", "githheheheub", "chakaboukbouk"); 
	return 0;
}
