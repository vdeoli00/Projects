/*
	FileName: VideoGameLibrary.h
	Class: CSC1310
	Author: Victor Hugo Battonyai
	Date: 2/18/2021
    Purpose:Header file for VideogameLibrary.cpp
*/
#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include "VideoGame.h"
#include "Text.h"


#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class VideoGameLibrary{

    private:
    VideoGame ** videoGamesArray;
    int maxGames;
    int numGames;

    void resizeVideoGameArray();
    public:
    VideoGameLibrary(int);
    ~VideoGameLibrary();

    void addVideoGameToArray();
    void displayVideoGames();
    void displayVideoGameTitles();

    void loadVideoGamesFromFile(ifstream&);
    void removeVideoGameFromArray();
    void saveToFile(ofstream&);
};

#endif