#include <iostream> //ракссчитать определитель матрицы, использя дополнительную память b. написать демонстрационную пограмму
int * copy(int * a, size_t k, int * b){
  while (k--){
    *(++a)=*(++b);
  }
  return b;
}
int det(int * b,  int * lhs, size_t n){ // lhs - left hand side(левый операнд), rhs - (правый операнд)
  int d = 0;
  for (size_t l = 0; l < n; ++l){
    int * minor = b;
    for (size_t i = 1; i < n; ++i){
       int * lhs_row = lhs + i*n;
      int * min_row = minor + (i-1)*(n-1);
      min_row = copy(lhs_row, l, min_row);
      lhs_row += (l+1);
      copy (lhs_row, n-(l+1), min_row);
    }
    int * next = b + (n-1)*(n-1);
    d += lhs[l]*det(next, minor, n-1)*(l%2?-1:1);
  }
  return d;
}