#include <iostream>
#include <string>
#include <fstream>

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
	return 0;
}
