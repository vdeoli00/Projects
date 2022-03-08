/*****************************************************************
	Title:  		graphMatrix.h
	Date:           04-22-2021
	Author: 		Victor Hugo Battonyai
	Purpose:		CSC 1310 Program 4 header file
******************************************************************/
#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class GraphMatrix {
    private:
    int numvertices;
    int **vertexMatrix;
    int numEdges = 0;

    public:
        
        // Function Name: GraphMatrix
        // Function Purpose: Constructor
        GraphMatrix(int nV){
            numvertices = nV;
            vertexMatrix = new int*[numvertices];
            for(int i = 0; i < numvertices; i++){
                vertexMatrix[i] = new int[numvertices];
            }
            for(int i = 0; i < numvertices; i++){
                for(int k = 0; k < numvertices; k++){
                    vertexMatrix[i][k]=0;
                }
            }
        }
    
        // Function Name: ~GraphMatrix
        // Function Purpose: Destructor
        ~GraphMatrix(){
            delete[] vertexMatrix;
        }

        // Function Name: addEdge
        // Function Purpose: adds an Edge
        void addEdge(int vertexOne, int vertexTwo) {
            if(vertexMatrix[vertexOne][vertexTwo]==0) {
                numEdges += 1;
            }
            vertexMatrix[vertexOne][vertexTwo]=1;
        }

        // Function Name: printGraph
        // Function Purpose: Prints Graph
        void printGraph(){
            for(int i = 0; i < numvertices; i++) {
                for(int k = 0; k < numvertices; k++) {
                    cout << vertexMatrix[i][k] << " ";
                
                }
                cout << endl;
            }
        }

        // Function Name: getFirstVertex
        // Function Purpose:  Gets the First Vertex
        int getFirstVertex() {
            int first_vertex = 0;
            bool is_first = false;

            while(!is_first && first_vertex <= numvertices) {
                is_first = true;
                for(int i = 0; i < numvertices; i++) {
                    if(vertexMatrix[i][first_vertex]==1) {
                        is_first=false;
                    }
                }
                first_vertex += 1;
            }
            return first_vertex;
        }

        // Function Name: isThereAnEdge
        // Function Purpose: Checks if there is an Edge (Bool)
        bool isThereAnEdge(int row, int column) {
            if(vertexMatrix[row][column]==1) {
                return true;
            }
            return false;
        }
};
#endif