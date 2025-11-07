#include <iostream>
int *extand(const int * a, size_t k, size_t d, int filler)
{
  int* new_array = new int[d];
  for (size_t i =0; i<std::min(k, d); i++)
  {
    new_array[i] = a[i];
  }
  for (size_t i =std::min(k, d); i< d; i++)
  {
    new_array[i] = filler;
  }
  return new_array;
}

int main()
{
  int array[5]={1, 2, 3, 4, 5};
  int* new_array = extand(array, 5, 3, 0);
  for (size_t i =0; i < 3; i++)
  {
    std::cout<<new_array[i];
  }
  
  
}