//
// Created by Recreational on 10/8/2017.
//
#include <cstdlib>
#include <iostream>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
    nodeCount = 0;
    headNode = nullptr;
    currentNode = nullptr;
    tempNode = nullptr;
}

//Add the Node to the list
void LinkedList::AddNode(int nodeToAdd) {
    nodePointer node = new Node;
    node->next = nullptr;
    node->data = nodeToAdd;

    //Check if our head has been set yet
    if(headNode != nullptr){
        currentNode = headNode;
        //Check if we are the last Node in the list
        while(currentNode->next != nullptr){
            currentNode = currentNode->next;
        }

        //Set the added Node to the end of the list
        currentNode->next = node;
    }else{
        headNode = node;
    }

    nodeCount++;
}

//Delete the Node from the list
void LinkedList::DeleteNode(int nodeToDelete) {
    nodePointer deletePointer = nullptr;
    tempNode = headNode;
    currentNode = headNode;

    while(currentNode != nullptr && currentNode->data != nodeToDelete){
        tempNode = currentNode;
        currentNode = currentNode->next;
    }

    if(currentNode == nullptr){
        cout << nodeToDelete << " was not in the list\n";
        delete deletePointer;
    }else{
        deletePointer = currentNode;
        currentNode = currentNode->next;
        tempNode->next = currentNode;
        //Check if we are the head Node
        if(deletePointer == headNode){
            headNode = headNode->next;
            tempNode = nullptr;
        }

        delete (deletePointer);
        cout << "The value " << nodeToDelete << " was deleted\n";

        nodeCount--;
    }
}

//Print out the data from the linked list
void LinkedList::PrintList() {
    currentNode = headNode;
    int tempCount = 0;

    while(currentNode != nullptr){
        cout << "LinkedList [" << tempCount << "]: " << currentNode->data <<  endl;
        currentNode = currentNode->next;

        tempCount++;
    }
}