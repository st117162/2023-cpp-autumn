#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int a = 0;
	int b = 1;
	int c = a + b;
	std::cin >> n;
	if (n == 0)
	{
		std::cout << 0 << std::endl;
	}
	for (int i = 2; i < n; ++i)
	{
		a = b;
		b = c;
		c = a + b;
	}
	std::cout << c << std::endl;
	return EXIT_SUCCESS;
}