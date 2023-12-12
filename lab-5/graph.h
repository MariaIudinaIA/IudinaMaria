#include <iostream> 
#include <vector> 
#include <unordered_map> 

struct Node { // Определение структуры
    int value; // Значение
    std::vector<Node*> neighbors; // Вектор на соседние узлы

    Node(int val) : value(val) {} // принимает значение и начинает узел
};

class Graph {
private:
    std::unordered_map<int, Node*> nodes; // Хранилище

public:
    void addNode(int value); // Метод добавления
    void addEdge(int fromValue, int toValue); // Метод добавления ребра
    int sumOfNeighbors(int nodeValue); // Метод вычисления суммы
    ~Graph(); // удаление
};


// Этот код для работы с графами. Есть узел графа и вектор указателей на соседние узлы, содержит карту, связывающую значения с узлами, 
// а также методы для добавления узлов и ребер, вычисления суммы и удаления памяти.