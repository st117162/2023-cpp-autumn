#include<iostream>
#include<algorithm>
#include"ProgramJob.h"

int main(int argc, char* argv[])
{
	int* a = nullptr;
	int len = 0;
	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			
		}

		int choice = 0;
		{
			std::cin >> choice;
		}

		{
			switch (choice)
			{
			case 0:
				exit = true;
				break;
			case 1:
				printArray(a, len);
				system("pause");
				break;
			case 2:
			{
				int element = 0;
				std::cout << "Input element to add: ";
				std::cin >> element;
				addElement(a, len, element);
				break;
			}
			case 3:
			{
				int index = 0;
				std::cout << "Input index to extract: ";
				std::cin >> index;
				std::cout << "Extracted " << extractElement(a, len, index) << std::endl;
				system("pause");
				break;
			}
			case 4:
				sortArray(a, len);
				break;
			case 5:
				reverseArray(a, len);
				break;
			case 6:
				swapArrayElements(a, maxArrayElement(a, len), minArrayElement(a, len));
				break;
			case 7:
				removeDuplicates(a, len);
				break;
			case 8:
			{
				int n = 0;
				std::cout << "Input number of elements: ";
				std::cin >> n;
				addRandomElements(a, len, n);
				break;
			}
			default:
				std::cout << "Unknown command" << std::endl;
				system("pause");
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}
