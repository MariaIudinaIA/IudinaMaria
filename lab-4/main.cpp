#include <assert.h> 
#include <iostream>
#include "dynamicArray.h"


DynamicArray createDynamicArray(int capacity = 5) { // Функция динамического массива (с размером 5)
    DynamicArray* newArray = new DynamicArray(capacity); // Создание нового DynamicArray
    return *newArray;
}


void addElementToArray(DynamicArray& arr, int value) { // Добавляется элемент в динамический массив
    if (arr.length + 1 >= arr.capacity) { // Создается условие если длина +1 или = размеру 
        arr.capacity *= 2; // то увеличиваем размер массива умножая на 2
    }
    int* newValues = new int[arr.capacity]; // новый массив с увеличенным размером
    for (int i = 0; i < arr.length; i++) { // Копируем все из старого в новый
        newValues[i] = arr.values[i];
    }
    newValues[arr.length] = value; // новый элемент в конец нового
    arr.values = newValues; // Переназначаем указатель на новый
    arr.length += 1; // Увеличиваем длину
}


int getElementByIndex(DynamicArray& arr, int index) { // Функция получения элемента по index из массива
    if (arr.length - 1 >= index) { // Создается условие если index находится в пределах длины
        return arr.values[index]; // то возвращаем значение элемента (index)
    }
    else {
        return -100000; // в противном случае
    }
}


void destroyMemory(DynamicArray& arr) { // здесь освобождается выделенная память
    arr.capacity = 1; // Устанавливается емкость(1)
    arr.length = 0; // Обнуляется длина
    delete[] arr.values; // освобождается память
}

int main() {
    int cap; // емкостб массива
    std::cout << "Give default value for capacity (0 if default)" << std::endl;
    std::cin >> cap; 

    
    DynamicArray myArray = cap == 0 ? createDynamicArray() : createDynamicArray(cap); // Создание объекта DynamicArray

    
    cap == 0 ? assert(myArray.capacity == 5) : assert(myArray.capacity == cap); // идет проверка assert на соответствие емкости массива

    
    addElementToArray(myArray, 10);// Добавление элементов
    addElementToArray(myArray, 20);
    addElementToArray(myArray, 30);

    
    myArray.coutValues(); // Выводится содержимое

    
    int el = getElementByIndex(myArray, 2); // Получение элемента и проверка
    assert(el == 30);

    
    destroyMemory(myArray); // и наконец освобождаем память
}
