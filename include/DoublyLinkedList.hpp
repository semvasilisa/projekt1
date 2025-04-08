#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <iostream>

//węzel to podstawowy element listy
struct NodeD {
    int data;
    NodeD* next;//wskażnik na następny element
    NodeD* prev;//wskażnik na poprzedni element
};

//zarządza węzlami listy
class DoublyLinkedList {
private:
    NodeD* head;
    NodeD* tail;
    int size;
public:
    //konstruktor
    DoublyLinkedList();

    void push_back(int value);
    void push_front(int value);
    void insert(int index, int value);
    void pop_front();
    void pop_back();
    void remove_at(int index);
    void print();

    //destructor 
    ~DoublyLinkedList(); 
};

#endif