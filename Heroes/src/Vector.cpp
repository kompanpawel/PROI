#include "Vector.h"


template<>
void Vector<Monster>::pushback(Monster elem)
{
    if (elem.getAttack()<10)
        return;
    Vector::reallocMemory();
    store[size] = elem;
    size++;
}
