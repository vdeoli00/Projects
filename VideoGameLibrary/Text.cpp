/*
	FileName: Text.cpp
	Class: CSC1310
	Author: Victor Hugo Battonyai
	Date: 2/18/2021
    Purpose:cpp with functions, constructor and destructor
*/
#include "Text.h"

//Function Name: Text
//Purpose: Constructor
Text::Text(const char* str) {
    textLength = strlen(str);
    char* string2 = new char [textLength + 1];
    strcpy(string2, str);
    textArray = string2;
}

//Function Name: ~Text
//Purpose: Desctructor
Text::~Text() {
    delete[] textArray;
    cout << "Text destructor: Released memory for textArray." << endl;
}

//Function Name: displayText
//Purpose: Display a Text & (endl)
void Text::displayText() {
    cout << textArray << endl;
}

//Function Name: getText
//Purpose: Get text (from TextArray)
const char* Text::getText() {
    return textArray;
}

//Function Name: getLength
//Purpose: Get Length (from TextLength)
int Text::getLenght() {
    return textLength;
}