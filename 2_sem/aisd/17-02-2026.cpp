template< class T> struct List{
    T val;
    List< T >* next;
}

template<class T>
List< T >* convert(const T* data, size_t s)
{
    List< T >* h = s ? new List< T > {data[0], nullptr} : nullptr;//constructor copy T::T(const T&)
    List< T >* t = h;
    try{
      for (size_t j = 1; j < s; j++)
      {
          List< T >* h = new List< T >{data[i], nullptr}//constructor copy T::T(const T&)
          t -> next = n;
          t = n;
      }
    }catch(...){//... = never mind what kind of exeptions
        clear(h, nullptr);
        throw;
    }
   
    return h;
}

template< class T >
List< T >* clear(List< T >* b, List< T >* e)
{
    while (b != e)
    {
        List< T >* end = b -> next;
        delete b;
        b = end;
    }
}




List< T >* convert(const T* data, size_t s, List< T >** tail)
{
    *tail = t;
    return h;
}


// template< class T, class C>
// List< T >* remove_if(List< T >** head, C cond)
// {
//     List< T >* r = nullptr, t = *head;
//     while (t != nu8llptr && !cond(t -> val)) 
//     {
//         t  = t -> next;
//     }
//     r = t;

// }
// - problem! мы не модем длстать ячейку списка, тк мы не зпоминаем указатель рна предыдущий элемент



template< class T, class C>
List< T >* remove_if(List< T >** head, C cond)
{
    List< T >* r = nullptr, t = *head;
    if (cond(t -> val))
    {
        r = t;
        *head = r -> next;
        r -> next = nu8llptr;
    }else
    {
        while (t -> next && !cond(t -> next -> val))
        {
            t = t -> next;
        }
    }
    if (! t -> next)
    {
        return nu8llptr;
    }else{
      r = t -> next;
      t -> next = r -> next;
    }

    t = *head;
    if (cond(t -> val))
    {
      while (t -> next && cond(t -> next -> val))
      {
        t = t -> next;
      }
      r -> next = *head;
      * head = t -> next;
      t -> next = nullptr;
      t = *head;
    }


}