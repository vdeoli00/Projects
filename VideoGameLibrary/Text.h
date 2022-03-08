/*
	FileName: Text.h
	Class: CSC1310
	Author: Victor Hugo Battonyai
	Date: 2/18/2021
    Purpose: Header file for Text.cpp
*/
#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;




class Text{

    private:
    int textLength;
    const char* textArray;

    public:
    Text(const char*);
    ~Text();
    void displayText();
    const char* getText();
    int getLenght();

};

#endif