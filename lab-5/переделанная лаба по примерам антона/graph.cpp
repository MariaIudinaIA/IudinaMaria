#include <iostream>
#include <cassert>
using namespace std;

struct DynamicArray {
    int* addres; // Указатель на массив
    size_t capacity; // Емкость массива
    size_t count; // количество
};

// добавления элемента
void addElementToArray(DynamicArray* arr, int n) {
    // Проверка если равно максимальной вместительности
    if (arr->count == arr->capacity) {
        size_t newSize = arr->capacity * 2;
        // Проверка емкость. если элемент был нулевой, то и новый будет 0, делаем его равным 1
        if (newSize == 0) {
            newSize = 1;
        }
        int* newArr = new int[newSize];

        // Копирование старых элементов
        for (size_t i = 0; i != arr->capacity; i++) {
            newArr[i] = arr->addres[i];
        }

        delete[] arr->addres; // Освобождение памяти
        arr->addres = newArr; // Обновление указателя
        arr->capacity = newSize; // Обновление емкости
    }

    arr->addres[arr->count] = n; // Добавление элемента в конец массива
    arr->count++; // Увеличение количества элементов
}

// создание с указанной емкостью, если нет, то по дефолту равно 4
DynamicArray createArray(size_t capacity = 4) {
    int* arr = new int[capacity];
    DynamicArray result;
    result.addres = arr;
    result.capacity = capacity;
    result.count = 0;
    return result;
}

// Структура узла с массивом ребер и ссылкой на следующий узел
struct Node {
    int value;
    DynamicArray edges;
    Node* next;
};

// Структура односвязного списка
struct SingleLinkedList {
    Node* first;
    Node* last;
    int length;
};

// Создание нового узла
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

// Добавление узла
Node* insertAfter(SingleLinkedList* list, Node* node, int value) {
    Node* newNode = createNode(value);
    if (list->first == nullptr) {
        list->first = newNode;
        list->last = list->first;
    }
    else if (node == nullptr) {
        newNode->next = list->first;
        list->first = newNode;
    }
    else {
        newNode->next = node->next;
        node->next = newNode;
        if (newNode->next == nullptr) {
            list->last = newNode;
        }
    }
    list->length++;
    return newNode;
}

// Удаление узла
void removeAfter(SingleLinkedList* list, Node* node) {
    if (node == nullptr) {
        Node* temp = list->first->next;
        delete list->first;
        list->first = list->first->next;
    }
    else {
        Node* temp = node->next->next;
        delete node->next;
        node->next = temp;
    }
    list->length--;
}

// Функция для подсчета суммы элементов массива ребер узла
int countSum(Node* node) {
    int sum = 0;
    for (int i = 0; i < node->edges.count; i++) {
        sum += node->edges.addres[i];
    }
    return sum;
}

// Основная функция
int main() {
    SingleLinkedList* list = new SingleLinkedList;

    // Добавление узлов
    Node* node4 = insertAfter(list, nullptr, 4);
    Node* node3 = insertAfter(list, nullptr, 3);
    Node* node2 = insertAfter(list, nullptr, 2);
    Node* node1 = insertAfter(list, nullptr, 1);

    // Инициализация массивов ребер
    node1->edges = createArray(3);
    addElementToArray(&node1->edges, 2);
    addElementToArray(&node1->edges, 3);
    addElementToArray(&node1->edges, 4);

    assert(countSum(node1) == 9); // Проверка суммы

    node2->edges = createArray(1);
    addElementToArray(&node2->edges, 3);

    assert(countSum(node2) == 3); // Проверка суммы

    node3->edges = createArray(1);
    addElementToArray(&node3->edges, 4);

    assert(countSum(node3) == 4); // Проверка суммы

    node4->edges = createArray(1);
    addElementToArray(&node4->edges, 1);

    assert(countSum(node4) == 1); // Проверка суммы

    // Освобождение памяти
    delete list;
}
