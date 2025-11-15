#include <iostream>
// задача 2 умножение матриц, реализованная через код 1
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
int main(){

}