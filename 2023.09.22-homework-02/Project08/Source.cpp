#include<iostream>
int max(int x, int y, int z)
{
	if ((x >= y) && (x >= z))
	{
		return x;
	}
	else if ((y >= x) && (y >= z))
	{
		return y;
	}
	else
	{
		return z;
	}
}

int min(int x, int y, int z)
{
	if ((x <= y) && (x <= z))
	{
		return x;
	}
	else if ((y <= x) && (y <= z))
	{
		return y;
	}
	else
	{
		return z;
	}
}

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cout << min(a, b, c) << " " << a + b + c - min(a, b, c) - max(a, b, c) << " " << max(a, b, c) << std::endl;
	return EXIT_SUCCESS;
}