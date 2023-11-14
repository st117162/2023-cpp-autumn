#include<iostream>
#include<ctime>

void initRandomArray(int*& a, int len);
void printArray(int* a, int len);
void swap(int& a, int& b);
void mixArray(int* a, int len);
void BubbleSort(int* a, int len);
void InsertionSort(int* a, int len);
void SelectionSort(int* a, int len);
void CountSort(int* a, int len);
void GnomeSort(int* a, int len);
bool isSorted(int* a, int len);
void MonkeySort(int* a, int len);

int main(int argc, char* argv[])
{
	int n = 7;
	int* a = new int[n] { 0 };
	initRandomArray(a, n);
	printArray(a, n);
	CountSort(a, n);
	printArray(a, n);
	return EXIT_SUCCESS;
}

void initRandomArray(int*& a, int len)
{
	srand(time(0));
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 10;
	}
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void mixArray(int* a, int len)
{
	srand(time(0));
	for (int i = 0; i < len; ++i)
	{
		swap(a[i], a[rand() % len]);
	}
}

void BubbleSort(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}

void InsertionSort(int* a, int len)
{
	for (int i = 1; i < len; ++i)
	{
		int j = i;
		for (j; j > 0 && a[j] < a[j - 1]; --j)
		{
			swap(a[j], a[j - 1]);
		}
	}
}

void SelectionSort(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		int minInd = i;
		for (int j = i + 1; j < len; ++j)
		{
			minInd = (a[minInd] <= a[j] ? minInd : j);
		}
		swap(a[minInd], a[i]);
	}
}

void CountSort(int* a, int len)
{
	int lenc = 10;
	int* c = new int[lenc] { 0 };

	for (int i = 0; i < len; ++i)
	{
		++c[a[i]];
	}

	int b = 0;

	for (int j = 0; j < lenc; ++j)
	{
		for (int i = 0; i < c[j]; ++i)
		{
			a[b] = j;
			++b;
		}
	}
}

void GnomeSort(int* a, int len)
{
	int i = 1;
	int j = 2;
	while (i < len)
	{
		if (a[i - 1] < a[i])
		{
			i = j;
			++j;
		}
		else
		{
			swap(a[i], a[i - 1]);
			--i;
			if (i == 0)
			{
				i = j;
				++j;
			}
		}
	}
}

bool isSorted(int* a, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			return false;
		}
	}
	return true;
}

void MonkeySort(int* a, int len)
{
	while (!isSorted(a, len))
	{
		mixArray(a, len);
	}
}
