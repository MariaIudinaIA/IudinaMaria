#include "dynamicArray.h"

DynamicArray::DynamicArray(int capacity) { // конструктора для DynamicArray
    this->values = new int[capacity]; // Выделяется памятб для массива
    this->capacity = capacity; // Присваивание значение
}

void DynamicArray::coutValues() { // Определение метода
    for (int i = 0; i < this->length; i++) { // Цикл начиная с 0 и до значения переменной длины
        std::cout << this->values[i] << " ";
    }
    std::cout << std::endl << this->capacity << std::endl;
}

 
// в этом фрагменте уже создается метод реализации структуры DynamicArray