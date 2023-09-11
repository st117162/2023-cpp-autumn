#include<iostream>

int main(int argc, char* argv[])
{
	long long a = 0;
	std::cin >> a;
	long long b = abs(a / 10);
	std::cout << (b * (b + 1) * 100) + 25 << std::endl;
	return EXIT_SUCCESS;
}