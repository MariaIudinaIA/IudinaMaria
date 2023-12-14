#include <iostream>
#include <cassert>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};

struct DoubleLinkedList {
    Node* first; // ��������� �� ������ �������
    Node* last; // ��������� �� ��������� �������
    int length; // ���������� ���������
};

Node* createNode(int value) {
    Node* newNode = new Node{ value, nullptr, nullptr }; // �������� ������ ����
    return newNode;
}

DoubleLinkedList* createList() {
    DoubleLinkedList* list = new DoubleLinkedList{ nullptr, nullptr, 0 }; // �������� ������
    return list;
}

Node* find(DoubleLinkedList* list, int value) {
    for (Node* i = list->first; i != nullptr; i = i->next) { // ����� ��������
        if (i->value == value)
            return i;
    }
    return nullptr;
}

Node* insertAfter(DoubleLinkedList* list, Node* node, int value) {
    Node* newNode = createNode(value); // �������� ������ ����
    if (list->first == nullptr) { // ������ ����
        list->first = newNode; // ����� ���������� ������
        list->last = list->first; // � ���������
    }
    else if (node == nullptr) { // ���� �� �����
        newNode->next = list->first; // ����� ���� ���������� ������
        list->first->prev = newNode;
        list->first = newNode; 
    }
    else { 
        newNode->prev = node; // ����� ���� ��������� �� ����������
        newNode->next = node->next; // ����� ���� ��������� �� ���������
        if (newNode->prev) // ���� ���������� ���� ����������
            newNode->prev->next = newNode; // ��������� ��������� ���������� ���� �����������
        if (newNode->next) // ���� ��������� ���� ����������
            newNode->next->prev = newNode; // ��������� ��������� ����������� ���� ����������
        if (newNode->next == nullptr) { // ���� ����� ���� ��������� � ������
            list->last = newNode; // ��������� ��������� �� ��������� �������
        }
    }
    list->length++; 
    return newNode;
}

