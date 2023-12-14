#include <iostream>
#include <cassert>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};

struct DoubleLinkedList {
    Node* first; // Указатель на первый элемент
    Node* last; // Указатель на последний элемент
    int length; // Количество элементов
};

Node* createNode(int value) {
    Node* newNode = new Node{ value, nullptr, nullptr }; // Создание нового узла
    return newNode;
}

DoubleLinkedList* createList() {
    DoubleLinkedList* list = new DoubleLinkedList{ nullptr, nullptr, 0 }; // Создание нового
    return list;
}

Node* find(DoubleLinkedList* list, int value) {
    for (Node* i = list->first; i != nullptr; i = i->next) { // Поиск элемента
        if (i->value == value)
            return i;
    }
    return nullptr;
}

Node* insertAfter(DoubleLinkedList* list, Node* node, int value) {
    Node* newNode = createNode(value); // Создание нового узла
    if (list->first == nullptr) { // список пуст
        list->first = newNode; // Новый становится первым
        list->last = list->first; // И последним
    }
    else if (node == nullptr) { // Если не задан
        newNode->next = list->first; // Новый узел становится первым
        list->first->prev = newNode;
        list->first = newNode; 
    }
    else { 
        newNode->prev = node; // Новый узел ссылается на предыдущий
        newNode->next = node->next; // Новый узел ссылается на следующий
        if (newNode->prev) // Если предыдущий узел существует
            newNode->prev->next = newNode; // Обновляем указатель следующего узла предыдущего
        if (newNode->next) // Если следующий узел существует
            newNode->next->prev = newNode; // Обновляем указатель предыдущего узла следующего
        if (newNode->next == nullptr) { // Если новый узел последний в списке
            list->last = newNode; // Обновляем указатель на последний элемент
        }
    }
    list->length++; 
    return newNode;
}

