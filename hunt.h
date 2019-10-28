/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#ifndef HUNT_H
#define HUNT_H

#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;
class Event{
	private:
		string message;
		char sign_of_event;
	public:
		Event();
		virtual string get_message()=0;
		virtual void play_game(char,int,char *)=0;
		~Event();
};

class Wumpus:public Event{
	private:
		string message;
		char sign_of_event;
		bool alive;
	public:	
		Wumpus();
		string get_message();
		bool get_alive();
		void play_game(char,int,char*);
		~Wumpus();
};

class Pit : public Event{
	private:
		string message;
		char sign_of_event;
	public:	
		Pit();
		string get_message();
		void play_game(char,int,char*);
		~Pit();
};

class Gold : public Event{
	private:
		string message;
		char sign_of_event;
	public:	
		Gold();
		string get_message();
		void play_game(char,int,char*);
		~Gold();
};

class Bats:public Event{
	private:
		string message;
		char sign_of_event;
	public:	
		Bats();
		string get_message();
		void play_game(char,int,char*);
		~Bats();
};

#endif
