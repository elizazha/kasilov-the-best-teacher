#include <iostream>
#include <stdexcept>
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
            mtx[created] = new int[cols];
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
{
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

int** convert(const int* t, size_t n, const size_t* lns, size_t rows)
{
    // Проверяем, что общее количество элементов совпадает
    size_t total_elements = 0;
    for (size_t i = 0; i < rows; i++) {
        total_elements += lns[i];
    }

    if (total_elements != n) {
        throw std::invalid_argument("Total elements in lns doesn't match n");
    }
    // Создаем "рваный" массив
    int** result = new int* [rows];
    size_t line = 0;
    size_t current_index_of_t = 0;
    try {
        for (; line < rows; ++line) {
            // Создаем строку длиной lns[line]
            result[line] = new int[lns[line]];

            // Копируем данные из исходного массива
            for (size_t j = 0; j < lns[line]; j++) {
                result[line][j] = t[current_index_of_t];
                current_index_of_t++;
            }
        }
    }
    catch (const std::bad_alloc& e) {
        destroy(result, line);
        throw;
    }
    return result;
}

void output_homework(int** mtx, const size_t* lns, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        std::cout << i << lns[i]; //строка, длина
        for (size_t j = 0; j < lns[i]; j++)
        {
            std::cout << mtx[i][j] << " ";
        }
        std::cout << "\n";
    }
}

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
        matrix = create(r, c);
    }
    catch (const std::bad_alloc&e)
    {
        std::cerr << e.what() << "\n";
        return 1;   
    }
    std::cout << "created!\n";
    construct(matrix, 2, r, c);
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
