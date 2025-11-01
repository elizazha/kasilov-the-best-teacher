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

int** create(size_t rows, size_t cols)
{
    int** mtx = new int* [rows];
    size_t created = 0; //счетчик чтобы посмотреть сколько массивров внутри массива успело выделиться
    try
    {
        for (; created < rows; ++created) //(size_t i = 0; i < rows; ++i)
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

void construct(int** mtx, int init, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            mtx[i][j] = init;
        }
    }
}

void input(int ** mtx, size_t rows, size_t cols)
{3
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cin >> mtx[i][j];
        }
    }
}
void output(int** mtx, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        //std::cout << mtx[i][0];
        for (size_t j = 0; j < cols; j++)
        {
            std::cout <<" "<< mtx[i][j];
        }
        std::cout << "\n";
    }
}
/*6
void construct(...);
int ** create(...);
void destroy();
могли их объявить, а исп потом в main 
*/
int main()
{
    size_t r = 0, c = 0;
    std::cin >> r >> c; // возвращает булевую прееменную, которая выдает false при некорректном вводе
    if (!std::cin)
    {
        std::cerr << "bad input!\n";
        return 2;
    }

    int** matrix = nullptr;
    try {
        matrix = create(5, 5);
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << e.what() << "\n";
        return 1;   
    }
    std::cout << "created!\n";
    construct(matrix, 2, 5, 5);
    std::cout << matrix[0][0] << "\n"; // undefined behavior (UB)
    input(matrix, r, c);
    if (!std::cin)
    {
        destroy(matrix, r);
        std::cerr << "Input error\n";
        return 1;
    }
    output(matrix, r, c);
      
    destroy(matrix, r);
}
