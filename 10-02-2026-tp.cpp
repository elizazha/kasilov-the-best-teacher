#include <iostream>
#include <algorithm>

void reverse(int* a, size_t s)
{
  for (size_t i = 0; i < (s / 2); i++)
  {
    std::swap(a[i], a[s - 1]);
    s--;
  }
}

int* partition(int* a, size_t s, bool(*c)(int)){}

void quad_partition(int* a, size_t s, bool(*c1)(int), bool(*c2)(int), int** pts)
{
  int* y1 = partition(a, s, c1);
  int* y2 = partition(a, y1 - a, c2);
  int* y3 = partition(a, sy1, a + s - y1, c2);
  pts[0] = y2;
  pts[1] = y1;
  pts[2] = y3;

}

int* unique(int* a, size_t s)
{
  size_t j = 0;
  for (size_t i = 0; i < s; i++)
  {
    if (a[j] != a[i])
    {
      a[j + 1] = a[i];
      j++;
    }
  }
  return a + j + 1;
}

int* merge(const int* a, size_t sa, const int* b, size_t sb, int* c)
{
  sized_t ia = 0, ib = 0, ic = 0;
  while (ia < sa && ib < sb)
  {
    if (a[ia] < b[ib])
    {
      c[ic] = a[ia ++];
    }else
    {
      c[ic] = b[ib++];
    }
    ++ic;
    int* max_arr = sa > sb ? a : b;
    size_t max_size = sa > sb ? sa : sb;
    size_t ig = sa > sb ? ia : ib;
    for (size_t i = ig, i < max.max_size; ++i)
    {
      c[ic++] = max_arr[i];
    }assert(sa + sb == ic);
    returnc + sa + sb;
  }
  for (size_t i = 0; i < sa && i < sb; i++)
  {

  }
}

int main()
{
  int a[] = {1, 2, 3, 4, 5};
  reverse(a, 5);
  for (size_t i = 0; i < 5; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
