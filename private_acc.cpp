/******************************************************
** Program filename: Aiignment4.cpp/private_acc.cpp
** Author: Sanchit Chopra
** Date: 25-05-2019
** Description: This is one of the required cpp file for this code and contains the mutator, accessor and the constructors.
** Input: In input we are paaing different parmeters to diferent functions like some functions want the size of the cave entered by the user, some want the true or false.
** Output: In output, this functions runs and give the desire outputs. 
******************************************************/ 
#include<iostream>
#include"./hunt_1.h"
#include"./hunt.h"

using namespace std;

Gold::Gold(){	//constructor for gold.
	message = "You see a glimmer nearby.";//setting the message for gold.
	sign_of_event = 'g';	//setting the event.
}

string Gold::get_message(){	//accessor for getting message of gold.
	return message;
}

Event::Event(){	//constructor for Event.
	message = " ";	//setting the message for Event.
	sign_of_event = ' ';	//setting event.
}
string Event::get_message(){	//accessor for getting message.
	return message;
}

Bats::Bats(){	//constructor for bats.
	message = "You hear wings flapping.";	//setting the message for bats.
	sign_of_event = 'b';	//setting the event.
}
string Bats::get_message(){	//setting the message for getting message of bats.
	return message;
}
Pit::Pit(){	//constructor for Pits.
	message = "You feel a breeze.";	//setting the message for Pits.
	sign_of_event = 'p';//setting the event.
}
string Pit::get_message(){	//accessor for getting message for pits.
	return message;
}

Wumpus::Wumpus(){	//constructor for Wumpus.
	message = "You smell a terrible stench.";	//setting the message for wumpus.
	alive = true;	//setting the live status of wumpus.
	sign_of_event = 'w';	//setting the event.
}
string Wumpus::get_message(){	//accessore of getting message from wumpus.
	return message;
}

bool Wumpus::get_alive(){	//accessor of getting the live status of wumpus.
	return alive;
}
Room::Room(){	//constructor fotr Room.
	size_of_cave = 0;
	num_of_arrows_used = 3;
	user_choice = 0;
	gold_found = 0;
	user_horizontal_start = user_vertical_start = new_user_horizontal = new_user_vertical = 0;
	movement_of_user = ' ';
	is_game_finished = false;
	is_user_won = false;
	array_of_events = NULL;
	num_of_wumpus_dead = false;
	srand (time(NULL));
	cave_event = ' ';
	player = 'x';
	srand (time(NULL));
}
Event::~Event(){
}
char Room::get_cave_event(){	//accessr of getting the cave event.
	return cave_event;
}
int Room::calculating_random_number(){	//function of calculating arandom number.
	int num = rand()% size_of_cave + 1;
	return num;	
}

int Room::calculating_random_number_1(){//Another function for calculating a random number.
	int num = rand()% size_of_cave + 1;
	return num;
}
string Room::get_message(){	//accessor of getting the messages.
	return array_of_events->get_message();
}
Wumpus::~Wumpus(){
	
}
Gold::~Gold(){
	
}
Pit::~Pit(){
	
}
Bats::~Bats(){
	
}



