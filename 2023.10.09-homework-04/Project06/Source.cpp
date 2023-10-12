#include<iostream>
#include<cstdlib>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	int max = *(a);
	int* x = a;
	for (int i = 0; i < n; ++i)
	{
		if (max <= *(a + i))
		{
			max = *(a + i);
			x = (a + i);
		}
	}

	int min = *(a);
	int* y = a;
	for (int i = 0; i < n; ++i)
	{
		if (min > *(a + i))
		{
			min = *(a + i);
			y = (a + i);
		}
	}

	*x = min;
	*y = max;
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}
	std::cout << std::endl;
	free(a);

	return EXIT_SUCCESS;
}
