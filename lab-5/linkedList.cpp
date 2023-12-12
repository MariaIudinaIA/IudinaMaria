#include "linkedList.h"
#include <assert.h> 
#include <iostream> 

Node* LinkedList::insertAfter(Node* node, int value) { // Метод вставки
    Node* newNode = new Node(value); // Создание нового узла
    nodeCount++; // Увеличение узлов

    if (this->head == nullptr) { // Если список пуст
        this->head = newNode; // новый узел становится началом списка
        return newNode; 
    }

    Node* current = this->head; // Указатель на текущий узел( имеется в виду с начала списка)
    while (current != nullptr) { // Пока не достигнут конец списка
        if (current->data == node->data) { // Если значение текущего=указанного
            newNode->nextNode = current->nextNode; // нового узла указываем на следующий узел, после текущего
            current->nextNode = newNode; // текущий узла на новый узел
            return newNode;
        }
        current = current->nextNode; // Переход к следующему
    }

    newNode->nextNode = this->head; // Если узла нет, то новый узел в начало списка
    this->head = newNode;
    return newNode;
}

FindNodeResult LinkedList::find(int value) { // Метод поиска
    if (head == nullptr || head->data == value) { // Если список пуст
        return FindNodeResult(nullptr, head); // Возвращаем nullptr и указатель на найденный узел
    }

    Node* current = head; // Указатель на текущий узел
    while (current->nextNode != nullptr) { // Пока не достигнут конец
        if (current->nextNode->data == value) { // Если значение следующего=заданному
            return FindNodeResult(current, current->nextNode);
        }
        current = current->nextNode
    }

    return FindNodeResult(nullptr, nullptr); // Если значение не было найдено, nullptr для обоих узлов
}

void LinkedList::removeAfter(Node* node) { // Метод удаления
    if (head == nullptr || (node == nullptr && head->nextNode == nullptr)) { // Если список пуст
        return; // Просто возвращает
    }

    if (node == nullptr) { // Если узел не указан, то удаляем
        Node* temp = head; // Временный указатель
        head = head->nextNode; // в начало списка - следующий узел
        delete temp; // Удаляем
        return;
    }

    if (node->nextNode != nullptr) { // Если узел существует
        Node* temp = node->nextNode; // Временный указатель после указанного
        node->nextNode = temp->nextNode; // Устанавливаем указатель на следующий узел
        delete temp; // Удаляем
    }
}

void LinkedList::assertNoCycles() { // Метод проверки
    int count = 0; // Счетчик
    Node* slow = head; // Указатель, на 1 узел 
    Node* fast = head; // Указатель, на 2 узла

    while (fast != nullptr && fast->nextNode != nullptr) { // Пока на 2 указатели не достигли конца
        slow = slow->nextNode; // Перемещение на 1
        fast = fast->nextNode->nextNode; // Перемещение на 2 указателя
        count++; // Увеличение счетчика

        if (count > nodeCount) { // Если количество больше общего числа узлов
            assert(false && "Cycle detected in the linked list!"); // ошибка
        }
    }
}

void LinkedList::displayList() { // Метод отображения
    Node* current = head; // Указатель на текущий узел
    while (current != nullptr) { // Пока не достигнут конец
        std::cout << current->data << " "; 
        current = current->nextNode; 
    }
    std::cout << std::endl;
}

// Если коротко, то этот код реализует методы (вставки, поиска, удаления, проверки и отображения)