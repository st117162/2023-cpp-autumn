#include<iostream>

int main(int argc, char* argv[])
{
	int n = 0;
	int one = 0;
	int five = 0;
	int ten = 0;
	int twenty = 0;
	int sixty = 0;
	std::cin >> n;
	sixty = n / 60;
	n %= 60;
	twenty = n / 20;
	n %= 20;
	ten = n / 10;
	n %= 10;
	five = n / 5;
	n %= 5;
	one = n;
	std::cout << one << " " << five << " " << ten << " " << twenty << " " << sixty << std::endl;
	return EXIT_SUCCESS; //я знать, что код не работать, но моя не понимать, как это заботать :(
}