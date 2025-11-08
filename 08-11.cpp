#include <iostream>

int ** ct(size_t n, size_t m);

int* copy(const int * v, size_t k, int* w) //пернеосит из матрицы v в матицу w k символов строки. по сути просто объединяет строки
{
  for (size_t i = 0; i < k; ++i)
  {
    w[i]=v[i]; // ?? что делает w[i]=v[i], если w и v - указатели?
  }
  return w+k;
}

int ** concad_rows(const int* const * a, size_t n1, size_t m1, const int * const * b, size_t n2, size_t m2)
{
  size_t n = n1>n2?n2:n1;
  int ** c = ct(n, m1+m2);
  for (size_t i = 0; i<n; ++i)
  {
    const int * rowa = a[i];//const потому что на вход const, иначе ошибка
    const int * rowb = b[i];
    int * rowc = c[i];
    rowc = copy(rowa, m1, rowc);
    copy(rowb, m2, rowc);



  }
  return c;
}

int main()
{

}