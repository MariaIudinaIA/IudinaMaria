#include "dynamicArray.h"

DynamicArray::DynamicArray(int capacity) { // ������������ ��� DynamicArray
    this->values = new int[capacity]; // ���������� ������ ��� �������
    this->capacity = capacity; // ������������ ��������
}

void DynamicArray::coutValues() { // ����������� ������
    for (int i = 0; i < this->length; i++) { // ���� ������� � 0 � �� �������� ���������� �����
        std::cout << this->values[i] << " ";
    }
    std::cout << std::endl << this->capacity << std::endl;
}

 
// � ���� ��������� ��� ��������� ����� ���������� ��������� DynamicArray