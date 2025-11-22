#include <iostream>
#include <memory>
struct p_t{
    int x, y;
};

struct Ints{
    ~Ints();
    Ints();
    Ints(size_t kk, int i);// констурктор создает массим кк, заполненный эл-тами i
    Ints(const Ints & w);
    Ints(Ints && w);
    void set(size_t id, int i );
    Ints & operator = (const Ints & w);
    Ints & operator = (Ints && w);
    Ints append(int x) const;
    Ints append(const Ints & w) const;
    private:
    int* d;
    size_t k;
};

struct Points
{
    Points() = default;
    Points(size_t k, p_t a); // к точек со значениями а
    //Points(const Points&w); // конструктор копирование
    //Points & operator(const Points& w); // деструктор присвавание(вроде)
    //Points(Points && w); // перемещ соот полей
    //Points & operator = (Points && w);// перемещ с присваи в соот полей
    // можно не писать, тк прога сама сделает, тк прописано в Ints

    void set(size_t id, p_t a);
    p_t get(size_t id) const;
    size_t size() const;
    Points append(p_t a) const;
    Points append(const Points & w) const ; // должны созд новый масс и вернуть его

    private:
    Points(Ints && d); // пусть он перемещвет intы
    Ints data;
};

Points::Points(Ints && d): // ссылка на Rvalue, чтобы работало надо move
    data(std::move(d)) // на копирование
{}

Points::Points(size_t k, p_t a):
    data(k*2, a.x) // 1 раз выделяем память и потом ее зполняем
    {
        for(size_t i = 0; i < k; ++i){
            data.set(i*2+1, a.y);
        }
    }
size_t Points::size() const{
    return data.size()/2; // ищем кол-во точек (пар x-y)
}
void Points::set(size_t id, p_t a){
    data.set(id*2, a.x);
    data.set(id*2+1, a.y);
}
p_t Points::get(size_t id)const{
    p_t r{data.get(id*2), data.get(id*2+1)}; // -x-y
    return r;
}
Points Points::append(p_t a) const{
    Ints delta(2, a.x);
    delta.set(1, a.y);
    delta = data.append(delta);
    //а теперь надо создать точки из этого массива
    return Points(std::move(delta));
} 
Points Points::append(const Points & w) const{}
int main()
{

}