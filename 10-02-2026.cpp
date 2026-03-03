#include <iostream>
#include <cstdlib>
int* insert(const int* a, size_t s, size_t i, size_t v)
{
  int* a_new = new int[s+1];
  for (size_t j = 0; j < s+1, j++)
  {
    if (j < i)
    {
      a_new[j] = a[j];
    }
    else if( j == i)
    {
      a_new[j] = v;
    }
    else
    {
      a-new[j] = a[j - 1];
    }
  }
  return a_new;
}

void insert(int** a, size_t s, size_t i, size_t v)
{
  int* a_new = insert(*a, s, i, v);
  delete[] (*a);
  (*a) = new_a;
}

int* remove (int* a, size_t s, size_t i)
{
  int v = a[i];
  for(size_t k = i; k < s - 1; k++)
  {
    a[k] = a[k + 1]; //a[k] = std::move(a[k + 1])
  }
  a[s - 1] = v;
  return a + s - 1;
}

int* cut(const int* a, size_t s)
{}

int* remove(int* a, size_t s, int v)
{
  for (size_t i = 0; i < s; i++)
  {
    if (a[i] == v)
    {
      remove(a, s, i);
      --s;
      --k;
    }
  }
  return a + s;
}

int* cut(const int* a, size_t s)=

{
  int* t = new int(s);
  for5 (size_t i = 0; i < s;i++)
  {
    t[i] = a[i];
  }
  return t;
}

size_t erase(int** a, size_t s, int v)
{
  size_t upd = remove(*a, s, v) - *a;
  int* t = cut(*a, upd)
  delete [] (*a);
  *a = t;
  return upd;
}
