#include "../include/SinglyLinkedList.hpp"

SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void SinglyLinkedList::push_back(int value) {
    NodeS* newNode = new NodeS{ value,nullptr };
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

void SinglyLinkedList::push_front(int value) {
    NodeS* newNode = new NodeS{ value,nullptr };
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

void SinglyLinkedList::insert(int index, int value) {
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
        NodeS* newNode = new NodeS{ value,nullptr };
        //w zmienną current zapisujemy element poprzedni przed tym elementem który chcemy wstaić, czyli element na pozycji 'index-1'
        NodeS* current = head;
        //licznik dla pętli 
        int currentIndex = 0;

        //'current != nullptr' sprawdza czy lista jest pusta
        while (current != nullptr && currentIndex<index-1) {
            current = current->next;
            currentIndex++;
        }

        //sprawdzenie czy current==nullptr aby uniknąć błędu dostępu do pamięci
        if (current == nullptr) { 
            std::cout << "Unexpected error: current is nullptr!" << std::endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
    //jeśli index > rozmiar listy
    else {
        std::cout << "You cannot add an element at an index greater than the length of the list" << std::endl;
        return;
    }
}

void SinglyLinkedList::pop_front() {
    //lista jest pusta
    if (head == nullptr) {
        std::cout << "You can't remove an item from an empty list" << std::endl;
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
        NodeS* temp = head;//Save the current head
        head = head->next;//We update the head, it now points to the next node
        if (head == nullptr) {  // If the list becomes empty, tail must also be nullptr
            tail = nullptr;     
        }
        delete temp;
        size--;
    }
}

void SinglyLinkedList::pop_back() {
    //jeśli lista jest pusta
    if (head == nullptr) {
        std::cout << "You can't remove an item from an empty list" << std::endl;
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
        NodeS* current = head;
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

void SinglyLinkedList::remove_at(int index) {
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
    if (index == size-1) {
        pop_back();
        return;
    }
    //index > 0 and index <size-1
    if (index > 0 && index < size) {
        NodeS* current = head;
        int currentIndex = 0;

        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {
            std::cout << "Unexpected error: current is nullptr!" << std::endl;
            return;
        }

        NodeS* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }
    //jeśli index > rozmiar listy
    else {
        std::cout << "You cannot remove an element at an index greater than the length of the list" << std::endl;
        return;
    }
}

void SinglyLinkedList::print() {
    //wypadek jeśli lista jest pusta
    if (head == nullptr) {  
        std::cout << "List is empty!" << std::endl;
        return;
    }

    NodeS* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

//destructor 
SinglyLinkedList::~SinglyLinkedList() {
    NodeS* current = head;
    while (current != nullptr) {
        NodeS* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;
}