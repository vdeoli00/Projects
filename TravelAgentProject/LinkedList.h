/**********************************************************************
	Title:        LinkedList.h
	Author:       Victor Hugo Battonyai De Oliveira
	Date Created: 3/08/2021
	Purpose:      LinkedList header file (With template and LinkedList class)
***********************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>

using namespace std;

template <typename Template>

class LinkedList {
    private:
    struct ListNode {
        Template value;
        ListNode *next;
    };
    ListNode *head;
    ListNode *tail;
    int numNodes;

    public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        numNodes = 0;
    }
    ~LinkedList();

    int getLength();
    Template getNodeValue(int);
    void insertNode(Template);
};


//Function Name:getLength()
//Purpose: Returns numNodes (Length)
template <typename Template>
int LinkedList<Template>::getLength(){
    return numNodes;
}

//Function Name:getNodeValue()
//Purpose: Gets Node Values
template <typename Template>
Template LinkedList<Template>::getNodeValue(int position){
    int currentPos = 0;

	ListNode *nodePtr = new ListNode;
    nodePtr = head;


    while(currentPos <= position ) {
        if(currentPos == position) {
            return nodePtr->value;
        }
        else {
            currentPos++;
            nodePtr = nodePtr->next;
        }
    }
    return NULL;
}

//Function Name:insertNode()
//Purpose: Inserts Node Values In alphabetical Order
template <typename Template>
void LinkedList<Template>::insertNode(Template nodeValue){
    
    ListNode *nodePtr = new ListNode;
    ListNode *previousNode = new ListNode;
	ListNode *newNode = new ListNode;

	newNode->value = nodeValue;
    numNodes++;
    newNode->next = NULL;

    if(!head) {
        head = newNode;
		tail = newNode;
    }
    else{

        nodePtr = head;
        if(*(newNode->value) < *(head->value)) {
            newNode->next = head;
            head = newNode;

            return;
        }
        else if(*(tail->value) < *(newNode->value)  ) {
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;

            return;
        }
        else {
            while(*(nodePtr->value) < *(newNode->value)) {
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

//Function Name:~LinkedList()
//Purpose: Desctructor
template <typename Template>
LinkedList<Template>::~LinkedList() {
	ListNode *nodePtr = new ListNode;
	ListNode *nextNode = new ListNode;

	nodePtr = head;

	while (nodePtr != NULL) {
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}


}

#endif