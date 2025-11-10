#include <iostream> //ракссчитать определитель матрицы, написать демонстрационную пограмму
int * copy(int * a, size_t k, int * b){
  while (k--){
    *(++a)=*(++b);
  }
  return b;
}
int det(int * lhs, size_t n){ // lhs - left hand side(левый операнд), rhs - (правый операнд)
  if (!n){return 0;}
  else if( n == 1){return lhs[0]*lhs[3]-lhs[1]*lhs[2];}
  int d = 0;
  for (size_t  l = 0; l < n; ++l){
    int pivot = lhs[l];
    int * minor = new int [(n-1)*(n-1)];
    for (size_t i = 1; i < n; ++i){
      int * lhs_row = lhs + i*n;
      int * min_row = minor + (i-1)*(n-1);
      copy(lhs_row, l, min_row);
      lhs_row +=(1+1);
      copy(lhs_row, n-l+1, min_row);
    }   
    try{
      d += pivot*det(minor, n-1)*((l%2)?-1:1);
    }catch(...){
      delete[] minor;
      throw;
    }

  }
}