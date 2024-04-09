#include<iostream>

int n[4]{ 0 };
int** d = new int* [4] {nullptr, new int[10], new int[10], new int[10]};

void shift(int from = 1, int to = 3);

void hanoi(int n, int from = 1, int to = 3);

void sort();

int main(int argc, char* argv[])
{
	std::cin >> n[1];
	for (int i = n[1] - 1; i >= 0; --i)
	{
		std::cin >> d[1][i];
	}
	sort();
	return EXIT_SUCCESS;
}

void shift(int from = 1, int to = 3)
{
	std::cout << d[from][n[from] - 1] << " " << from << " " << to << std::endl;
	--n[from];
	d[to][n[to]] = d[from][n[from]];
	n[to]++;
}

void hanoi(int n, int from = 1, int to = 3)
{
	if (n == 0)
	{
		return;
	}

	int res = 6 - from - to;

	hanoi(n - 1, from, res);
	shift(from, to); //std::cout << count << " " << from << " " << to << std::endl;
	hanoi(n - 1, res, to);
}
