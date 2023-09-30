#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	while (a > b)
	{
		if ((a % 2 == 0) && (a / 2 > b))
		{
			std::cout << ":2" << std::endl;
			a /= 2;
		}
		else
		{
			std::cout << "-1" << std::endl;
			--a;
		}
	}
	return EXIT_SUCCESS;
}