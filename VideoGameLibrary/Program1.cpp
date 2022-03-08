/*
	Name: Program1.cpp
	Class: CSC1310
	Author: Victor Hugo Battonyai
	Date: 2/18/2021
    Purpose: Driver
*/
#include "VideoGameLibrary.h"
#include "Text.h"
#include "VideoGame.h"

int main() {
    int numGames = 0;
    int choice = 0;
    string fileName;
    bool menu = true;

    
    cout << "How many video games can your library hold?" << endl;
    cin >> numGames;

    VideoGameLibrary* library = new VideoGameLibrary(numGames);

    //Menu Loop
    while(menu == true) {
        cout << "What would you like to do?" << endl;
        cout << "(1)\tLoad video games from file." << endl;
        cout << "(2)\tSave video games to a file." << endl;
        cout << "(3)\tAdd a video game." << endl;
        cout << "(4)\tRemove a video game." << endl;
        cout << "(5)\tDisplay all video games." << endl;
        cout << "(6)\tRemove ALL video games from this Library and end program." << endl;

        cout << "CHOOSE 1-6:\t";
        cin >> choice;

        //Choice authenticator
        while (choice < 1||choice > 6 ) {
            cout << "This is not a valid choice." << endl;
            cout << "CHOOSE 1-6:\ts";
            cin >> choice;
        }
        
        //Menu Switch
        switch(choice) {
            case 1: {
                cout << "What is the name of the file? (example.txt): ";
                cin >> fileName;

                ifstream ifs;
                ifs.open(fileName);

                if(!ifs.good()) {
                    cout << "Sorry, I cannot open your file." << endl;
                }
                else {
                    library->loadVideoGamesFromFile(ifs);
                }
                break;
            }
            case 2: {
                cout << "What do you want to name the file? (example.txt):";
                cin >> fileName;

                ofstream ofs;
                ofs.open(fileName);

                library->saveToFile(ofs);
            
                break;
            }
            case 3: {
                library->addVideoGameToArray();
                break;
            }

            case 4: {
                library->removeVideoGameFromArray();
                break;
            }
            case 5: {
                library->displayVideoGames();
                break;
            }

            case 6: {
                
                delete library;

                cout << "\nGOODBYE!" << endl;

                menu = false;
            }
        }
    }
    return 0;
}