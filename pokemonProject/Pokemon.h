/**********************************************************************
	Title:        Pokemon.h
	Author:       Victor Hugo Battonyai De Oliveira
	Date Created: 4/05/2021
	Purpose:      Pokemon Header
***********************************************************************/
#ifndef _POKEMON_H
#define _POKEMON_H

#include <iostream>
#include <string>

using namespace std;

class Pokemon {
    private:
        int indexNum;
        string pokeName;
    
    public:
        /* constructor */
        Pokemon(int num = 0, string name = "none") {
            setID(num);
            setName(name);
        }
        
        /* set pokemon id */
        void setID(int num) {
            indexNum=num;
        }

        /* set pokemon name*/
        void setName(string name) {
            pokeName = name;
        }

        /* get pokemon id */
        int getID() {
            return indexNum;
        }

        /* get pokemon name */
        string getName() {
            return pokeName;
        }

        /* overloaded < operator */
        bool operator <(const Pokemon& member) {
            if (this->indexNum < member.indexNum) {
                return true;
            }
            else {
                return false;
            }
        }

        /* overloaded == operator */
        bool operator ==(const Pokemon& member) {
            if (this->indexNum == member.indexNum) {
                return true;
            }
            else {
                return false;
            }
        }

        /* overloaded friend operator */
        friend ostream & operator << (ostream&  oFS, Pokemon member) {
            oFS << "Pokemon Index Number:  "<<member.indexNum;
            oFS << "\t Name: "<< member.pokeName;
            return oFS;
        }
};

#endif