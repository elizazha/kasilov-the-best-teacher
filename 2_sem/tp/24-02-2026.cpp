# include <iostream>
#include <cstddef>

//task 1
// template <class T>
// struct Vec
// {
//   T* data;
//   size_t s;
// };

// template <class T>
// struct VexIt // vector iterator
// {
//   T* data;

//   size_t s, i; //s - size of massive, i - current iterator // if without "i" - size_t s;
// };

// template <class T>
// VecIt<T> begin(Vec <T> v)
// {
//   return {v.data, v.s, 0}; //  return {v.data, v.s};
// }

// template <class T>
// bool HasNext(VecIt<T> it)
// {
//   return it.s != it.i; // return it.s;
// }

// template <class T>
// VecIt<T> next(VecIt<T> it)
// {
//   it.i++; // it.data++; it.s--;
//   return it; // копия итератора по значению
// }

// template <class T>
// T& value(VecIt<T> it)
// {
//   return it.data[it.i]; // return *(it.data);
// }

// template<class T>
// VecIt<T> end(Vec<T> v)
// {
//   return {v.data+v.s, 0};
// }



//task 2
template <class T>
struct Vec
{
  T* data;
  size_t s;
};

template <class T>
struct Vec RIt //Reversed Iterator
{
  T* data;
  size_t s, i;
}

//здесь нам надо получать указатель на эоемент до [0], так делать нельзя, будме искать выход

template <class T>
Vec RIt<T> rbegin(Vec <T> v)
{
  return {v.data, v.s, v.s}
}

template <class T>
T& value(vec RIt<T> it)
{
    return it.data[it.i - 1];
}

template <class T>
bool hasPrev(Vec RIt <T> it) // has previous
{
    return it.i; // while i > 0
}

template <class T>
Vec RIt<T> prev(Vec RIt<T> it)
{
    it.i--;
    return it;
}

// auto it = begin(...);\
// for (;hasPrev(it);it=prev(it))
// {
//     auto& v = value(it);
//     ...
// }6