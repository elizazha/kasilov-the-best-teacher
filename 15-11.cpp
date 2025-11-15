#include <iostream>
//задача 3. сумма из произведений последовательност матриц чна заданную
void mul(int *c, const int * a, size_t n1, size_t m1,  const int * b, size_t m2){
  for (size_t i = 0; i < n1; i++){ // перебор по стобцам, i - столебц
    for (size_t j = 0; j < m2; j++){ // перебор по строкам, j - строка
      // идем по j-тому столбцу и одновремнно в другой матрицы идем по i-той строке
      // с[i][j]=?? надо пиисвоить, что мы там посчитали
      int res = 0;
      const int * rowa = a + i*m1; 
      const int * colb = b+j;
      for (size_t l = 0; l < m1; ++l){
        int rowa_l = rowa[l];
        int colb_l = colb[l*m2];
        res += rowa_l*colb_l;

      }
      int * rowc = c + i*m2;
      rowc[j]=res;
    }
  }
}
void add(size_t n, size_t m, int * a, const int * b){}
void sum_of_mul(size_t n, int *c, const int * a, const int * const * b, size_t s){
  int *sums = new int [n * n];
  for (int i = 0; i < n*n; i++){sums[i]=0;}
  for (int b1 = 0; b1 < s; b1++){
    add (n, n, sums, b[b1]);
  }
  mul(c, sums, n, n, a, n);
  delete [] sums;
}

int * sum(size_t n, const int *a, const int *const *b, size_t s){
  int *result = new int [n*n];
  sum_of_mul(n, result, a, b, s);
  delete[] result;
}

//задача 3. произведение из произведений последовательност матриц чна заданную
void mul_of_mul1(size_t n, int *c, const int * a, const int * const * b, size_t s){
  int *temp = new int[n * n];
  mul(c, b[0], n, n, a, n);
  for (size_t i = 1; i < s; i++){
    mul(temp, b[i], n, n, a, n);
    mul(c, c, n, n, temp, n);

  }
  delete [] temp;
}
int *mul_of_mul2(size_t n, const int *a, const int *const *b, size_t s) {
    int *result = new int[n * n];
    mul_of_mul1(n, result, a, b, s);
    return result;
}


