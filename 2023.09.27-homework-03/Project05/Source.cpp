#include<iostream>
int palind(int x)
{
	int res = 0;
	for (int i = x; i > 0; i /= 10)
	{
		res = res * 10 + i % 10;
	}
	if (res == x)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(int argc, char* argv[])
{
	int k = 0;
	int res = 0;
	std::cin >> k;
	for (int i = 1; i <= k; ++i)
	{
		if (palind(i))
		{
			++res;
		}
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}