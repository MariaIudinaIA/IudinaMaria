#include <stdlib.h>
#include <iostream>

// This program was designed to show you how the stack works.
// You shouldn't dereference pointers which are no longer in scope.
// Never do that, it's undefined behavior (anything can happen).

// Note that this program may break if you use optimizations.
// Also, I have only tried it on Zig C++ (Clang) on Windows.

// Also note, that this produces a warning on Zig C++ (Clang), which is expected.

// See the excel file for a visualization of the stack.

int* stackMemory1()
{
    int a = 1; // Инициализируем переменную а и присваиваем ему значение 1
    return &a; // Возвращаем его адресс в памяти
}

int* stackMemory2()
{
    int b = 2; // аналогичное действие с b
    return &b;
}

int main()
{
    int* b = stackMemory1(); // Указатель b теперь указывает на адресс возвращенный из stackMemory1()
    int a1 = *b; // 1 //переменной a1 присваивается значение b
    int* c = stackMemory2(); // указатель с теперь указывает на адресс возвращенный функцией stackMemory2()
    int a2 = *c; // 2 
    int a3 = *b; // 2

    std::cout << a1 << std::endl; // prints 1
    std::cout << a2 << std::endl; // prints 2
    std::cout << a3 << std::endl; // prints 2
    std::cout << ((std::byte*)b - (std::byte*)c) << std::endl; // prints 0, pointers are equal

    return 0;
}


// код показывает, то как переменные размещаются на стеке 
// так же то как адреса этих переменных возвращаются через указатели в функции stackMemory1 и stackMemory2. 