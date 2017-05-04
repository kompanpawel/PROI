#include "Vector.h"


template<>
void Vector<Monster>::pushback(Monster elem)
{
    if (elem.getAttack()<10)
        {
            std::cout<< "Too weak monster. Try make it again";
            return;
        }
    if(size+1 > capacity)
        Vector::reallocMemory();
    store[size] = elem;
    size++;
}
