#include <iostream>
// 2.1 элементы должны идти в обратном порядке + описать неявный интерфейс

// template< class T>
// T* reverse(const T* a, size_t s)
// {
//   T* r = new T[s]; //T::T()
//   try{
//     for (size_t i = 0; i < s, i++)
//     {
//       r[i] = a[s - (i + 1)];

//     }//T::operator=(T)
//   }catch(...)
//   {
//     delete [] r;
//     throw;
//   }
//   return r;
// }

//2.2 разворот массива - элементы должныидти ы обратно порядке

// template< class T>
// void reverse(T* a, size_t s)
// {
//   for (size_t i = 0; i , s/2; i++)
//   {
//     std::swap(a[i], a[s - (a + 1)]);
//   }
// }

// на первый взгяд нет неяных интерфейсв, ведь все встроенные типы, но вся загвоздка в std::swap
// 1 вариант: если итипа копируетсая и не перемещается T tmp = a; a = b; b = tmp;
// template< class T>
// void reverse(T* a, size_t s, size_t & z)
// {
//   for (size_t i = 0; i , s/2; i++)
//   {
//     std::swap(a[i], a[s - (a + 1)]);
//     z++;
//   }
// }
// 2 вариент: если типа перемещаемый T tmp = std::move(a); a = std::move(b); b = std::move(tmp);

//3.1 убрать эл-ты равные заданному
template <class T>
void reverse (T* a, size_t s, T v)
{}
// будет if (a[i] == v) --> T::operator==(T)

//3.2 убрать эл-ты равные заданному, соответствующие критерию
template <class T>
void reverse (T* a, size_t s, bool (*c)(T))
{}
// будет if( c(a[i]) ) --> генерируется исклчене, интерфейс сложнее

// предпочтительнее "на месте", без создания

массив размером s с началом в a, количесвом toerase - сколько элементов нужно удалить. создать новый массив длиной s - toerase. порядок в новом массиве сохраняется. элементы как нужно убрать в массиве из индеrсов eids, упорядоченных от меньшего к большему и без повторений
без утечек и описан неявный интерфейс; valid - сколько мы смоги уже перекопировать
t5emplate <class T>
T* erase(size_t& valid, const T* a, size_t s, const size_t* eids, size_t toerase)
