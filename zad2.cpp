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
    SinglyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push_back(int value) {
        Node* newNode = new Node{ value,nullptr };
        //lista jest pusta: dany węzel będzie i head i tail
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        //lista nie jest pusta
        else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void push_front(int value) {
        Node* newNode = new Node{ value,nullptr };
        //lista jest pusta: dany węzel będzie i head i tail
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        //lista nie jest pusta
        else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insert(int index, int value) {
        //index < 0
        if (index < 0) {
            cout << "You can't add an element at a negative index" << endl;
            return;
        }
        //index == 0
        if (index == 0) {
            push_front(value);
            return;
        }
        //index == size 
        if (index == size) {
            push_back(value);
            return;
        }
        //index >0 and index < size
        if (index > 0 && index < size) {
            Node* newNode = new Node{ value,nullptr };
            //w zmienną current zapisujemy element poprzedni przed tym elementem który chcemy wstaić, czyli element na pozycji 'index-1'
            Node* current = head;
            //licznik dla pętli 
            int currentIndex = 0;

            //'current != nullptr' sprawdza czy lista jest pusta
            while (current != nullptr && currentIndex<index-1) {
                current = current->next;
                currentIndex++;
            }

            //sprawdzenie czy current==nullptr aby uniknąć błędu dostępu do pamięci
            if (current == nullptr) { 
                cout << "Unexpected error: current is nullptr!" << endl;
                return;
            }

            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
        //jeśli index > rozmiar listy
        else {
            cout << "You cannot add an element at an index greater than the length of the list" << endl;
            return;
        }
    }

    void pop_front() {
        //lista jest pusta
        if (head == nullptr) {
            cout << "You can't remove an item from an empty list" << endl;
            return;
        }
        // w liście jest tylko jeden element
        if (head == tail)
        {
            head->next = nullptr;
            tail->next = nullptr;
            head = tail = nullptr;
            delete head;
            size--; 
        }
        // w liście więcej niż jeden element
        else {
            Node* temp = head;//Save the current head
            head = head->next;//We update the head, it now points to the next node
            if (head == nullptr) {  // If the list becomes empty, tail must also be nullptr
                tail = nullptr;     
            }
            delete temp;
            size--;
        }
    }

    void pop_back() {
        //jeśli lista jest pusta
        if (head == nullptr) {
            cout << "You can't remove an item from an empty list" << endl;
            return;
        }
        //jęsli lista ma tylko jeden element
        if (head == tail)
        {
            head->next = nullptr;
            tail->next = nullptr;
            delete head;
            size--;
            head = tail = nullptr;
        }
        //jeśli lista ma więcej niż jeden element
        else {
            // We will walk through the list to the penultimate element
            Node* current = head;
            while (current->next != tail) {
                //In each iteration, we write the element that does not point to the tail into the variable. Thus, when we go to the penultimate element and it points to the tail, the cycle ends and from the previous iteration, the penultimate element is written into the variable 'current'.
                current = current->next;
            }
            delete tail;
            current->next = nullptr;
            tail = current;
            size--;
        }
    }

    void remove_at(int index) {
        //index<0
        if (index < 0) {
            cout << "You can't remove an element at a negative index" << endl;
            return;
        }
        //index==0
        if (index == 0) {
            pop_front();
            return;
        }
        //index == size-1
        if (index == size-1) {
            pop_back();
            return;
        }
        //index > 0 and index <size-1
        if (index > 0 && index < size) {
            Node* current = head;
            int currentIndex = 0;

            while (current != nullptr && currentIndex < index - 1) {
                current = current->next;
                currentIndex++;
            }

            if (current == nullptr) {
                cout << "Unexpected error: current is nullptr!" << endl;
                return;
            }

            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
        //jeśli index > rozmiar listy
        else {
            cout << "You cannot remove an element at an index greater than the length of the list" << endl;
            return;
        }
    }

    void print() {
        //wypadek jeśli lista jest pusta
        if (head == nullptr) {  
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    //destructor 
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }
};

//funkcja do generowania liczb od min do max
int generete_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

//funkcja obliczjąza średni czas dodawania liczb do 10 list
int countAverageTime(string fileName) {
    SinglyLinkedList list[10];

    //otwarzmy plik do odczytu liczb 
    std::ifstream file(fileName);


    int liczba;
    auto start = high_resolution_clock::now();
    while (file >> liczba) {
        for (int i = 0; i < 10; i++) {
            list[i].push_back(liczba); // dodajemy liczbę do każdej listy
        }
    }
    auto stop = high_resolution_clock::now();

    file.close();

    auto duration = duration_cast<microseconds>(stop - start);
    int t = duration.count() / 10;
    return t;
}

//funkcja obliczjąza średni czas dodawania liczb z 3ech plików 
int badanie(string liczby1, string liczby2, string liczby3) {

    int t1 = countAverageTime(liczby1);
    int t2 = countAverageTime(liczby2);
    int t3 = countAverageTime(liczby3);
    return (t1 + t2 + t3) / 3;
}

//funkcja zapisywująca generewane liczby do pliku
void generuj_do_pliku(int ileLiczb, string nazwaPliku) {

    // Create and open a text file
    ofstream file1(nazwaPliku);

    // Write to the file
    for (int i = 0;i < ileLiczb;i++) {
        file1 << generete_number(1, 100) << " ";
        if (i == ileLiczb-1) cout << "zapisane" << endl;
    }

    file1.close();
}

int main()
{
    generuj_do_pliku(10, "testMetody.txt");
    generuj_do_pliku(10, "testMetody2.txt");
    generuj_do_pliku(10, "testMetody3.txt");

    //cout<<countAverageTime("testMetody.txt");
    cout << badanie("testMetody.txt", "testMetody2.txt", "testMetody2.txt");

}

