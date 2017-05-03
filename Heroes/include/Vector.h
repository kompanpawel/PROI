#ifndef VECTOR_H
#define VECTOR_H
#include "Monster.h"

template < typename T >
class Vector
{

    T *store;
    int size;
    static const int Initial_Capacity = 20;
    int capacity;
    public:
        /*class iterator
        {
        public:
            typedef iterator self_type;
            typedef T value_type;
            typedef T& reference;
            typedef T *pointer;

            iterator (pointer ptr) : ptr_(ptr){}
            self_type operator++() {self_type i = *this; ptr_++; return i; }
            self_type operator++(int sth) {ptr_++; return *this;}
            reference operator*() {return *ptr_;}
            pointer operator ->() {return ptr_;}
            bool operator==(const self_type& obj) {return ptr_ == obj.ptr_;}
            bool operator!=(const self_type& obj) {return ptr_ != obj.ptr_;}
        private:
            pointer ptr_;


        };*/
        typedef T* iterator;

        Vector(int initialCapacity = Initial_Capacity)
        :
            size{0}, capacity{initialCapacity}
        {
            store = new T[initialCapacity];
        }
    void pushback(T elem)
    {
        if ((size + 1) > capacity)
        reallocMemory();
        store[size] = elem;
        size++;
    }
    void reallocMemory()
    {
        capacity *=2;
        T *temp = new T[capacity];
        for (int i = 0; i<size; i++)
        {
            temp[i] = store[i];
        }
        delete[] store;
        store = temp;
    }
    void remove(int i)
    {
        for (i; i<size+1;i++)
        {
            store[i] = store[i+1];
        }
    }
    T& operator [](int i)
    {
        return store[i];
    }
    T& operator +(T elem)
    {
        pushback(elem);
    }
    T& operator -(int i)
    {
        remove(i);
    }
    iterator begin()
    {
        return &store[0];
    }
    iterator end()
    {
        return &store[size];
    }
    protected:

    private:
};
template<>
void Vector<Monster>::pushback(Monster monster)
{
    if (monster.getAttack()<10)
        return;
}
#endif // VECTOR_H
