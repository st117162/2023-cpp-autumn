#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int res = 0;
	std::cin >> n;
	for (int i = 1; i < n; i *= 2)
	{
		++res;
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}