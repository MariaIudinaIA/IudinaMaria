#include <iostream>
#include <cassert>

// Структура узла
struct Node {
    int value;
    Node* next = nullptr; // Указатель на следующий узел
};

// Структура односвязного списка
struct SingleLinkedList {
    Node* first = nullptr; // Указатель на первый элемент списка - пустой элемент
    Node* last = nullptr; // Указатель на последний элемент списка - пустой элемент
    int length = 0; // Количество элементов в списке - равен 0
};

// Структура для результата поиска узла
struct FindNodeResult {
    Node* previous = nullptr; // Указатель на предыдущий узел
    Node* current = nullptr; // Указатель на текущий узел
};

// Создание нового узла
Node* createNode(int value) {
    return new Node{value}; // Выделяется память под узел
}

// Создание пустого односвязного списка
SingleLinkedList* createList() {
    return new SingleLinkedList{}; // Выделяется память под список
}

// Поиск узла со значением в списке
FindNodeResult find(SingleLinkedList* list, int value) {
    FindNodeResult result;
    result.current = list->first; // Указатель на текущий элемент устанавливается на начало списка

    for (Node* i = list->first; i != nullptr; i = i->next) {
        if (i->value == value) { 
            return result; 
        } else {
            result.previous = i; // Указатель на предыдущий элемент обновляется на текущий
            result.current = i->next; // Указатель на текущий элемент обновляется на следующий
        }
    }
    return result; // если найден элемент, то возвращаем результат
}

// Вставка нового узла со значением после указанного узла
Node* insertAfter(SingleLinkedList* list, Node* node, int value) {
    Node* newNode = createNode(value); // Создается новый узел
    if (list->first == nullptr) { // Если пуст
        list->first = newNode; // Новый узел становится первым
        list->last = newNode; // И последним элементом
    } else if (node == nullptr) { // Если узел для вставки после нулевой
        newNode->next = list->first; // Новый узел становится первым элементом, а предыдущий первый элемент становится следующим
        list->first = newNode;
    } else {
        newNode->next = node->next; // Устанавливается связь нового узла со следующим узлом
        node->next = newNode; // Связывается предыдущий узел с новым узлом
        if (newNode->next == nullptr) { // Если новый узел последний в списке
            list->last = newNode; // Устанавливается как последний элемент
        }
    }
    list->length++; // Увеличивается счетчик элементов в списке
    return newNode; // Возвращается указатель на новый узел
}

// Удаление узла после заданного узла
void removeAfter(SingleLinkedList* list, Node* node) {
    if (node == nullptr) { // Если передан nullptr
        Node* temp = list->first; // Сохраняется первый элемент
        list->first = list->first->next; // Устанавливается новый первый элемент
        delete temp; // Освобождается память
        if (list->first == nullptr) { // Если список пуст
            list->last = nullptr; // Последний элемент становится nullptr
        }
    } else if (node->next != nullptr) { // Если узел после заданного существует
        Node* temp = node->next; // Сохраняется узел для удаления
        node->next = node->next->next; // Устанавливается связь между предыдущим и следующим за удаляемым узлом
        delete temp; // Освобождается память
        if (node->next == nullptr) { // Если удалили последний элемент
            list->last = node; // Обновляется указатель на последний элемент
        }
    }
    list->length--; // Уменьшается счетчик элементов в списке
}

// Проверка списка на наличие циклов
void assertNoCycles(SingleLinkedList* list) {
    int length = 0; // Инициализируется счетчик элементов
    for (Node* i = list->first; i != nullptr; i = i->next) { // Проход по всем элементам списка
        length++; // Увеличение счетчика элементов
    }
    assert(list->length == length); // Проверка на соответствие количества элементов в списке с фактическим числом элементов
}

// Тестирование функциональности списка
int main() {
    SingleLinkedList* list = createList(); // Создается новый список
    Node* node1 = insertAfter(list, nullptr, 5); 
    Node* node2 = insertAfter(list, node1, 11); 
    Node* node3 = insertAfter(list, node2, 12);
