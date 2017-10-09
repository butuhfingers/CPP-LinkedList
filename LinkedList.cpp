//
// Created by Recreational on 10/8/2017.
//
#include <cstdlib>
#include <iostream>
#include <fstream>

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


// sorts the linked list by changing next pointers (not data)
void MergeSort(struct Node** headRef)
{
    struct Node* head = *headRef;
    struct Node* a;
    struct Node* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return(result);
}
void FrontBackSplit(struct Node* source,
                    struct Node** frontRef, struct Node** backRef)
{
    struct Node* fast;
    struct Node* slow;
    if (source==NULL || source->next==NULL)
    {
        /* length < 2 cases */
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;

        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        /* 'slow' is before the midpoint in the list, so split it in two
          at that point. */
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

//Print out the data from the linked list
void LinkedList::PrintList() {
    ofstream outputStream;
    outputStream.open("array.txt");


    currentNode = headNode;
    int tempCount = 0;

    while(currentNode != nullptr){
        outputStream << "LinkedList [" << tempCount << "]: " << currentNode->data <<  "\n";
        cout << "LinkedList [" << tempCount << "]: " << currentNode->data <<  endl;
        currentNode = currentNode->next;

        tempCount++;
    }

    outputStream.close();
}