#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	int res = 1;
	while (n != 0)
	{
		res *= n % 10;
		n /= 10;
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}
