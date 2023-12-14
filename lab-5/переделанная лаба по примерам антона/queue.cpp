#include <iostream>
#include <cassert>

// Структура узла
struct Node {
    int value;
    Node* next = nullptr; // Указатель на следующий узел по умолчанию nullptr
};

// Структура очереди
struct Queue {
    Node* first = nullptr; // Указатель на первый элемент очереди по умолчанию nullptr
    Node* last = nullptr; // Указатель на последний элемент очереди по умолчанию nullptr
    int length = 0; // Количество элементов в очереди по умолчанию 0
};

// Создание нового узла с переданным значением
Node* createNode(int value) {
    return new Node{value}; // Выделение памяти под узел и инициализация переданным значением
}

// Создание пустой очереди
Queue* createQueue() {
    return new Queue{}; // Выделение памяти под очередь и инициализация значениями по умолчанию
}

// Проверка, пуста ли очередь
bool isEmpty(Queue* queue) {
    return queue->first == nullptr && queue->last == nullptr; // Проверка наличия как первого, так и последнего элемента
}

// Добавление элемента в очередь
void enqueue(Queue* queue, int value) {
    Node* newNode = createNode(value); // Создание нового узла с переданным значением
    if (isEmpty(queue)) { // Если очередь пуста
        queue->first = newNode; // Устанавливается первый элемент
    } else {
        queue->last->next = newNode; // Устанавливается связь последнего элемента с новым узлом
    }
    queue->last = newNode; // Обновление указателя на последний элемент
    queue->length++; // Увеличение счетчика элементов
}

// Удаление элемента из очереди
int dequeue(Queue* queue) {
    int value = -1; // Значение по умолчанию
    if (!isEmpty(queue)) { // Если очередь не пуста
        value = queue->first->value; // Получение значения первого элемента
        Node* temp = queue->first; // Сохранение первого элемента для последующего удаления
        queue->first = queue->first->next; // Обновление указателя на первый элемент
        delete temp; // Освобождение памяти от удаляемого элемента
        queue->length--; // Уменьшение счетчика элементов
        if (queue->first == nullptr) { // Если после удаления элемента очередь пуста
            queue->last = nullptr; // Обновление указателя на последний элемент
        }
    }
    return value; // Возвращается удаленное значение (или -1, если очередь пуста)
}

// Запуск тестов
void runTests() {
    Queue* queue = createQueue(); // Создание новой очереди

    // Тест 1
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 7);
    enqueue(queue, 11);

    assert(queue->length == 4); // Проверка длины очереди
    assert(queue->first->value == 5); // Проверка значения первого элемента
    assert(queue->last->value == 11); // Проверка значения последнего элемента

    dequeue(queue);
    dequeue(queue);

    assert(queue->length == 2); // Проверка длины очереди после удаления элементов
    assert(queue->first->value == 7); // Проверка значения нового первого элемента
    assert(queue->last->value == 11); // Проверка значения последнего элемента
}

// Основная функция
int main() {
    runTests(); // Запуск тестов
    return 0;
}
