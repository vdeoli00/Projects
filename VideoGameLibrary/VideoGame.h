/*
	FileName: VideoGame.h
	Class: CSC1310
	Author: Victor Hugo Battonyai
	Date: 2/18/2021
    Purpose: Header file for Videogame.cpp
*/
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Text.h"

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class VideoGame{

    private:
    Text* title;
    Text* platform;
    int year;
    Text* genre;
    Text* ageRating;
    float userRating;

    public:
    VideoGame(Text*, Text*, int, Text*, Text*, float);
    ~VideoGame();
    void printVideoGameDetails();
    void printVideoGameDetailsToFiles(ofstream&);
    Text* getVideoGameTitle() const;

};

#endif