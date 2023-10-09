#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int n = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	if (((n > a) && (n > b)) || ((a % 2 == 0) && (b % 2 == 0) && (n % 2 != 0)))
	{
		std::cout << "Impossible" << std::endl;
	}
	else
	{
		int a1 = 0;
		int b1 = 0;
		while ((a1 != n) || (b1 != n))
		{
			if (a1 == 0)
			{
				a1 = a;
				std::cout << ">A" << std::endl;
			}
			else
			{
				b1 = 0;
				std::cout << "B>" << std::endl;
			}
			(b1 == 0) ? b1 = a1, a1 = 0 : a1 = b1 + a1 - b, b1 = b;
			std::cout << "A>B" << std::endl;
		}
	}
	return EXIT_SUCCESS;
}