#include <iostream> 
#include <cassert> 
#include "doubleList.h" 

Node* DoubleLinkedList::insertAfter(Node* node, int value) { // Метод вставки узла
    if (node == nullptr) { // начинается цикл если указатель на узел пустой
        Node* newNode = new Node(value); // Создание нового узла
        firstNode = newNode; // Устанавливается первый и последний узлы как новый узел
        lastNode = newNode;
        return newNode;
    }

    Node* newNode = new Node(value); // Создание нового узла
    newNode->prevNode = node; // Устанавливаем указатель (на предыдущий узел, но нового узла)
    newNode->nextNode = node->nextNode; // Устанавливаем указатель, но уже на следующий

    if (node->nextNode != nullptr) { // длаем цикл если следующий узел не пустой
        node->nextNode->prevNode = newNode; // то указатель на предыдущий узел становится для следующего узла
    }
    else { // в противном случае  если пустой
        lastNode = newNode; // То новый узел становится последним
    }

    node->nextNode = newNode; // Устанавливаем указатель 
    return newNode; // Возвращаем
}

Node* DoubleLinkedList::insertBefore(Node* node, int value) { // Метод вставки
    if (node == nullptr) { // Если указатель пустой
        Node* newNode = new Node(value); // Создание узла
        firstNode = newNode; // Устанавливаем первый и последний
        lastNode = newNode;
        return newNode;
    }

    Node* newNode = new Node(value); // Создание нового узла
    newNode->nextNode = node; // Устанавливаем указатель на следующий узел
    newNode->prevNode = node->prevNode; // Устанавливаем указатель на предыдущий узел

    if (node->prevNode != nullptr) { // Если предыдущий узел не пустой
        node->prevNode->nextNode = newNode; // Устанавливаем указатель на следующий узел для предыдущего узла
    }
    else { // в противном случае если пустой
        firstNode = newNode; // То новый узел становится первым
    }

    node->prevNode = newNode; // Устанавливаем указатель на предыдущий узел
    return newNode; 
}

Node* DoubleLinkedList::find(int value) { // Метод для поиска узла
    Node* current = firstNode; // Устанавливаем текущий узел как первый
    while (current != nullptr) { // Пока узел не пустой
        if (current->data == value) { // Если узел равен значению
            return current; 
        }
        current = current->nextNode; // Переходим к следующему узлу
    }
    return nullptr;
}

void DoubleLinkedList::remove(Node* node) { // Метод для удаления
    if (node == nullptr) { // Если указатель пустой
        return; // ничего не произойдет
    }

    if (node->prevNode != nullptr) { // Если не пустой
        node->prevNode->nextNode = node->nextNode; // Устанавливаем указатель на следующий узел
    }
    else { // в противном если пустой
        firstNode = node->nextNode; // То становится первым узлом
    }

    if (node->nextNode != nullptr) { // Если не пустой
        node->nextNode->prevNode = node->prevNode; // Устанавливаем указатель на предыдущий узел для следующего узла
    }
    else { // в противном случае если пустой
        lastNode = node->prevNode; // То становится последним узлом
    }

    delete node; // Удаляем
}

void DoubleLinkedList::assertNoCycles() { // Метод для проверки
    Node* current = firstNode; // Устанавливаем как первый узел
    while (current != nullptr) { // Пока не пустой
        if ((current->nextNode != nullptr && current->nextNode->prevNode != current) || // Если связь нарушена
            (current->prevNode != nullptr && current->prevNode->nextNode != current)) { // Или тут нарушена
            assert(false && "Cycle detected in the linked list!"); // завершаем программу
        }
        current = current->nextNode; // идем к следующему узлу
    }
}

DoubleLinkedList::~DoubleLinkedList() { // Деструктор класса
    deleteList(); // освобождения памяти
}

void DoubleLinkedList::deleteList() { // Метод для удаления
    Node* current = firstNode; // Устанавливаем как первый узел
    Node* next = nullptr; // Указатель на следующий узел

    while (current != nullptr) { // Пока не пустой
        next = current->nextNode; // Сохраняем на следующий узел
        delete current; // Удаляем
        current = next; // Переходим к следующему
    }

    firstNode = nullptr; // первый = nullptr
    lastNode = nullptr; // последний = nullptr
}

// Двусвязанный список - это точно такой же односвязнный список, только у каждого элемента данного списка помимо значения 
// и указателя на следующие элементы есть ещё и указатель на предыдущие элементы, за счёт этого он становится чуть-чуть более увесистым по размеру памяти, 
// но при этом с ним намного легче работать. То есть, если удалить элемент, для того, чтобы удалить элементы нужно было найти элемент предшествующий элемент, 
// которого хочешь удалить и потом у него там поменять значение указателей и потом только удалить этот элемент, то у  двусвязного всё намного легче, 
// потому что всегда есть указатель и на следующий элемент и на предыдущей. То есть всегда знаешь соседей (если так корректно сказать, но это лучшее описание, 
// что я смогла сама придумать) данного элемента и ты можешь очень легко его, например, удалить и просто соседям поменять указатели. 
// Или же вставить новые элементы, соседям поменять указатели. 
