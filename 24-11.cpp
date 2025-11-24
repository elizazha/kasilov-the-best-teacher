#include <iostream>
struct Stud{
    const char* fst;//имя
    const char* snd;//фамилия
    int year;//год
    int dep;//кафедра
};



size_t countyear(const Stud * const * studs, size_t k, int y)
{
    size_t r = 0;
    for (size_t i = 0; i < k; ++i)
    {
        const Stud * stud_i = studs[i];
        int stud_y = stud_i -> year;
        r += (stud_y == y)? 1 : 0;
    }
    return r;
}

const Stud ** stud_dep (const  Stud * const * studs, size_t k, int dep, size_t & found)
{
    size_t depCount = 0;
    for (size_t i = 0; i < k; i++)
    {
        const Stud * stud_i = studs[i];
        depCount += (stud_i -> dep == dep);
    }
    const Stud **  r = new const Stud*[depCount];
    found = depCount;
    size_t j = 0;
    for (int i = 0; i < k; ++i)
    {
        const Stud * stud_i = studs[i];
        if (stud_i -> dep == dep)
        {
            r[j++] = stud_i;
        }
    }
}

struct Subj {
    const char * name;
    size_t people, classes;
    const Stud * const * studs;
    const size_t * visited;
};

size_t max_visits(const Subj & sub, int y)
{
    size_t cy = countyear(sub.studs, sub.people, y);
    return cy * sub.classes;
}
size_t visits(const Subj & sub, int y)
{
    size_t r = 0;
    for (size_t i =0; i < sub.people; i++)
    {
        const Stud* stud_i = sub.studs[i];
        if (stud_i -> year == y)
        {
            r += sub.visited[i];
        }
    }
    return r;
}