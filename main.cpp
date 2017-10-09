#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

int main() {
    //Open a file
//    ofstream outputStream;
//    outputStream.open("array.txt");

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
    int* pointer = &integerArray[0];
    int* endPointer = &integerArray[arraySize-1];
    i = 0;

    //Go through the "pointer array" as a pointer
    while(pointer <= endPointer){
        //       outputStream << "Pointer[" << i << "]: " << *pointer << "\n";
        cout << "Pointer[" << i << "]: " << *pointer << endl;
        pointer++, i++;
    }
    integerList.PrintList();

//    outputStream.close();

    return 0;
}