//
// Created by Recreational on 10/8/2017.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


class LinkedList {
private:
    typedef struct Node{
        int data;
        Node* next; //Create a pointer to the next Node in the list
    } * nodePointer;
    //Create a type definition of a Node pointer

    int nodeCount;
    nodePointer headNode;
    nodePointer currentNode;
    nodePointer tempNode;

public: //This is where the functions go
    LinkedList();
    void AddNode(int nodeToAdd);
    void DeleteNode(int nodeToDelete);
    void PrintList();
};


#endif //LINKEDLIST_LINKEDLIST_H
