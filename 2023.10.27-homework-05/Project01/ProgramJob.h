#pragma once
#include<iostream>

void printMenu();
void printArray(int* a, int len);
void expandArray(int*& a, int& len);
void addElement(int*& a, int& len, int element);
bool indexValid(int index, int len);
void contractArray(int*& a, int& len);
int extractElement(int*& a, int& len, int index);
void sortArray(int*& a, int len);
void reverseArray(int*& a, int len);
int maxArrayElement(int* a, int len);
int minArrayElement(int* a, int len);
void swapArrayElements(int*& a, int indexA, int indexB);
void removeDuplicates(int*& a, int& len);
void addRandomElements(int*& a, int& len, int n);