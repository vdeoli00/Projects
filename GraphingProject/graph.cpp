/*****************************************************************
	Title:  		graph.cpp
	Date:           04-22-2021
	Author: 		Victor Hugo Battonyai
	Purpose:		CSC 1310 Program 4 cpp file
******************************************************************/
#include "GraphList.h"
#include "stack.h"
#include "GraphMatrix.h"

using namespace std;

int main() {
    fstream file;
    string fileName;
    int numVertices;
    Stack <int> stack;

    cout << "Enter the name of the file that contains the graph vertices: ";
    cin >> fileName;
    file.open(fileName);
    file >> numVertices;

    GraphMatrix graph_matrix (numVertices);
    GraphList graph_list (numVertices);

    if(file.is_open()){
        while(!file.eof()){
            int temp1;
            int temp2;
            file >> temp1;
            file >> temp2;
            graph_list.addEdge(temp1,temp2);
            graph_matrix.addEdge(temp1,temp2);
        }
    }
    else {
        cout << "The file you entered could not be opened"<< endl;
    } 

    graph_list.printGraph();
    graph_matrix.printGraph();
    file.close(); 

    int first = 0;
    int cur = 0;

    bool *visited = new bool[numVertices];

    for(int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    stack.push(first);
    cout << "Now traversing & printing graph vertices with DFS."<< endl;
    cout << first << " ";

    while(!stack.isEmpty()) {
        stack.peek(cur);

        if(!visited[cur]) {
            visited[cur] = true;
        }

        for(int i =0; i < numVertices; i++){
            if(graph_matrix.isThereAnEdge(cur,i)&&!visited[i]){
                stack.push(i);
                visited[i] = true;
                cout << i << " ";
                cur = i;
                i = 0;
            }
        }
        stack.pop(cur);
    }
}