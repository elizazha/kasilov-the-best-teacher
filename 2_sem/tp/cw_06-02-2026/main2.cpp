//Задача 1.1
//обход бинарного дерева по возрастанию
template< class T>
struct BiTree{
  T val;
  BiTree<T>* lt, *rt, *parent;
};

BiTree< T >* minimum(BiTree< T >* root)
{
  if (!root)
  {
    return root;
  }
  while(root -> lt)
  {
    root = root -> lt;
  }
  rerutn root;
}

BiTree< T >* maximum(BiTree< T >* root)
{
  if (!root)
  {
    return root;
  }
  while(root -> rt)
  {
    root = root -> rt;
  }
  rerutn root;
}

template< class T, class F >
F traverse(BiTree< T >* root, F f)
{
  if( !root)
  {
    return f;
  }
  BiTree< T >* next = minimum(root);
  while(next)
  {
    f(next -> val);
    if (next -> rt)
    {
      next = next -> rt;
      next = minimum(next);
    }else
    {
      BiTree< T >* parent = next -> parent;
      while(parent && parent -> lt != next)
      {
        next = parent;
        parent = next -> parent;
      }
      next = parent;
    }
  }
  return f;
}
//Задачу 1.2 пропускаем (обход бинарного дерева по убыванию)

//Задача 1.3 
// Двуунаправленные итераторы бинарного дерева, обход по возрастанию
template< class T>
struct BiTree{
  T val;
  BiTree<T>* lt, *rt, *parent;
};
template< class T>
struct BiTreeIt
{
  BiTree< T >* curr;
}
template < class T >
T& value(BiTreeIt < T > it)
{
  return it.curr -> val;
}
template < class T >
BiTreeIt < T > next(BiTreeIt< T > it)
{
  Bitree< T >* next = curr.val;
  if (next -> rt)
  {
    next = next -> rt;
    next = minimum(next);
  }else
  {
    BiTree< T >* parent = next -> parent;
    while(parent && parent -> lt != next)
    {
      next = parent;
      parent = next -> parent;
    }
    next = parent;
  }
  return {next};
}
template < class T >
BiTreeIt < T > prev(BiTreeIt< T > it)
{
  Bitree< T >* next = curr.val;
  if (next -> lt)
  {
    next = next -> lt;
    next = maximum(next);
  }else
  {
    BiTree< T >* parent = next -> parent;
    while(parent && parent -> rt != next)
    {
      next = parent;
      parent = next -> parent;
    }
    next = parent;
  }
  return {next};
}
template < class T >
bool hasNext(BiTreeIt< T > it)
{
  return next(it).curr;
}
template < class T >
bool hasPrev(BiTreeIt< T > it)
{
  return prev(it).curr;
}

//Задача 2.1
// Двуунаправленные итераторы тернарного дерева, обход по возрастанию
template< class T >
struct TriTree{
  T val1, val2;
  TriTree< T >* lt, *rt, *mid, *parent;
};//[lt] < val1 < [mid] < val2 < [rt]

template< class T >
struct TriTreeIt
{
  size_t s;//обозначает на каком жлементе мы стоим (val0 или val1)
  TriTree< T >* curr;
}
template< class T >
T& value(TriTreeIt < T > it)
{
  if (s==0)
  {
    return it.curr -> val0;
  }
  return it.curfr -> val1;
}

template< class T >
TriTree< T >* maximum(TriTree< T >* root)
{
  if (!root)
  {
    return root;
  }
  while(root -> rt)
  {
    root = root -> rt;
  }
  rerutn root;
}

template< class T >
TriTree< T >* minimum(TriTree< T >* root)
{
  if (!root)
  {
    return root;
  }
  while(root -> lt)
  {
    root = root -> lt;
  }
  rerutn root;
}

template< class T >
TriTreeIt< T > next(TriTreeIt < T > it)
{
  TriTree< T >* next = it.curr;
  size_t ind = it.s;
  if (!next)
  {
    return it;
  }
  if (ind == 0)
  {
    if (next -> mid)
    {
      next = next -> mid;
      next = minimum(next);
      ind = 0;
    }else
    {
      ind = 1;
    }
  }else
  {
    if (next -> rt)
    {
      next = next -> rt;
      next = minimum(next);
      ind = 0;
    }else
    {
      TriTreeIt < T >* parent = next -> parent;
      while (parent)
      {
        if (parent -> lt == next)
        {
          ind = 0;
          break;
        }
        if(parent -> mid == next)
        {
          ind = 1;
          break
        }
        next = parent;
        parent = next -> parent;
      }
      next = parent;
    }
  }
  return {ind, next};
}
template< class T >
TriTreeIt< T > prev(TriTreeIt < T > it)
{
  TriTree< T >* next = it.curr;
  size_t ind = it.s;
  if (!next)
  {
    return it;
  }
  if (ind == 1)
  {
    if (next -> mid)
    {
      next = next -> mid;
      next = maximum(next);
      ind = 1;
    }else
    {
      ind = 0;
    }
  }else
  {
    if (next -> lt)
    {
      next = next -> rt;
      next = maximum(next);
      ind = 1;
    }else
    {
      TriTreeIt < T >* parent = next -> parent;
      while (parent)
      {
        if (parent -> rt == next)
        {
          ind = 1;
          break;
        }
        if(parent -> mid == next)
        {
          ind = 0;
          break
        }
        next = parent;
        parent = next -> parent;
      }
      next = parent;
    }
  }
  return {ind, next};
}
template< class T >
bool hasNext(TriTreeIt < T > it)
{
  return next(it).curr;
}
template< class T >
bool hasPrev(TriTreeIt < T > it)
{
  return prev(it).curr;
}

main()
{
  TriTreeIt< int >* root = new TriTree< int > {1, 2, nullptr, nullptr, nullptr, nullptr};
  TriTreeIt< int > it{};
  while (hasNext(it))
  {
    std::cout << value(it);
    it = next(it);
  }
  delete root;
}