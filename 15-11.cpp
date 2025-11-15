#include <iostream>

// int * sum(size_t n, size_t m, const int * a, const int * b){  // задача 1. Код 2
//   int * r = new int[m*n];
//   sum(n, m, r, a, b); // в r(result) скалдываем a и b
//   return r;
// }

// void * sum(size_t n, size_t m, int * c, const int * a, const int * b){
//   for (size_t i =0; i < m*n; i++){
//       c[i]=a[i]+b[i];
//     }
// } // задача 1. Код 1

// void add(size_t n, size_t m){ // - задача 1. Код 3
//   sum(n, m, a, a, d) // a - куда запис рез( по сути с, но *а и *с указ на одно и то же место); а, b - то, что надо сложить
// }
// через код 2 нельзя реальзоват две остальные, так как этот метод не выделяет память внутри функции. нам самим
// придется выделить память. то есть будут исключения, что может => проблемы
int main(){

}