#include <iostream>
#include <string>
#include <vector>
class Kata
{
public:
	std::vector<std::string> towerBuilder(int nFloors)
	{
		std::vector<std::string> tower;
		std::string floor;
		if(0 < nFloors)
		{
			int maxNumOfStars = (nFloors * 2) - 1;
			int curNumOfStars = 1;
			for (int curFloor = 0; curFloor < nFloors; ++curFloor)
			{
				for(int index = 0; index < ((maxNumOfStars- curNumOfStars)/2); ++index)
				{
					floor += ' ';
				}
				for(int index = 0; index < curNumOfStars; ++index)
				{
					floor += '*';
				}
				for(int index = 0; index < ((maxNumOfStars- curNumOfStars)/2); ++index)
				{
					floor += ' ';
				}
				curNumOfStars += 2;
				tower.push_back(floor);
				floor.clear();
			}
		}
		return tower;
	}
};



int main(int argc, char* argv[])
{
	std::vector<std::string> tower;
	Kata k;
	size_t height = 6;
	if (argc == 2)
	{
		height = atoi(argv[1]);
	}
	tower = k.towerBuilder(height);
	for (size_t index = 0; index < tower.size(); ++index)
	{
		std::cout << tower[index] << std::endl;
	}
	return 0;
}











/*
OTHER SOLUTIONS:
----------------
class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
      std::vector<std::string> ret;
      for(int i=0; i<nFloors ; i++)
      {
        ret.push_back(std::string(nFloors-i-1,' ') + 
                      std::string((i*2)+1,'*') +
                      std::string(nFloors-i-1,' '));
      }
      return ret;
    }
};
