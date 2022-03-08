/*****************************************************************
	Title:  		graphList.h
	Date:           04-22-2021
	Author: 		Victor Hugo Battonyai
	Purpose:		CSC 1310 Program 4 header file
******************************************************************/
#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class GraphList {
    private:

    struct ListNode {
        int value;
        ListNode* next;
    };

    ListNode **headArray;
    int numEdges;
    int numVertices;

    public:
    
    // Function Name: GraphList
    // Function Purpose: Constructor
    GraphList(int nV) {
        numVertices = nV;
        headArray = new ListNode* [numVertices];

        for(int i = 0; i < numVertices; i++) {
            headArray[i] = NULL;
        }
    }

    // Function Name: ~GraphList
    // Function Purpose: Destructor
    ~GraphList() {
        delete[] headArray;
    }

    // Function Name: addEdge
    // Function Purpose: Adds an Edge
    void addEdge(int verticeOne, int verticeTwo) {
        ListNode *node = new ListNode;

        node -> value = verticeTwo;
        node -> next = NULL;
        if(!headArray[verticeOne]){
            headArray[verticeOne] = node;
        }
        else {
            ListNode *node2 = headArray[verticeOne];
            while(node2 -> next!=NULL){
                node2 = node2 -> next;
            }
            node2 -> next = node;
        }
        numEdges += 1;
    }

    // Function Name: printGraph
    // Function Purpose: Prints Graph
    void printGraph() {
        for(int i = 0; i < numVertices; i++) {
             ListNode *node2 = headArray[i];
             cout << i << "--->";
            while(node2 != NULL){
                cout << node2 -> value << "--->"; 
                node2 = node2 -> next;
            }
            cout << "NULL" << endl;
        }
    }
};
#endif