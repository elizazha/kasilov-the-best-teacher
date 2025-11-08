#include <iostream>

size_t detsize(size_t n1, size_t m1, size_t n2, size_t m2, size_t i) // дает длину строки
{
  size_t minn = n1>n2?n2:n1;
  if (i < minn)
  {
    return m1+m2;
  }
  // if (n1>n2)
  // {
  //   return  m1;
  // }
  // else
  // {
  //   return m2;
  // }
  return n1<n2?m2:m1;
}


void rm(int ** a, size_t k)//как понять, когда стаит *, а когда **?
{
  for (size_t i = 0; i<k; ++i)
  {
    delete[]a[i];
  }
  delete[]a;
}

int ** ct(size_t n1, size_t m1, size_t n2, size_t m2)
{
  size_t n = n1>n2?n1:n2;    //если n1>n2, возвр n1, иначе n2...?
  int ** c = new int* [n];   //создаем массив массивов, почему начала **, потом *? 
  size_t i = 0;
  try
  {
    for (i; i<n; ++i)
    {
      size_t m = detsize(n1, n2, m1, m2, i);   //?
      c[i] = new int[m]; // почему без ** и *?
    }
  }catch(...){
    rm(c, i);
  }throw;
  return c;
}


