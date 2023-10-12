#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	if (n >= 0)
	{
		while (n >= 0)
		{
			std::cout << n << " ";
			--n;
		}
	}
	else
	{
		while (n <= 0)
		{
			std::cout << n << " ";
			++n;
		}
	}
	std::cout << std::endl;

	return EXIT_SUCCESS;
}
