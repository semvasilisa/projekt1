#indef zad3_hpp
#define zad3_hpp

#include <iostream>

using namespace std;

//węzel to podstawowy element listy
struct Node {
    int data;
    Node* next;//wskażnik na następny element
    Node* prev;//wskażnik na poprzedni element
};

//zarządza węzlami listy
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
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

int generete_number(int min, int max);

int main(){}


#endif