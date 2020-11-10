#include <iostream>
int main()
{
	for(int i = 0; i < 40*12; i++)
	{
		std::cout << (i % 40) << ", " << (i / 40) << std::endl;	
	}
}
