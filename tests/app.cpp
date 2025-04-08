#include "ArrayList.hpp"
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"

void doublyLinkedListTest(DoublyLinkedList& dList)
{
    std::cout << "DoublyLinkedList:" << std::endl
              << "1. Dodaj element na koniec" << std::endl
              << "2. Dodaj element na poczatek" << std::endl
              << "3. Dodaj element na pozycji" << std::endl
              << "4. Usun element z poczatku" << std::endl
              << "5. Usun element z konca" << std::endl
              << "6. Usun element na pozycji" << std::endl
              << "7. Wyswietl wszystkie elementy" << std::endl;

    int choice;
    std::cin >> choice;

    int value, index;

    switch (choice)
    {
        case 1:
            std::cout << "Podaj element do dodania na koniec: ";
            std::cin >> value;
            dList.push_back(value);
            doublyLinkedListTest(dList);
            break;
        case 2:
            std::cout << "Podaj element do dodania na poczatek: ";
            std::cin >> value;
            dList.push_front(value);
            doublyLinkedListTest(dList);
            break;
        case 3:
            std::cout << "Podaj pozycje i element do dodania: ";
            std::cin >> index >> value;
            dList.insert(index, value);
            doublyLinkedListTest(dList);
            break;
        case 4:
            std::cout << "Usuwam element z poczatku" << std::endl;
            dList.pop_front();
            doublyLinkedListTest(dList);
            break;
        case 5:
            std::cout << "Usuwam element z konca" << std::endl;
            dList.pop_back();
            doublyLinkedListTest(dList);
            break;
        case 6:
            std::cout << "Podaj pozycje do usuniecia: ";
            std::cin >> index;
            dList.remove_at(index);
            doublyLinkedListTest(dList);
            break;
        case 7:
            std::cout << "Wszystkie elementy w liscie: ";
            dList.print();
            doublyLinkedListTest(dList);
            break;
        default:
            doublyLinkedListTest(dList);
    }
}

void singlyLinkedListTest(SinglyLinkedList& sList)
{
    std::cout << "SinglyLinkedList:" << std::endl
              << "1. Dodaj element na koniec" << std::endl
              << "2. Dodaj element na poczatek" << std::endl
              << "3. Dodaj element na pozycji" << std::endl
              << "4. Usun element z poczatku" << std::endl
              << "5. Usun element z konca" << std::endl
              << "6. Usun element na pozycji" << std::endl
              << "7. Wyswietl wszystkie elementy" << std::endl;

    int choice;
    std::cin >> choice;

    int value, index;

    switch (choice)
    {
        case 1:
            std::cout << "Podaj element do dodania na koniec: ";
            std::cin >> value;
            sList.push_back(value);
            singlyLinkedListTest(sList);
            break;
        case 2:
            std::cout << "Podaj element do dodania na poczatek: ";
            std::cin >> value;
            sList.push_front(value);
            singlyLinkedListTest(sList);
            break;
        case 3:
            std::cout << "Podaj pozycje i element do dodania: ";
            std::cin >> index >> value;
            sList.insert(index, value);
            singlyLinkedListTest(sList);
            break;
        case 4:
            std::cout << "Usuwam element z poczatku" << std::endl;
            sList.pop_front();
            singlyLinkedListTest(sList);
            break;
        case 5:
            std::cout << "Usuwam element z konca" << std::endl;
            sList.pop_back();
            singlyLinkedListTest(sList);
            break;
        case 6:
            std::cout << "Podaj pozycje do usuniecia: ";
            std::cin >> index;
            sList.remove_at(index);
            singlyLinkedListTest(sList);
            break;
        case 7:
            std::cout << "Wszystkie elementy w liscie: ";
            sList.print();
            singlyLinkedListTest(sList);
            break;
        default:
            singlyLinkedListTest(sList);
    }
}

void arrayListTest(ArrayList<int>& list)
{
    std::cout << "ArrayList:" << std::endl
              << "1. Dodaj element na koniec" << std::endl
              << "2. Dodaj element na pozycji" << std::endl
              << "3. Usun element" << std::endl
              << "4. Zwroc element na pozycji" << std::endl
              << "5. Sprawdz czy zawiera element" << std::endl
              << "6. Wyswietl wszystkie elementy" << std::endl;
              
    int choice;
    std::cin >> choice;

    int value, index;

    switch (choice)
    {
        case 1:
            std::cout << "Podaj element do dodania: ";
            std::cin >> value;
            list.add(value);
            arrayListTest(list);
            break;
        case 2:
            std::cout << "Podaj pozycje i element do dodania: ";
            std::cin >> index >> value;
            list.add(index, value);
            arrayListTest(list);
            break;
        case 3:
            std::cout << "Podaj pozycje do usuniecia: ";
            std::cin >> index;
            list.remove(index);
            arrayListTest(list);
            break;
        case 4:
            std::cout << "Podaj pozycje do zwrocenia: ";
            std::cin >> index;
            std::cout << "Element na pozycji " << index << ": " << list.get(index) << std::endl;
            arrayListTest(list);
            break;
        case 5:
            std::cout << "Podaj element do wyszukania: ";
            std::cin >> value;
            index = list.contains(value);
            if (index != -1)
                std::cout << "Element " << value << " znajduje sie na pozycji " << index << std::endl;
            else
                std::cout << "Element " << value << " nie znajduje sie w liscie" << std::endl;
            arrayListTest(list);
            break;
        case 6:
            std::cout << "Wszystkie elementy w liscie: ";
            list.print();
            arrayListTest(list);
            break;
        default:
            arrayListTest(list);
    }
}

void mainMenu()
{
    std::cout << "Wybierz strukture:" << std::endl
              << "1. ArrayList" << std::endl
              << "2. SinglyLinkedList" << std::endl
              << "3. DoublyLinkedList" << std::endl;

    int choice;
    std::cin >> choice;

    ArrayList<int> list;
    SinglyLinkedList sList;
    DoublyLinkedList dList;

    switch (choice)
    {
        case 1:
            arrayListTest(list);
            break;
        case 2:
            singlyLinkedListTest(sList);
            break;
        case 3:
            doublyLinkedListTest(dList);
            break;
        default:
            mainMenu();
    }
}

int main(int argc, char *argv[])
{
    mainMenu();
    return 0;
}