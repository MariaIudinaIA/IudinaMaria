#include <iostream>

int main()
{
	int i;
	i = 69;
	int number = 72;
	i = 69 + 72;

	int arr[3] = { };
	int* iPointer = &i;

	number = *iPointer;
	*iPointer = 15;
	
	iPointer = &arr[0];
	iPointer = iPointer + 2;
	
	arr[0] = 5;
	*iPointer = 6;

	std::cout << "i: " << i << std::endl;
	std::cout << "number: " << number << std::endl;
	std::cout << "arr[0]: " << arr[0] << std::endl;
	std::cout << "arr[2]: " << arr[2] << std::endl;

	return 0;
}
