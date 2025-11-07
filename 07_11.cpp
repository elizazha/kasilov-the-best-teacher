#include <iostream>

int* extand(const int *a, size_t k, size_t d, int filler);
int *add_row(const int * a, size_t n, size_t m, int filler)
{
  return extand(a, n*m, (n+1)*m, filler);
}
void extand(int **ptr_a, size_t k, size_t d, int filler)
{
  int *new_array = extand(*ptr_a, k, d, filler);
  delete[] *ptr_a; //удаляем, чтобы не было утечки памяти при перезаписывании, поэтому g++
  *ptr_a = new_array; // удаляем старый и перезаписываем новый
}

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
  int *array = new int[4]{1, 2, 3, 4};
  int* new_matrix = add_row(array, 2, 2, 0);
  for (size_t i = 0; i < 3; i++)
  {
    for (size_t j = 0; i < 2; j++)
    {
      std::cout <<array[i*2+j]<<" ";
    }
    std::cout<<'\n';
  }
  std::cout<<'\n';
}
/* 4 programm
#include <iostream>

int* extand(const int *a, size_t k, size_t d, int filler);

int *add_col(const int *a, size_t n, size_t m, int filler)
{
  int *new_array = new int[n * (m+1)];
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      new_array[i*(m+1)+j]=a[i*m+j];
    }
    new_array[i *(m+1)+m] = filler;
  }
  return new_array;
}

//[0, 1]
//[2, 3] n = 2, m =2 
//[0, 1, _]
//[2, 3, _] n = 2, m = 3





int *add_row(const int * a, size_t n, size_t m, int filler)
{
  return extand(a, n*m, (n+1)*m, filler);
}
void extand(int **ptr_a, size_t k, size_t d, int filler)
{
  int *new_array = extand(*ptr_a, k, d, filler);
  delete[] *ptr_a; //удаляем, чтобы не было утечки памяти при перезаписывании, поэтому g++
  *ptr_a = new_array; // удаляем старый и перезаписываем новый
}
8*/
