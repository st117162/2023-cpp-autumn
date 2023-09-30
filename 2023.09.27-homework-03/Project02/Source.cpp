#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int res = 0;
	std::cin >> a;
	for (int i = a; i > 0; i /= 10)
	{
		res = res * 10 + i % 10;
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}