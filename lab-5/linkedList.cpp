#include "linkedList.h"
#include <assert.h> 
#include <iostream> 

Node* LinkedList::insertAfter(Node* node, int value) { // ����� �������
    Node* newNode = new Node(value); // �������� ������ ����
    nodeCount++; // ���������� �����

    if (this->head == nullptr) { // ���� ������ ����
        this->head = newNode; // ����� ���� ���������� ������� ������
        return newNode; 
    }

    Node* current = this->head; // ��������� �� ������� ����( ������� � ���� � ������ ������)
    while (current != nullptr) { // ���� �� ��������� ����� ������
        if (current->data == node->data) { // ���� �������� ��������=����������
            newNode->nextNode = current->nextNode; // ������ ���� ��������� �� ��������� ����, ����� ��������
            current->nextNode = newNode; // ������� ���� �� ����� ����
            return newNode;
        }
        current = current->nextNode; // ������� � ����������
    }

    newNode->nextNode = this->head; // ���� ���� ���, �� ����� ���� � ������ ������
    this->head = newNode;
    return newNode;
}

FindNodeResult LinkedList::find(int value) { // ����� ������
    if (head == nullptr || head->data == value) { // ���� ������ ����
        return FindNodeResult(nullptr, head); // ���������� nullptr � ��������� �� ��������� ����
    }

    Node* current = head; // ��������� �� ������� ����
    while (current->nextNode != nullptr) { // ���� �� ��������� �����
        if (current->nextNode->data == value) { // ���� �������� ����������=���������
            return FindNodeResult(current, current->nextNode);
        }
        current = current->nextNode
    }

    return FindNodeResult(nullptr, nullptr); // ���� �������� �� ���� �������, nullptr ��� ����� �����
}

void LinkedList::removeAfter(Node* node) { // ����� ��������
    if (head == nullptr || (node == nullptr && head->nextNode == nullptr)) { // ���� ������ ����
        return; // ������ ����������
    }

    if (node == nullptr) { // ���� ���� �� ������, �� �������
        Node* temp = head; // ��������� ���������
        head = head->nextNode; // � ������ ������ - ��������� ����
        delete temp; // �������
        return;
    }

    if (node->nextNode != nullptr) { // ���� ���� ����������
        Node* temp = node->nextNode; // ��������� ��������� ����� ����������
        node->nextNode = temp->nextNode; // ������������� ��������� �� ��������� ����
        delete temp; // �������
    }
}

void LinkedList::assertNoCycles() { // ����� ��������
    int count = 0; // �������
    Node* slow = head; // ���������, �� 1 ���� 
    Node* fast = head; // ���������, �� 2 ����

    while (fast != nullptr && fast->nextNode != nullptr) { // ���� �� 2 ��������� �� �������� �����
        slow = slow->nextNode; // ����������� �� 1
        fast = fast->nextNode->nextNode; // ����������� �� 2 ���������
        count++; // ���������� ��������

        if (count > nodeCount) { // ���� ���������� ������ ������ ����� �����
            assert(false && "Cycle detected in the linked list!"); // ������
        }
    }
}

void LinkedList::displayList() { // ����� �����������
    Node* current = head; // ��������� �� ������� ����
    while (current != nullptr) { // ���� �� ��������� �����
        std::cout << current->data << " "; 
        current = current->nextNode; 
    }
    std::cout << std::endl;
}

// ���� �������, �� ���� ��� ��������� ������ (�������, ������, ��������, �������� � �����������)