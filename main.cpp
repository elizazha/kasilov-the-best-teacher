#include <iostream>
int ** create( size_t rows, size_cols)
{
  int ** mtx = new int * [rows];
  try
  {
    for (sizw_t i = 0; i < rows; ++i)
    {
      mtx[i]=new int(cols);
    }
  }
  catch(const std::bad_alloc&e}
  {
    #include <iostream>
//хотим создать двумерый массив. в нашем слуаче 5х5
void destroy(int** mtx, size_t created)
{
    for (size_t i = 0; i < created; i++)
    {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int ** create(size_t rows, size_t cols)
{
    int** mtx = new int * [rows];
    size_t created = 0; //счетчик чтобы посмотреть сколько массивров внутри массива успело выделиться
    try
    {
        for (; created < rows;++created) //(size_t i = 0; i < rows; ++i)
        {
            mtx[created] = new int(cols);
        }
    }
    catch (const std::bad_alloc& e)
    {
        destroy(mtx, created);
        throw;//return nullptr;
    }
    return mtx;
}

int main()
{
    int** matrix = nullptr;
    try {
        matrix = create(5, 5);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << e.what()<<"\n";
    }
    destroy(matrix, 5);
}



  }
}

int main()
{
  int ** matrix = nullptr;
  matrix = create(5,5);
}
