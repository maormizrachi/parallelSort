#include "input.h"

void getVector(std::string fileName, std::vector<int> &vector)
{
	std::fstream file;
	file.open(fileName, std::ios::in);
	if(!file.good())
    {
		std::cerr << "Error in reading from " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}
	else
    {
		while(true)
        {
			if(file.eof())
			{
				break;
			}
			int x;
            file >> x;
            vector.push_back(x);
        }
	}
	file.close();
}