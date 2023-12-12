#include "dynamicArray.h"

DynamicArray::DynamicArray(int capacity) { // êîíñòðóêòîðà äëÿ DynamicArray
    this->values = new int[capacity]; // Âûäåëÿåòñÿ ïàìÿòá äëÿ ìàññèâà
    this->capacity = capacity; // Ïðèñâàèâàíèå çíà÷åíèå
}

void DynamicArray::coutValues() { // Îïðåäåëåíèå ìåòîäà
    for (int i = 0; i < this->length; i++) { // Öèêë íà÷èíàÿ ñ 0 è äî çíà÷åíèÿ ïåðåìåííîé äëèíû
        std::cout << this->values[i] << " ";
    }
    std::cout << std::endl << this->capacity << std::endl;
}

 
// â ýòîì ôðàãìåíòå óæå ñîçäàåòñÿ ìåòîä ðåàëèçàöèè ñòðóêòóðû DynamicArray
