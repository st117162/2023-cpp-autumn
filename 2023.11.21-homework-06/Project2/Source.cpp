#include<iostream>

void hanoi(int n, int from, int to);

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

void hanoi(int n, int from, int to)
{
	if (n <= 0)
	{
		return;
	}

	int res = 6 - from - to;

	if (res == 2)
	{
		hanoi(n, from, res);
		hanoi(n, res, to);
	}
	else
	{
		hanoi(n - 1, from, res);
		printf("%d %d %d\n", n, from, to);
		hanoi(n - 1, res, to);
	}
}
