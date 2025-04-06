#indef zad2_hpp
#define zad2_hpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

//węzel to podstawowy element listy
struct Node {
    int data;//dane węzla
    Node* next;//wskażnik na następny element
};

class SinglyLinkedList {
private:
    Node* head;
    Node* tail;
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

    //destructor 
    ~SinglyLinkedList();
};

//funkcja do generowania liczb od min do max
int generete_number(int min, int max);

//funkcja obliczjąza średni czas dodawania liczb do 10 list
int countAverageTime(string fileName);

//funkcja obliczjąza średni czas dodawania liczb z 3ech plików 
int badanie(string liczby1, string liczby2, string liczby3);
//funkcja zapisywująca generewane liczby do pliku
void generuj_do_pliku(int ileLiczb, string nazwaPliku);

int main();

#endif

