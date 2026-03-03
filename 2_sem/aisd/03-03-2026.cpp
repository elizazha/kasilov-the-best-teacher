
//TASK 1.1


#include <iostream>
#include <cstddef>
#include <new>

template<class T>
struct List{
  T val;
  List<T>* next;
};

template<class T>
struct Vec{
  T* data;
  size_t s;
};

template<class T>
void clear(List< Vec< T>>* h)
{
  while(h)
  {
    delete[] h->val.data;
    List< Vec< T >>* temp = h;
    h = h->next;
    delete temp;
  }
}

template<class T>
Vec<T> copy(const List< Vec< T>>& v)
{
  Vec<T> new_v;
  new_v.data = nullptr;
  try
  {
    new_v.data = new T[v.s];
    for(size_t i = 0; i < v.s; i++)
    {
      new_v.data[i] = v.data[i];
    }
    new_v.s = v.s;
  }catch(...)
  {
    delete[] new_v.data;
    throw;
  }
  return new_v;
}

template<class T>
List< Vec< T >>* copy(const List< Vec< T>>* h)
{
  if (!h)
  {
    return nullptr;
  }
  List< Vec< T >>* head = new List< Vec< T >>{copy(h->val), nullptr};
  try
  {
    List< Vec< T >>* node = head;
    while(h->next)
    {
      node->next = new List<Vec<T>>{copy(h->next->val), nullptr}
      h = h->next;
      node = node->next;
    }
  }catch(const std::bad_alloc &)
  {
    clear(head);
    throw;
  }
  return head;
}

template<class T>
List<T>* next(List<T>* node)
{
  return node->next;
}

template<class T>
bool hasNext(List<T>* node)
{
  return node->next != nullptr;
}


//TASK 1.2
//базовая гарантия

#include <iostream>
#include <cstddef>
#include <new>

template<class T>
struct List{
  T val;
  List<T>* next;
};

template<class T>
struct Vec{
  T* data;
  size_t s, cap;//объем выделенных элементов
};

template<class T>
void copy(List<Vec<T>>* h, List<Vec<T>>** r);


