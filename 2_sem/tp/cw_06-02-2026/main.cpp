
//Задача 1.1 Поиск
//Выполнить поиск в бинарном дереве поиска
//Все значения в дереве различны
template< class T>
struct BiTree{
  T val;
  BiTree<T>* lt, *rt;
};

template< class T, class Cmp >
const BiTree< T >* find( const T& d, const BiTree< T >* root, Cmp cmp)
{
  while (root)
  {
    if(cmp(d, root -> val))
    {
      root = root -> lt;
    }//ответ где-то слева
    else if (cmp(root-> val, d))//ответ где-то справа
    {
      root = root -> rt;
    }
    else
    {
      return root;
    }
  }
  return root;
}
//Поиск вохвращает null, а надо возвращать указатель на место, где должен быть резкльтат

//Задача 1.2  Поиск
//Выполнить поиск в тернарном дереве поиска
//Все значения в дереве различны
template< class T >
struct TriTree{
  T val1, val2;
  TriTree< T >* lt, *rt, *mid;
};//[lt] < val1 < [mid] < val2 < [rt] 

template< class T, class Cmp >
const TriTree< T >* find( const T& d, const TriTree< T >* root, Cmp cmp)
{
  while(root)
  {
    if(cmp{d, root -> val1})
    {
      root = root -> lt;
    }else if(cmp(d, root -> val2))
    {
      root = root -> mid;
    }else if(cmp(root->val1, d))
    {
      return {root, 0}
    }else if(cmp(d, root->val2))
    {
      root = root -> mid;
    }else if(!cmp(root->val2, d))
    {
      return {root, 1};
    }else
    {
      root = root -> rt;
    }
  }
  return {0, 3};
}

//Задача 2.1 Удаление(Рекурсивно)
//Освободить память, занимаемую бинарным деревом
template< class T>
struct BiTree{
  T val;
  BiTree<T>* lt, *rt;
};

template< class T, class Cmp >
void clear(BiTree< T >* root)
{

  if(!root){return;}
  clear(root->lt);
  clear(root->rt);
  delete root;
}

//Задача 2.2 Удаление(Рекурсивно)
//Освободить память, занимаемую тернарным деревом
template< class T>
struct BiTree{
  T val;
  BiTree<T>* lt, *rt;
};

template< class T, class Cmp >
void clear(BiTree< T >* root)
{

  if(!root){return;}
  clear(root->lt);
  clear(root->rt);
  clear(root->mid);
  delete root;
}