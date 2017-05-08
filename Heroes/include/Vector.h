#ifndef VECTOR_H
#define VECTOR_H
#include "Monster.h"
#include <cstdlib>
#include <iostream>

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
    iterator begin() /**head of vector*/
    {
        return &store[0];
    }
    iterator end() /**end of vector*/
    {
        return &store[size];
    }

        Vector(int initialCapacity = Initial_Capacity) /**default constructor*/
        :
            size{0}, capacity{initialCapacity}
        {
            store = new T[initialCapacity];
        }

    ~Vector() /**destructor*/
    {
        if (store!=nullptr)
        delete[] store;
    }
////////////////////////////////////////METHODS//////////////////////////////////////////////
    void pushback(T elem) /**adding an element to the end of vector*/
    {
        if ((size + 1) > capacity)
        reallocMemory();
        store[size] = elem;
        size++;
    }
    void popback() /**deleting last element*/
    {
        if(size == 0)
        {
            std::cout <<"No elements in vector";
            return;
        }
        size--;
    }
    void reallocMemory() /**allocing more memory, when space for next element is too short*/
    {
        capacity *=2;
        T *temp = new T[capacity];
        try
            {temp;}
        catch (std::bad_alloc &bAlloc)
        {
            std::cout << "Blad pamieci" << bAlloc.what() << std::endl;
            exit(2);
        }
        for (int i = 0; i<size; i++)
        {
            temp[i] = store[i];
        }
        delete[] store;
        store = temp;
    }
    void remove(int i) /**deleting i element*/
    {
        for (i; i<size+1;i++)
        {
            store[i] = store[i+1];
            size--;
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
    T& operator =(const T&& other)
    {
        store = other.store;
        size = other.size;
        capacity = other.capacity;
        other.store = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    int showSize() /**returning size of a vector*/
    {
        return size;
    }
    protected:

    private:
};
template<>
void Vector<Monster>::pushback(Monster elem); /**specialized function*/

#endif // VECTOR_H
