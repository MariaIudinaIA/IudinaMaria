#include <iostream> 

struct DynamicArray { 
    int* values; // ��������� �� ������ ���� int
    int length = 0; // ����� �������
    int capacity = 0; // ������� ������� (� ��������� � main.cpp ��� ��� �����, �� ������� �� �������)

    DynamicArray(int); // ���������� ������������
    void coutValues(); // ���������� ������� (��� ������ )
};


// ��� �������� ���� 
// �� ������������ ����� ��������� DynamicArray
// � ���� ��������� ���� ���������, ����������, � �����������
// ��� ����������� ����, ��� ����� ��������� ���������, �� �� �� ����������