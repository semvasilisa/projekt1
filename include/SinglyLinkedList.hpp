#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

#include <iostream>

//węzel to podstawowy element listy
struct NodeS {
    int data;//dane węzla
    NodeS* next;//wskażnik na następny element
};

class SinglyLinkedList {
private:
    NodeS* head;
    NodeS* tail;
    int size;
public:
    //konstruktor
    SinglyLinkedList();

    void push_back(int value);
    void push_front(int value);
    void insert(int index, int value);
    void pop_front();
    void pop_back();
    void remove_at(int index);
    void print();
    int getSize() const { return size; }

    //destructor 
    ~SinglyLinkedList();
};

#endif