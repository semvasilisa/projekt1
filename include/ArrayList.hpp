#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>

template <typename T>
class ArrayList
{
private:
    T* array;
    int capacity;
    int size;
    void reallocate();

public:
    ArrayList();
    ~ArrayList();

    T& get(int index) const;
    T remove(int index);
    void add(const T& value);
    void add(int index, const T& value);
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
    int contains(const T& value) const;
    void print() const;
};

#include "../src/ArrayList.cpp"
#endif