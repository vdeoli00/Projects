/*
	FileName: VideoGame.cpp
	Class: CSC1310
	Author: Victor Hugo Battonyai
	Date: 2/18/2021
    Purpose: cpp with functions, constructor and destructor
*/
#include "VideoGame.h"
#include "Text.h"

//Function Name: VideoGame
//Purpose: Constructor
VideoGame::VideoGame(Text* titl, Text* plat, int yea, Text* gen, Text* ageR, float userR) { 
    title = titl;
    platform= plat;
    year = yea;
    genre = gen;
    ageRating = ageR;
    userRating = userR;
}

//Function Name: ~VideoGame
//Purpose: Destructor
VideoGame::~VideoGame() {
    delete title;
    delete platform;
    delete genre;
    delete ageRating;
    
    cout << "VideoGame destructor: Released memory for title, platform, genre, & rating." << endl;
}

//Function Name: printVideoGameDetails 
//Purpose: Display Video Game Details (Title, Year, Platform, Genre, AgeRating, userRating)
void VideoGame::printVideoGameDetails() {
    cout << "Video Game title: ";
    title->displayText();

    cout << "Year: ";
    cout << year;
    cout << endl;

    cout << "Video Game platform: ";
    platform ->displayText();

    cout << "Genre: ";
    genre->displayText();

    cout << "Age Rating: ";
    ageRating->displayText();

    cout << "User Rating: ";
    cout << userRating;
    cout << endl;

}

//Function Name: printVideoGameDetailsToFiles
//Purpose: Print Video Game Details To Files (Title, Year, Platform, Genre, AgeRating, userRating)
void VideoGame::printVideoGameDetailsToFiles(ofstream& outfile) {
    char temp[10000];
    
    strncpy(temp, title->getText(), 10000);
    outfile << temp << endl;

    outfile << year << endl;

    strncpy(temp, platform->getText(), 10000);
    outfile << temp << endl;

    strncpy(temp, genre->getText(), 10000);
    outfile << temp << endl;

    strncpy(temp, ageRating->getText(), 10000);
    outfile << temp << endl;

    outfile << userRating << endl;
}

//Function Name: getVideoGameTitle
//Purpose: Return Title
Text* VideoGame::getVideoGameTitle() const {
    return title;
}