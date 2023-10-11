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

  for (int i = 0; i < n; ++i)
  {
    if (*(a + i) <= 0)
    {
      for (int j = i; j < n - 1; ++j)
      {
        *(a + j) = *(a + j + 1);
      }
      --n;
    }
  }

  int* b = (int*)malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i)
  {
    *(b + i) = *(a + i);
  }
  free(a);
  a = b;

  for (int i = 0; i < n; ++i)
  {
    std::cout << *(a + i) << " ";
  }
  std::cout << std::endl;
  free(a);
  return EXIT_SUCCESS;
}
