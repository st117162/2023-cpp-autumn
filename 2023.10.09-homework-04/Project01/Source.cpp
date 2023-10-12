#include<iostream>
#include<cstdlib>

int main(int, char**)
{
	int res = 0;
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	for (int i = 0; i < n; ++i)
	{
		if (*(a + i) > 0)
		{
			res += 1;
		}
	}
	std::cout << res << std::endl;
	free(a);

	return EXIT_SUCCESS;
}
