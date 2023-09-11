#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	std::cout << (1 + a) * (abs(1 - a) + 1)/ 2  << std::endl;
	return EXIT_SUCCESS;
}