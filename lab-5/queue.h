#include <iostream> 
#include <cassert> 

struct Node { // структура узла списка
    int data; // Данные
    Node* nextNode; // Указатель на следующий узел

    Node(int value) : data(value), nextNode(nullptr) {} // Конструктор узла
};

class Queue {
    Node* firstNode; // Указатель на первый узел
    Node* lastNode; // Указатель на последний узел

    Queue() : firstNode(nullptr), lastNode(nullptr) {} // Конструктор Queue

    void enqueue(int value); // Метод добавления
    int dequeue(); // Метод удаления
    bool isEmpty() const { // Метод проверки
        return (firstNode == nullptr); // true, если первый узел равен nullptr
    }
    ~Queue(); // Деструктор класса Queue (будет, если не будет класса)

private:
    void clear(); // очистка памяти
};
