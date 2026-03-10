#include <iostream>
//1.1 включен ли один двусвязный список в другой?
//принадлежность двух узлов к одному списку
template<class T>
struct List
{
  T* val;
  List<T>* next, prev;
};
template<class T>
bool has_common(const List<T>* h1, const List<T>* h2)
{
  const List<T>* head = h1;
  while(head -> prev)
  {
    head = head -> prev;
  }
  while(head)
  {
    if(head == h2)
    {
      return true;
    }
    head = head -> next
  }
  return false
}
//проверить что указанные списки не имеют общие элементы
template<class T>
struct List
{
  T* val;
  List<T>* next, *prev;
};
template<class T>
bool no_common(const List<const List<T>*>* h)
{
  auto head = h;
  const List<T>* curr = nullptr;//auto берет типа справа от =. у нас справа стоит nullptr, поэтому не факт, что будет правильрный тип( может вкатить void*)
  while(head)
  {
    if(has_common(head->>val, curr->val))
    {
      return false;
    }else{
      curr = curr -> next;
    }
    head = head -> next;
  }
  return true;
}

//в списке с доп.связями проверить, что все доп.сявзи укладывают в тот же список или не ссылаются никуда вовсе
template<class T>
struct MList
{
  T val;
  MList<T>* next, *prev, *ref;
};

template<class T>
bool has_common(MList<T>* a, MList<T>* b)
{
  auto head = a;
  while(head->prev)
  {
    head = head -> prev;
  }
  while(head)
  {
    if(head == b)
    {
      return true;
    }
    head = head -> next;
  }
  return false;
}

template<class T>
bool self_refed(MList<T>* h)
{
  auto head = h;
  while(head)
  {
//    if(!head->val || has_common(List<T> a{h->val, nullptr}, List<T> b{h->val, nullptr}))
    if(!head->val || !has_common(head, head -> prev))
    {
      return false; 
    }
    head = head -> next;
  }
  return true;
}

//hardcore ex
// в списке с доп.связями найти узлы, в которые нет доп.ссылок в других узлах: вернуть список из таких узлов
template<class T>
struct List
{
  T val;
  List<T>* next, *prev;
};

template<class T>
struct MList
{
  T val; 
  MList<T>* next, *prev, *ref;
};

template<class T>
bool has_ref(MList<T>* list, MList<T>* node)
{
  while(list)
  {
    if(list->ref == node)
    {
      returnn true;
    }
    list = list -> next;
  }
  return false;
}

template<class T>
List<const MList <T>* >* no_refs(const MList<T>* h)
{
  List<const MList<T>*> dummy_head{nullptr, nullptr, nullptr};
  List<const MList<T>* tail = &dummy_head;
  List<const MList<T>* prev = nullptr;
  MList<T>* inner = h;
  while(inner)
  {
    if(!has_ref(h, inner))
    {
      try{
        tail->next = new List<const MList<T>*{inner, nullptr, prev};
        tail = tail -> next;
        prev = tail;
      }catch(...)
      {
        while(tail -> prev) // or while(dummy_head != tail)
        {
          auto tmp = tail->prev;
          delete tail;
          tail = tmp;
          throw;
        }
      }
    }
    inner = inner -> next;
  }
  return dummy_head -> next;
}