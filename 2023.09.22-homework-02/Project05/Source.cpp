#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	if ((n / 10) % 10 != 1)
	{
		if ((n % 10 <= 4) && (n % 10 >= 2))
		{
			std::cout << n << " " << "bochki" << std::endl;
		}
		else if (n % 10 == 1)
		{
			std::cout << n << " " << "bochka" << std::endl;
		}
		else
		{
			std::cout << n << " " << "bochek" << std::endl;
		}
	}
	else
	{
		std::cout << n << " " << "bochek" << std::endl;
	}
	return EXIT_SUCCESS;
}