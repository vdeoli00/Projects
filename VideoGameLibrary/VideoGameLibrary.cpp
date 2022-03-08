/*
	FileName: VideoGameLibrary.cpp
	Class: CSC1310
	Author: Victor Hugo Battonyai
	Date: 2/18/2021
    Purpose:cpp with functions, constructor and destructor
*/
#include "VideoGameLibrary.h"
#include "Text.h"
#include "VideoGame.h"

//Function Name: VideoGameLibrary 
//Purpose: Constructor
VideoGameLibrary::VideoGameLibrary(int max) {
    maxGames = max;
    numGames = 0;
    videoGamesArray = new VideoGame*[maxGames];
}

//Function Name: ~VideoGameLibrary 
//Purpose: Destructor
VideoGameLibrary::~VideoGameLibrary() {

    for (int i = 0; i < numGames; ++i) {
        delete videoGamesArray[i];
    }
    delete[] videoGamesArray;
    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself." << endl;
    
}

//Function Name: resizeVideoGameArray 
//Purpose: Resizes MaxGames by 2 (Allocates new Memory)
void VideoGameLibrary::resizeVideoGameArray() {
    maxGames *=2;

    VideoGame** videoGamesArray2;
    videoGamesArray2 = new VideoGame*[maxGames];

    for(int i = 0; i < numGames; i++) {
        videoGamesArray2[i] = videoGamesArray[i];
    }

    delete[] videoGamesArray;

    cout << "Resizing VideoGameArray from " << maxGames/2 << " to " << maxGames << endl;
    videoGamesArray = videoGamesArray2;

}

//Function Name: addVideoGameToArray 
//Purpose: Adds a Video Game To Array Manually (Users Input)
void VideoGameLibrary::addVideoGameToArray() { 
    if (numGames == maxGames) {
        resizeVideoGameArray();
    }
    char answer[10000];
    int year;
    float stars;
    Text* title;
    Text* platform;
    Text* genre;
    Text* rating;

    cout << "Enter a Video Game title: ";
    cin.ignore();
    cin.getline(answer, 10000);
    title = new Text(answer);

    cout << "\nEnter a Video Game platform:  ";
    cin.getline(answer, 10000);
    platform = new Text(answer);

    cout << "\nEnter a Video Game year:  ";
    cin >> year;
    cin.ignore();

    cout << "\nEnter Video Game GENRE:  ";
    cin.getline(answer, 10000);
    genre = new Text(answer);

    cout << "\nEnter Video Game AGE RATING:  ";
    cin.getline(answer, 10000);
    rating = new Text(answer);

    cout << "\nEnter Video Game USER RATING (out of 100):  ";
    cin >> stars;

    VideoGame* otherGame = new VideoGame(title, platform, year, genre, rating, stars);
    videoGamesArray[numGames] = otherGame;
    numGames++;
}

//Function Name: displayVideoGames 
//Purpose: Prints all Video Games With Details (using printVideoGameDetails)
void VideoGameLibrary::displayVideoGames() {
    if (numGames > 0) {
        for(int i = 0; i < numGames; i++) {
            cout << "-------------- ";
            cout << "Video Game " << i+1;
            cout << " --------------" << endl;
            cout << endl;

            videoGamesArray[i]->printVideoGameDetails();
            cout << "------------------------------------------" << endl;
            cout << endl;
        }
    }
    else{
        cout << "No video games in library" << endl;
    }
}

//Function Name: displayVideoGameTitles 
//Purpose: Print Video Game Tittles
void VideoGameLibrary::displayVideoGameTitles() {
    cout << endl;
    if (numGames >0) {
        for(int i = 0; i < numGames; i++) {
            cout << "Video Game " << i+1 << ":  ";
            videoGamesArray[i]->getVideoGameTitle()->displayText();
        }
    }
    else{
        cout << "No video game title in library" << endl;
    }

}

//Function Name: printVideoGamloadVideoGamesFromFileeDetails 
//Purpose: Load a Video Game From A File Given the Name(example.txt)
void VideoGameLibrary::loadVideoGamesFromFile(ifstream& file) {
    int num;
    char temp[10000];
    int year;
    float stars;
    Text* title;
    Text* platform;
    Text* genre;
    Text* rating;

    cout << "\nVideo Games added: " << endl;
    while(!file.eof()){
        file.getline(temp, 10000);
        title = new Text(temp);
        title->displayText();


        file.getline(temp, 10000);
        platform = new Text(temp);

        file >> year;
        file.ignore();

        file.getline(temp, 10000);
        genre = new Text(temp);

        file.getline(temp, 10000);
        rating = new Text(temp);

        file >> stars;
        file.ignore();

        VideoGame* otherGame = new VideoGame(title, platform, year, genre, rating, stars);

        if (numGames == maxGames) {
            cout << endl;
            resizeVideoGameArray();
            cout << endl;

        }

        videoGamesArray[numGames] = otherGame;
        numGames++;
        num++;
    }
    cout << num << " video games were read from the file & added to the library." << endl << endl;
    file.close();
}

//Function Name: removeVideoGameFromArray 
//Purpose: Remove a chosen Video Game From Array
void VideoGameLibrary::removeVideoGameFromArray() {
    if (numGames <= 1) {
        cout << "\nThe library has to have at least 1 video Game" << endl;
        return;
    }
    int choice;

    cout << "You have the following Video Games: " << endl;
    this->displayVideoGameTitles();
    cout << endl;

    cout << "Enter a number from 1 to " << numGames << ": " << endl;
    cin >> choice;
    cin.ignore();

    cout << "The video game: ";
    videoGamesArray[choice-1]->getVideoGameTitle()->displayText();
    cout << "has been successfully deleted." << endl;

    delete videoGamesArray[choice-1];

    for(int i = choice-1; i < numGames-1; i++) {
        videoGamesArray[i] = videoGamesArray[i+1];
    }
    numGames--;
}

//Function Name: saveToFile 
//Purpose: Use printVideoGameDetailsToFiles to save Video Games to File
void VideoGameLibrary::saveToFile(ofstream& fileName) {

    for(int i = 0; i < numGames; i++) {
        videoGamesArray[i]->printVideoGameDetailsToFiles(fileName);
    }
    fileName.close();
}