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
	free(*(a));
	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i);
	}
	std::cout << std::endl;
	free(a);
	return EXIT_SUCCESS;
}
