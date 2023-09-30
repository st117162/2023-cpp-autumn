#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	for (int i = 0; a > 0; ++i)
	{
		for (int j = i; (j > 0) && (a > 0); --j)
		{
			std::cout << i << " ";
			--a;
		}
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}