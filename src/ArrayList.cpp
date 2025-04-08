#include "../include/ArrayList.hpp"

// Constructor with default capacity of 4
template <typename T>
ArrayList<T>::ArrayList()
{
    capacity = 4;
    size = 0;
    array = (T*)malloc(capacity * sizeof(T));

    if (array == nullptr)
        throw std::bad_alloc();
}

// Destructor to free allocated memory
template <typename T>
ArrayList<T>::~ArrayList()
{
    free(array);
}

// Reallocate the array to double its capacity
template <typename T>
void ArrayList<T>::reallocate()
{
    T* temp = (T*)realloc(array, capacity * 2 * sizeof(T));

    if (temp == nullptr)
        throw std::bad_alloc();

    array = temp;
    capacity *= 2;
}

// Get the element at the specified index
template <typename T>
T& ArrayList<T>::get(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    return *(array + index);
}

/// Remove the element at the specified index and return it
template <typename T>
T ArrayList<T>::remove(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    T removedValue = *(array + index);
    
    for (int i = index; i < size - 1; i++)
    {
        *(array + i) = *(array + i + 1);
    }
    
    *(array + size - 1) = T();  // Remove last element
    size--;
    return removedValue;
}

// Add an element to the end of the list
template <typename T>
void ArrayList<T>::add(const T& value)
{
    if (size == capacity)
        reallocate();

    *(array + size) = value;
    size++;
}

// Add an element at the specified index
template <typename T>
void ArrayList<T>::add(int index, const T& value)
{
    if (index < 0 || index > size)
        throw std::out_of_range("Index out of range");

    if (size == capacity)
        reallocate();

    for (int i = size; i > index; i--)
    {
        *(array + i) = *(array + i - 1);
    }

    *(array + index) = value;
    size++;
}

// Check if the list contains the specified value and return its index
template <typename T>
int ArrayList<T>::contains(const T& value) const
{
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) == value)
            return i;
    }

    return -1;  // Not found
}

// Print the elements of the list
template <typename T>
void ArrayList<T>::print() const
{
    int i = 0;
    while (i < size - 1)
    {
        std::cout << *(array + i) << ", ";
        i++;
    }
    std::cout << *(array + i) << std::endl;
}