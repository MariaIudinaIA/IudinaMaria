#include <iostream> 
#include <cassert> 

struct Node { // ��������� ���� ������
    int data; // ������
    Node* nextNode; // ��������� �� ��������� ����

    Node(int value) : data(value), nextNode(nullptr) {} // ����������� ����
};

class Queue {
    Node* firstNode; // ��������� �� ������ ����
    Node* lastNode; // ��������� �� ��������� ����

    Queue() : firstNode(nullptr), lastNode(nullptr) {} // ����������� Queue

    void enqueue(int value); // ����� ����������
    int dequeue(); // ����� ��������
    bool isEmpty() const { // ����� ��������
        return (firstNode == nullptr); // true, ���� ������ ���� ����� nullptr
    }
    ~Queue(); // ���������� ������ Queue (�����, ���� �� ����� ������)

private:
    void clear(); // ������� ������
};
