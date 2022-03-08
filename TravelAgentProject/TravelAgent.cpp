/**********************************************************************
	Title:        TravelAgent.cpp
	Author:       Victor Hugo Battonyai De Oliveira
	Date Created: 3/08/2021
	Purpose:      TravelAgent cpp file (Driver with the Main)
***********************************************************************/
#include "Destination.h"
#include "LinkedList.h"

#include <iostream>
#include <string>
#include <fstream>
#include <limits> 
#include <ctime> 


using namespace std;

int main() {
    LinkedList<Destination*> myList;

    cout << "Hello!  My name is Gavin O Cleirigh and I am your professional travel agent, tour director, and guide!" << endl;

    cout << R"(
                                                                                                                                                ./((/(/,
                                                                                                                                            //((((((/.
                                                                                                                                /@@,.,*/((((((((((,
                                                                                                                                /@@//(((/(((((/((//,
                                                                                                                                /@@//((((((((((//(((((/*
                                                                                                                                /@@//(((((((((/((/((/  
                                                                                                                                /@@//(((((((((/(/,
                                                                                                                                /@@//(((((//*
                                                                                                                                (@@/(((/
                                                                                                                                (@@*
                                                                                    /%&#.                                       (@@
                                                                        ,*/##%%&&%%%%%#((.                                      (@@
                                                                    (%&&&%%%%%%%%%%%%%%%%%&%,                                   (@@
                                                                /%&%%%%%%%%%%%%%%%%%%%&%#.                                      (@@
                                                                (%%&&%%%%%%%%%%%%%%%%%#((&#                                     (@@
                                                            /&%%%%&%%%&%//((((((//(((((#&,                                      (@@
                                                            /&%%%%%%#(((//(((((((((((#((%*                                      (@@
                                                            .%&%%%%%((((##/((((((((((/((,                                       (@@
                                                            .*/((%%%%((((((#&#(((((((%#(/.                                     .#@@/  
                                                            /((((/((((((((((((((((#((((((,                                  *(((/(/(#/  
                                                            .,(((((((((((((((((((((#(((((/.                                *(((((#%#(##(.
                                                                ,*/(#((((((((((##(((((((((*                                 ((((((#((###(/.  
                                                                .,%#/((((((((((((((((((/,                                /((((((#(##(#(. 
                                                                    ,(((((((((((((((((/,                                  /((((((%@&/* 
                                                                    ,((((((((((#* ...                                    ((((#((/%@@
                                                                    .,.,/((((((((/.,,....                                *((((((/#@@  
                                                            .,/(((*,.,....,.,/(((*.,(/((/(((///,.                     .,.,,,...**,#@@
                                                    ./((((((((((/((,.,...,.....*,,.*((/(((((((((((((/,                *##*........./         
                                                *(((((/(((((((/((((/.,..,(((((/(%((((((((/(/((((((((((((/,.          *(((((((###*   
                                                ,(((((((((((((((((//((((/(#(((((((#(((((((((((((((((((((((((((((/,.*((((((((((/
    *,      ,/(/,...                           .*(((((((((((((((((((((/((/((/##((/(#(((((((((((((((((((((((((((/(((((((((((((((,  
    *(((/*...  *((((*...                        *(((((((((((((((((((((/(((/((((((#((#/(/((/(/((((((((/(((((((((((((((((((((((((/ 
    ((((((((//*/(((((/...                    *((((((((((((((((((((((((((((/((((((#(//***(((((((((((((((((((((((((((((((((((((  
    .*((((((((((((((((((*                   .*((((((((((((((((((((((((((((/((,(((((((((((((((/((,((  .,**/(((((((((((((((((((
    ,((((((((((((((((((/.                 *((((((((((((((((((((((((((((((((((((((((((((*(((((/,              ,*//((((((((/ 
        .*/((((((((((((((((/,              /(((((((((((((((((((((((((((((((((((((((((((((((((((//, 
            .,/((((((((((((((,..       ./((((((((((((((*/((((((((((((((((/((/(((((((/((/(((/((*                         
                .,((((((((#,..../*.  ./((((((((((((((. ,/(((((((((((((((((((((((((((((((((((/*  
                    .,(((#/.,...*(((((((((((((((((((*.   *((((((((((((((((((((((((((((((((((((*
                        ......,../(((/((((((((((((((    .*((((((((((((((((((((((((((((((((((/(*  
                        ...*((((((((((((((((((/(,       ,/(((((((((((((((((((((((((((((((((((* 
                            ...*((((((((((((((((*       .*/(((((((((((((((((((((((((((((((((((*  
                                .,*(((((((((((/          ,/(((((((((((((((((((((((((((((((((((* 
                                    .,,/(((((*          .*/(((((((((((((((((((((((((((((((((((*   
                                                        ,/(((((((((((((((((((((((((((((((((((*    
                                                        *//((((((((((((((((((((((((((((((((/(*   
                                                        */(((((((((((((((((((((((((((((((((((*    
                                                        ,/(((((((((((((((((((((((((((((((((/*.
                                                        .,*/((((/(((((((((((((((((((((((((((*                           
    )";

    ifstream read;
    read.open("placeFile.txt");

    string place;
    string description;
    float travelCost;
    int dangerLevel;
    string temp;

    Destination * newNode; 

    if(!read.is_open()) {
        cout << "Error, could not read the file...";
    }
    else {
        while(getline(read, temp, '#')){
            place = temp;

            getline(read, temp, '#');
            description = temp;

            getline(read, temp, '#');
            travelCost = stof(temp);

            getline(read, temp, '#');
            dangerLevel = stoi(temp);

            newNode = new Destination(place, description, travelCost, dangerLevel);
            myList.insertNode(newNode);
        }
    }

    for(int i=0; i < myList.getLength(); i++ ) {
        cout << " ********** DESTINATION " << i << " **********" << endl;
        cout << *(myList.getNodeValue(i));
    }

    string response1;
    int response2;
    char response3;
    char response4;

    cout << "Please answer the following four questions and I will determine the place you should travel." << endl;
    
    cout << "\t 1.\t What is your full name?\t";
    getline(cin, response1);

    cout << "\t 2.\t How much money do you make per year? \t";
    cin >> response2;
    while(!cin || (response2 < 0)) {
        cin.clear();
    
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Oops!  You entered something wonky.  Please enter a number with no symbols or commas. " << endl;
        cout << "\t 2.\t How much money do you make per year? \t";

        cin >> response2;
    }

    cout << "\t 3.\t Do you like the taste of fruity pebbles cereal? (y or n)\t";
    cin >> response3;
    while(!cin ||(response3 != 'y' &&  response3 != 'n')) {
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Oops!  You entered something wonky.  Please enter the letter y or n." << endl;
        cout << "\t 3.\t Do you like the taste of fruity pebbles cereal? (y or n)\t";

        cin >> response3;
    }

    cout << "\t 4.\t Is planet Earth flat? (y or n)\t";
    cin >> response4;

    while(!cin || (response3 != 'y' &&  response3 != 'n')) {
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Oops!  You entered something wonky.  Please enter the letter y or n." << endl;
        cout << "\t 3.\t Do you like the taste of fruity pebbles cereal? (y or n)\t";

        cin >> response4;
    }
    int randomNum;
    srand(time(0));
    randomNum = rand()%(myList.getLength());

    cout << endl << endl;
    cout << response1 << ", based on your salary ($" << response2;
    cout  << ") and the fact that you answered '" << response3;
    cout << "' to liking Fruity Pebbles cereal and you answered '" << response4;
    cout << "' to believing the Earth is flat, you are going to travel to the following Destination!" << endl;
    cout << endl;

    cout << *(myList.getNodeValue(randomNum));

    cout << "\nHAVE FUN!!";
}