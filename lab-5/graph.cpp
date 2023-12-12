#include "graph.h"

void Graph::addNode(int value) { // Метод добавления
    Node* newNode = new Node(value); // Создание нового узла
    nodes[value] = newNode; // Добавление узла
}

void Graph::addEdge(int fromValue, int toValue) { // Метод добавления ребра
    if (nodes.find(fromValue) == nodes.end() || nodes.find(toValue) == nodes.end()) { // Проверка наличия
        std::cout << "Node not found!" << std::endl; // если один из узлов не найден, выдаст сообщение
        return; // Выход из метода
    }

    Node* fromNode = nodes[fromValue]; // Получение указателя
    Node* toNode = nodes[toValue];

    fromNode->neighbors.push_back(toNode); // Добавление узла
}

int Graph::sumOfNeighbors(int nodeValue) { // Метод вычисления
    if (nodes.find(nodeValue) == nodes.end()) { // Проверка наличия
        std::cout << "Node not found!" << std::endl; // если узлел не найден, выдаст сообщение
        return 0; // Возвращение 0
    }

    int sum = 0; // Переменная для хранения
    Node* currentNode = nodes[nodeValue]; // Получение указателя

    for (Node* neighbor : currentNode->neighbors) { // проходит всех соседних узлов
        sum += neighbor->value; // Добавление значения
    }

    return sum; // Возвращение суммы
}

Graph::~Graph() { // Деструктор
    for (auto& pair : nodes) { // проходит все элементы
        delete pair.second; // Удаление
    }
}


// Если коротко, то код реализует добавлениеузла в граф, добавление ребра, вычисление суммы соседних узлов и деструктор или очистку памяти