#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    int arraySize = 2000;
    //Create the array
    int integerArray[arraySize];
    LinkedList integerList;

    //Go through the array and create a random number for each
    int i = -1;
    while(++i < arraySize){
        int randomStuff = rand() % arraySize;

        integerArray[i] = randomStuff;
        integerList.AddNode(randomStuff);
        cout << "Intger[" << i << "]: " << integerArray[i] << endl;
    }

    cout << "------------Start the pointer arithmetic--------------" << endl;

    //Create a pointer
    int* pointer = integerArray;
    int* endPointer = &integerArray[arraySize-1];
    i = 0;

    //Go through the "pointer array" as a pointer
    while(pointer <= endPointer){
        cout << "Pointer[" << i++ << "]: " << *pointer << endl;
        pointer++;
    }
    integerList.PrintList();

    return 0;
}