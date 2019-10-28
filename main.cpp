/******************************************************
** Program Filename : Assignment4.cpp
** Author: Sanchit Chopra
** Date: 25-05-2019
** Description: This file is the main file in which there is a main function which calls the required functions and the game runs. 
** Input: The user has to enter the size of the cave and whether the user wants to play normally or in debug mode as an input through the command line argument.
** Output: The program tells whether the user won or lost the game.
******************************************************/ 
#include <iostream>
#include <curses.h>
#include <stdio.h> 
#include<cstring>
#include"./hunt.h"
#include "./hunt_1.h"

using namespace std;

int main(int argc, char **argv){
	Room r;	//creating an object of class room.
	Event *play =NULL;
	play = &r;		//Saving the address of the object created to a pointer of the parent class.
	char option;
	int dimensions = atoi (argv[1]);	//converting the argument into integer.
	if (dimensions < 4){	//if the user enter the size of the cave less than 4.
		do{	
			cout << "Error, you must enter a size greater than 4. Try again: ";
			cin >> dimensions;
		}while(dimensions < 4);
	}
	cout << "Good Morninng!!!" << endl;
	cout<<"You are going to play a game in which you have to hunt for gold and kill the wumpus and exit from the cave"<<endl;
	system("stty raw");
	cout<<"Do you want to play yourself(y) or you want to make the computer play for you(n)?";
	option = getchar();
	system("stty cooked");
	cout<<endl;
	play->play_game(option,dimensions,argv[2]);		//Calling the function.
	cout<<"Thank You For playing..."<<endl;
	cout<<"Have a Nice Day!!!"<<endl;	
	return 0;
}
