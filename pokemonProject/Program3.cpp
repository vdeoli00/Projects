/**********************************************************************
	Title:        Program3.cpp
	Author:       Victor Hugo Battonyai De Oliveira
	Date Created: 4/05/2021
	Purpose:      Driver for Program 3
***********************************************************************/
#include "BinaryTree.h"
#include "Pokemon.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    BinaryTree<Pokemon> binaryTree; //binary tree object
    int pokemonNum = 0, count = 0; //how many pokemon and index number
    ifstream inFS; //fstream operator
    string pokemon;

    inFS.open("pokedex.txt"); //open file

    /* check if open */
    if (!inFS.is_open()) {
        cout << "File failed to open, ending program." << endl;
        exit(1);
    }
    /* else insert pokemon into binary tree */
    else {
        do {
            getline(inFS, pokemon, '#');
            pokemonNum = stoi(pokemon);
            getline(inFS, pokemon, '#');
            Pokemon member(pokemonNum, pokemon);
            
            if (!binaryTree.searchNode(member)) {
                binaryTree.insertNode(member);//adds the node if it is not in the tree
                cout << "Inserting Pokemon with index " << pokemonNum << " into the Pokedex!" << endl;
                count++;
            }
            else {
                cout << "Oops, Pokemon with index " << pokemonNum << " is already in the Pokedex!" << endl;
            }
        } while (!inFS.eof());
    }

    cout << "\n" << count << " Pokemon have been added to the pokedex!"<< endl;

    cout << "\n\n********************POKEDEX:********************" << endl <<endl;
	binaryTree.displayInOrder();

    inFS.close();
    return 0;
}