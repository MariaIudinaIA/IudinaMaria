#include <stdlib.h>
#include <iostream> // подключение библиотек

struct TwoInts
{
    int a;
    int b;
};                  // Эта структура содержит два целых числа

struct StructWithArray
{
    int arr[4];
    int* someNumber;
};                  // Эта структура StructWithArray содержит массив из четырех целых чисел arr и указатель someNumber.

int main()
{
    TwoInts i2 = { };
    i2.a = 5;
    i2.b = 7;

    std::cout << i2.a << std::endl;
    std::cout << i2.b << std::endl;
    // Создается переменная i2 типа TwoInts и инициализируется нулями. Затем значения a и b устанавливаются в 5 и 7. 
    // После этого значения выводятся на консоль.

    StructWithArray s = { };
    s.arr[0] = 10;                   // Создается переменная s типа StructWithArray и инициализируется нулями. 
    // Затем значение элемента arr[0] устанавливается в 10.

    StructWithArray s1 = { };
    s1.arr[0] = 15;                 // Создается переменная s1 типа StructWithArray и инициализируется нулями. 
    // Затем значение элемента arr[0] устанавливается в 15.

    StructWithArray* sPointer = &s;
    sPointer->arr[0] = 20;          // Создается указатель sPointer, который указывает на структуру s. 
    // Затем через указатель изменяется значение элемента arr[0] структуры s на 20.

    std::cout << s.arr[0] << std::endl;
    s.arr[0] = 25;
    std::cout << s.arr[0] << std::endl;
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl;  // Выводятся значения элемента arr[0] структуры s на консоль, 
    // затем оно изменяется и выводится снова.

    sPointer = &s1;
    sPointer->arr[0] = 35;
    std::cout << s.arr[0] << std::endl;
    std::cout << s1.arr[0] << std::endl; //  Указатель sPointer переключается на структуру s1, 
    // и затем выводятся значения элементов arr[0] структур s и s1 на консоль.

    StructWithArray structArray[2] = { }; // Создается массив из двух структур StructWithArray. 
    structArray[0].arr[3] = 77; // Это означает, что внутри первой структуры элемент arr[3] будет содержать значение 77.
    structArray[1].someNumber = &structArray[0].arr[3]; // Теперь someNumber во второй структуре будет указывать на то же место в памяти, 
    // где хранится значение 77 из первой структуры.

    sPointer = &s;
    int* pointer = &sPointer->arr[3];
    s.arr[3] = 72;
    std::cout << *pointer;               // Указатель sPointer переключается на структуру s, 
    // затем создается указатель pointer, который указывает на элемент arr[3] структуры s. 
    //Значение элемента arr[3] структуры s изменяется на 72, и это значение выводится на консоль.

    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));  // Создается переменная memory типа StructWithArray, 
    // и функция memset используется для заполнения всей структуры нулями. Это может быть полезно для инициализации структуры данными значениями.
    return 0;
}
// Этот код демонстрирует различные операции с структурами и указателями, 
// а также работу с массивами и функцией memset для инициализации данных.