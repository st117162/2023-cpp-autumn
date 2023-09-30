#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int res = 0;
	std::cin >> a;
	for (int i = 1; i * i <= a; ++i)
	{
		if (a % i == 0)
		{
			++res;
			if (a / i != i)
			{
				++res;
			}
		}
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}