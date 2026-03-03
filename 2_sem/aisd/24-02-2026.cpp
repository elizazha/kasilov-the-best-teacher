# include <iostream>
#include <cstddef>

//task 1
// template <class T>
// struct List {
//     T val;
//     List<T>* next;
// }

// template <class T>
// size_t size(const List <T>* h)
// {
//     size_t count = 0;
//     while(h)
//     {
//         ++count;
//         h = h->next;
//     }
//     return count;
// }

// templtae <class T>
// void clean(List<T>* h)
// {
//   while (h)
//   {
//     List<T>*n = h->next;
//     delete h;
//     h = n;
//   }
// }


//task 2
// templtae <class T>
// struct List{
//   T val; 
//   List <T>* next;
// }

// templtae <class T>
// size_t size(const List <T*> * h)
// {
//    size_t count = 0;
//     while(h)
//     {
//         count += h-> val;
//         h = h->next;
//     }
//     return count;
// }

// templtae <class T>
// void clean(List<T*>* h)
// {
//   while (h)
//   {
//     List <T*>* n = h->next;
//     delete h-> val;
//     delete h;
//     h = n;
//   }
// }


//task 3
// templtae <class T>
// struct List
// {
//   T val;
//   List<T>*next;
// }

// templtae <class T>
// size_t size(const List<const List <T>*>* h)
// {
//   size_t count = 0; 
//   while (h)44
//   {
//     count += size <T> (h->val);
//     h = h -> next;
//   }
//   return count;
// }

// templtae <class T>
// void clean(List<List<T>*>* h)
// {
//   while(h)
//   {
//     clear <T> (h->val); // <T> нужно чтобы подсказать компилятору что исп clear из Task 1
//     List<List<T>*>* n = h -> next;
//     delete h;
//     h = n;
//   }
// }

//task 4
// templtae <class T>
// struct List{
//   T  val; List <T>* next;
// }

// templtae <class T>
// struct Vec{
//   T* data; size_t size;
// }

// templtae <class T>
// sie_t size(Vec<const List <T>*> v)
// {
//   size_t count = 0;
//   for(size_t i = 0; i < v.size; ++i)
//   {
//     count += size <T> (v.data[i]);
//   }
//   return count;
// }

// templtae <class T>
// void clean(Vec< List< T >* > v)
// {
//   for (size_t i = 0; i < v.sze; ++i)
//   {
//     clear <T> (v.data[i]);
//   }
//   delete[] v.data
// }


 