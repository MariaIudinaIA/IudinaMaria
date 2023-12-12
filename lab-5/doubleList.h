#include <iostream>
#include <cassert> 

struct Node { 
    int data; // Данные узла
    Node* prevNode; // Указатель на предыдущий узел
    Node* nextNode; // Указатель на следующий узел

    Node(int value) : data(value), prevNode(nullptr), nextNode(nullptr) {} // Конструктор для инициализации узла
};

class DoubleLinkedList { 
    Node* firstNode; // Указатель на первый узел списка
    Node* lastNode; // Указатель на последний узел списка

    DoubleLinkedList() : firstNode(nullptr), lastNode(nullptr) {} // Конструктор класса, указатели у нас nullptr

    Node* insertAfter(Node* node, int value); // Метод для вставки узла (после)
    Node* insertBefore(Node* node, int value); // Метод для вставки узла (перед)
    Node* find(int value); // Метод для поиска узла
    void remove(Node* node); // Метод для удаления
    void assertNoCycles(); // Метод для проверки

    ~DoubleLinkedList(); // Деструктор для очистки памяти

private:
    void deleteList(); // Метод для удаления
};
