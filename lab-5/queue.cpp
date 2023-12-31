#include "queue.h" 

void Queue::enqueue(int value) { // Метод добавления
    Node* newNode = new Node(value); // Создание нового узла
    if (isEmpty()) { 
        firstNode = newNode; // то новый узел становится первым
    }
    else {
        lastNode->nextNode = newNode; // в противном случае, новый узел становится следующим
    }
    lastNode = newNode; // Новый узел становится последним
}

int Queue::dequeue() { // Метод удаления
    assert(!isEmpty() && "Queue is empty"); // Проверка на пустоту

    int value = firstNode->data; // инициализирунтся первый элемент
    Node* temp = firstNode; // хранение указателя на первый элемент
    firstNode = firstNode->nextNode; // переход указателя с первого элемента на следующий
    delete temp; // Освобождение памяти

    if (firstNode == nullptr) { 
        lastNode = nullptr; // последний элемент тоже становится nullptr
    }

    return value; // Возвращение удаленного элемента
}

Queue::~Queue() { // Деструктор Queue
    clear(); // освобождение памяти
}

void Queue::clear() { // Метод очистки памяти
    Node* current = firstNode; // Инициализация current, указывает на первый элемент
    Node* next = nullptr; // указателю next присуждается nullptr

    while (current != nullptr) { // Цикл удаления всех элементов
        next = current->nextNode; // переход на следующий элемент
        delete current; // Освобождение памяти
        current = next; // следующий элемент
    }

    firstNode = nullptr; // Установка указателя nullptr (первый)
    lastNode = nullptr; // Установка указателя nullptr (последний)
}


// Этот код - это односвязный список. Суть в том, что односвязанный список - это как массив, только не массив. 
// На самом деле это набор элементов структуры, которую сами определяем и главное условие, чтобы каждый элемент этого списка содержал указатель на следующий 
// после него элемент списка, а сам список должен содержать указатель на первый элемент в списке и на последние элементы в списке. 
// Суть в том что в каждом элементе есть какое-то значение и указатель на следующий элемент и таким образом, если мы знаем первый элемент, 
// знаем последний элемент, то мы можем пройти весь список, от первого элемента по указателям на следующий элемент до самого конца. 
// И таким образом он как будто бы действует как массив, но на самом деле он по-другому совершенно организован в памяти и его фишка в том, 
// что он как бы постоянно является динамическим. То есть у него никогда нет фиксированные длины. Его длина всегда может увеличиваться или уменьшаться, 
// в зависимости от того добавляешь элементы или убираешь. И все функции для работы с этим списком, они как бы тоже основываются на этих свойствах, 
// что можно просто от первого элемента до последнего пройти по всему списку. 
// Описала личное понимание и разбор всего сделанного. Без чатов и прочего
