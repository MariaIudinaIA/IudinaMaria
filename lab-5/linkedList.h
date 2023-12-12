struct Node { 
    int data; // хранения данных узла
    Node* nextNode; // Указатель на следующий узел

    Node(int value) : data(value), nextNode(nullptr) {} // Конструктор для инициализации
};

struct FindNodeResult { // Определение для результата поиска
    Node* previousNode; // Указатель на предыдущий узел
    Node* foundNode; // Указатель на найденный узел

    FindNodeResult(Node* prev, Node* found) : previousNode(prev), foundNode(found) {} // Конструктор для предыдущего и найденного
};

class LinkedList {
private:
    Node* head; // Указатель на начало списка
    int nodeCount; // Количество узлов в списке

public:
    LinkedList() : head(nullptr) {} // Конструктор класса, начало списка

    Node* insertAfter(Node* node, int value); // Метод вставки
    FindNodeResult find(int value); // Метод поиска
    void removeAfter(Node* node); // Метод удаления
    void assertNoCycles(); // Метод для проверки
    void displayList(); // Метод для отображения
};

// Если коротко, то представляет связанный список и включает методы для вставки узла, поиска узла, удаления узла, проверки и отображения списка