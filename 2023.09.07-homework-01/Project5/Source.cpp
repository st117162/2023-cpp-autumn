#include<iostream>

int main(int argc, char* argv[])
{
	int v = 0;
	int t = 0;
	std::cin >> v >> t;
	std::cout << (v * t % 109 + 109) % 109 + 1 << std::endl;
	return EXIT_SUCCESS;
}