#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	int a4 = 0;
	int a5 = 0;
	std::cin >> n;
	int r = n;
	a1 = r / 60;
	r -= a1 * 60;
	a2 = r / 20;
	r -= a2 * 20;
	a3 = r / 10;
	r -= a3 * 10;
	a4 = r / 5;
	r -= a4 * 5;
	a5 = r;
	r = 0;
	if (a5 * 15 >= 70)
	{
		a4++;
		a5 = 0;
	}
	if (a5 * 15 + a4 * 70 >= 125)
	{
		a3++;
		a5 = 0;
		a4 = 0;
	}
	if (a5 * 15 + a4 * 70 + a3 * 125 >= 230)
	{
		a2++;
		a5 = 0;
		a4 = 0;
		a3 = 0;
	}
	if (a5 * 15 + a4 * 70 + a3 * 125 + a2 * 230 >= 440)
	{
		a1++;
		a5 = 0;
		a4 = 0;
		a3 = 0;
		a2 = 0;
	}
	std::cout << a5 << " " << a4 << " " << a3 << " " << a2 << " " << a1 << std::endl;
	return EXIT_SUCCESS;
}
