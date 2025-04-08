#include "../include/DoublyLinkedList.hpp"

//konstruktor
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DoublyLinkedList::push_back(int value) {
    NodeD* newNode = new NodeD{ value,nullptr };
    //lista jest pusta: dany węzel będzie i head i tail
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    //lista nie jest pusta
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::push_front(int value) {
    NodeD* newNode = new NodeD{ value,nullptr };
    //lista jest pusta: dany węzel będzie i head i tail
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    //lista nie jest pusta
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoublyLinkedList::insert(int index, int value) {
    //index < 0
    if (index < 0) {
        std::cout << "You can't add an element at a negative index" << std::endl;
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
        NodeD* newNode = new NodeD{ value,nullptr };
        //w zmienną current zapisujemy element poprzedni przed tym elementem który chcemy wstaić, czyli element na pozycji 'index-1'
        NodeD* current = head;
        //licznik dla pętli 
        int currentIndex = 0;

        //'current != nullptr' sprawdza czy lista jest pusta
        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        //sprawdzenie czy current==nullptr aby uniknąć błędu dostępu do pamięci
        if (current == nullptr) {
            std::cout << "Unexpected error: current is nullptr!" << std::endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
        size++;
    }
    //jeśli index > rozmiar listy
    else {
        std::cout << "You cannot add an element at an index greater than the length of the list" << std::endl;
        return;
    }
}

void DoublyLinkedList::pop_front() {
    //lista jest pusta
    if (head == nullptr) {
        std::cout << "You can't remove an item from an empty list" << std::endl;
        return;
    }
    // w liście jest tylko jeden element
    if (head == tail) {
        head->next = nullptr;
        tail->next = nullptr;
        head = tail = nullptr;
        delete head;
        size--;
    }
    // w liście więcej niż jeden element
    else {
        NodeD* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        size--;
    }
}

void DoublyLinkedList::pop_back() {
    //jeśli lista jest pusta
    if (head == nullptr) {
        std::cout << "You can't remove an item from an empty list" << std::endl;
        return;
    }
    NodeD* temp = tail;
    //jęsli lista ma tylko jeden element
    if (head == tail) {
        head->next = nullptr;
        tail->next = nullptr;
        head = tail = nullptr;
    }
    //jeśli lista ma więcej niż jeden element
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

void DoublyLinkedList::remove_at(int index) {
    //index<0
    if (index < 0) {
        std::cout << "You can't remove an element at a negative index" << std::endl;
        return;
    }
    //index==0
    if (index == 0) {
        pop_front();
        return;
    }
    //index == size-1
    if (index == size - 1) {
        pop_back();
        return;
    }
    //index > 0 and index <size-1
    if (index > 0 && index < size - 1) {
        //w zmienną current zapisujemy element poprzedni przed tym elementem który chcemy usunąć, czyli element na pozycji 'index-1'
        NodeD* current = head;
        //licznik dla pętli 
        int currentIndex = 0;

        //'current != nullptr' sprawdza czy lista jest pusta
        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }
        NodeD* temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;
        delete temp;
        size--;
    }
    //jeśli index > rozmiar listy
    else {
        std::cout << "You cannot remove an element at an index greater than the length of the list" << std::endl;
        return;
    }
}

void DoublyLinkedList::print() {
    //wypadek jeśli lista jest pusta
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    NodeD* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

//destructor 
DoublyLinkedList::~DoublyLinkedList() {
    NodeD* current = head;
    while (current != nullptr) {
        NodeD* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}


int generete_number(int min, int max) {
    //rand() % N -> liczba losowa od 0 do N-1
    //rand() % (max - min + 1) -> liczba od liczba losowa od 0 do max
    //min + rand() % (max - min + 1) -> liczba losowa od min do max
    return min + rand() % (max - min + 1);
}