#include "ProgramJob.h"
#include<ctime>

void printMenu()
{
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Print array" << std::endl;
	std::cout << "2 - Append element to array" << std::endl;
	std::cout << "3 - Extract element from array" << std::endl;
	std::cout << "4 - Sort elements of array" << std::endl;
	std::cout << "5 - Reverse array" << std::endl;
	std::cout << "6 - Swap min and max" << std::endl;
	std::cout << "7 - Remove duplicates from array" << std::endl;
	std::cout << "8 - Append n elements to array" << std::endl;
}
void printArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY" << std::endl;

	}
	else
	{
		std::cout << "{ ";
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[i] << " ";
		}
		std::cout << "}" << std::endl;
	}
}
void expandArray(int*& a, int& len)
{
	int* newA = new int[len + 1] { 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
	}
	a = newA;
	++len;
}
void addElement(int*& a, int& len, int element)
{
	expandArray(a, len);
	a[len - 1] = element;
}
bool indexValid(int index, int len)
{
	return (index >= 0 && index < len);
}
void contractArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		if (len == 1)
		{
			delete[] a;
			a = nullptr;
			--len;
		}
		else
		{
			int* newA = new int[len - 1];
			for (int i = 0; i < len - 1; ++i)
			{
				newA[i] = a[i];
			}
			delete[] a;
			a = newA;
			--len;
		}
	}
}
int extractElement(int*& a, int& len, int index)
{
	int res = -1;
	if (indexValid(index, len))
	{
		res = a[index];
		for (int i = index; i < len - 1; ++i)
		{
			a[i] = a[i + 1];
		}
		contractArray(a, len);
	}
	return res;
}
void sortArray(int*& a, int len)
{
	if (a != nullptr)
	{
		for (int i = 1; i < len; ++i)
		{
			for (int j = 0; j < len - i; ++j)
			{
				if (a[j] > a[j + 1])
				{
					int aa = a[j];
					a[j] = a[j + 1];
					a[j + 1] = aa;
				}
			}
		}
	}
}
void reverseArray(int*& a, int len)
{
	if (a != nullptr)
	{
		int* newA = new int[len];
		for (int i = 0; i < len; ++i)
		{
			newA[i] = a[len - 1 - i];
		}
		delete[] a;
		a = newA;
	}
}
int maxArrayElement(int* a, int len)
{
	if (a != nullptr)
	{
		int maxi = a[0];
		int index = 0;
		for (int i = 0; i < len; ++i)
		{
			if (a[i] > maxi)
			{
				maxi = a[i];
				index = i;
			}
		}
		return index;
	}
}
int minArrayElement(int* a, int len)
{
	if (a != nullptr)
	{
		int mini = a[0];
		int index = 0;
		for (int i = 0; i < len; ++i)
		{
			if (a[i] <= mini)
			{
				mini = a[i];
				index = i;
			}
		}
		return index;
	}
}
void swapArrayElements(int*& a, int indexA, int indexB)
{
	if (a != nullptr)
	{
		int aa = a[indexA];
		int bb = a[indexB];
		a[indexA] = bb;
		a[indexB] = aa;
	}
}
void removeDuplicates(int*& a, int& len)
{
	if (a != nullptr)
	{
		for (int i = 0; i < len - 1; ++i)
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (a[i] == a[j])
				{
					extractElement(a, len, j);
					--j;
				}
			}
		}
	}
}
void addRandomElements(int*& a, int& len, int n)
{
	int* newA = new int[len + n];
	for (int i = 0; i < len; ++i)
	{
		newA[i] = a[i];
	}
	srand(time(0));
	for (int i = len; i < len + n; ++i)
	{
		newA[i] = rand() % 10;
	}
	delete[] a;
	a = newA;
	len += n;
}