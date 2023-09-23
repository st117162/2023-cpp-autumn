#include<iostream>

int main(int argc, char* argv[])
{
	int k = 0;
	int m = 0;
	int n = 0;
	int res = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	res = n / k * m * 2;
	if (n < k)
	{
		res = m * 2;
	}
	else if (n % k != 0)
	{
		if (k / 2 >= n % k)
		{
			res += m;
		}
		else
		{
			res += m * 2;
		}
	}
	std::cout << res << std::endl;
	return EXIT_SUCCESS;
}