/******************************************************
** Program filename: Aiignment4.cpp/private_acc_1.cpp
** Author: Sanchit Chopra
** Date: 25-05-2019
** Description: This is one of the required cpp file for this code.
** Input: In input we are paaing different parmeters to diferent functions like some functions want the size of the cave entered by the user, some want the true or false.
** Output: In output, this functions runs and give the desire outputs. 
******************************************************/ 


#include<iostream>
#include"./hunt.h"
#include"./hunt_1.h"

using namespace std;


/*********************************************************************
** Function Name: play_game
** Parameters: int,char*
** Description: This function is virtual function of main class and is performing the polymorphism by saving the child class addressin the parent class pointer. 
** Pre-Conditions: N/A.
** Post-Consitions: In output, it runs the child class function.
*********************************************************************/

void Event::play_game(char option,int num,char *argv){
	Room r;	//creating an object of room
	Event *e1 = &r;//saving the address of that object into parent class ppointer.
	e1->play_game(option,num,argv);	//calling the function from that pointer.
}

/*********************************************************************
** Function Name: set_cave_event
** Parameters: char
** Description: This function is checking what the is the event and according to that is adding into the array.
** Pre-Conditions: Passing the event which we have to add to the array.
** Post-Consitions: In output, it adds the event to the array.
*********************************************************************/

void Room::set_cave_event(char event_in_cave){
	this->cave_event = event_in_cave;
	if (cave_event == 'g'){	//if the evnt is gold.
		array_of_events  =  new Gold;
	}
	if (cave_event == 'w'){	//if the event is wumpus.
		array_of_events = new Wumpus;
	}
	if (cave_event == 'b'){	//if the event is bats.
		array_of_events = new Bats;
	}
	if (cave_event == 'p'){	//if ther event is pit.
		array_of_events = new Pit;
	}
	if (cave_event == ' '){
		array_of_events = NULL;
	}
}
/*********************************************************************
** Function Name: showing_messages_to_user
** Parameters: N/A
** Description: This function is checking the surrondings of the user, if they are in bounds and then if in the surronding is anything then printing that event.
** Pre-Conditions: N/A.
** Post-Consitions: In output, it tells the user of they have something near them.
*********************************************************************/
void Room::showing_messages_to_user(){	
	if (checking_the_bounds(new_user_horizontal, new_user_vertical-1) == true)//checkig the bounds 
		if (array_of_cave[new_user_horizontal][new_user_vertical-1]->get_cave_event() != ' ')//checking if the event is not empty.
			cout << array_of_cave[new_user_horizontal][new_user_vertical-1]->get_message() << endl;	//printing the message of the event there.
	if (checking_the_bounds(new_user_horizontal, new_user_vertical+1) == true) //checking the bounds
		if (array_of_cave[new_user_horizontal][new_user_vertical+1]->get_cave_event() != ' ')//checking if the event is not empty.
			cout << array_of_cave[new_user_horizontal][new_user_vertical+1]->get_message() << endl;//printing the message of the event there.
	if (checking_the_bounds(new_user_horizontal-1, new_user_vertical) == true) //checking the bounds
		if (array_of_cave[new_user_horizontal-1][new_user_vertical]->get_cave_event() != ' ')//checking if the event is not empty.
			cout << array_of_cave[new_user_horizontal-1][new_user_vertical]->get_message() << endl;//printing the message of the event here.
	if (checking_the_bounds(new_user_horizontal+1, new_user_vertical) == true) //checking the bounds
		if (array_of_cave[new_user_horizontal+1][new_user_vertical]->get_cave_event() != ' ')//checking if the event is not empty.
			cout << array_of_cave[new_user_horizontal+1][new_user_vertical]->get_message() << endl;//printing the message of the event here.
}
/*********************************************************************
** Function Name: play_game
** Parameters: int,char*
** Description: This function is virtual function of main class and is performing the polymorphism by saving the child class addressin the parent class pointer. 
** Pre-Conditions: N/A.
** Post-Consitions: In output, it runs the child class function.
*********************************************************************/

void Wumpus::play_game(char option,int num,char *argv){
	Wumpus w;//creating the object
	Event *e1 = &w;//saving the address of that class in parent class pointer.
	cout<<e1->get_message()<<endl;//printing the message.
	e1 = NULL;
}

/*********************************************************************
** Function Name: play_game
** Parameters: int,char*
** Description: This function is virtual function of main class and is performing the polymorphism by saving the child class addressin the parent class pointer. 
** Pre-Conditions: N/A.
** Post-Consitions: In output, it runs the child class function.
*********************************************************************/

void Bats::play_game(char option,int num,char *argv){
	Bats b;//creating the object.
	Event *e1 = &b;//saving the address of that class in parent class pointer.
	cout<<e1->get_message()<<endl;//printing the message.
	e1 = NULL;
}

/*********************************************************************
** Function Name: play_game
** Parameters: int,char*
** Description: This function is virtual function of main class and is performing the polymorphism by saving the child class addressin the parent class pointer. 
** Pre-Conditions: N/A.
** Post-Consitions: In output, it runs the child class function.
*********************************************************************/

void Pit::play_game(char option,int num,char *argv){
	Pit p;//creating the object.
	Event *e1 = &p;//saving the address of that class in parent class pointer.
	cout<<e1->get_message()<<endl;//printig the message.
	e1 = NULL;
}

/*********************************************************************
** Function Name: play_game
** Parameters: int,char*
** Description: This function is virtual function of main class and is performing the polymorphism by saving the child class addressin the parent class pointer. 
** Pre-Conditions: N/A.
** Post-Consitions: In output, it runs the child class function.
*********************************************************************/

void Gold::play_game(char option,int num,char *argv){
	Gold g;//creating the object.
	Event *e1 = &g;//saving the address of that class in parent class pointer.
	cout<<e1->get_message()<<endl;//printing the message.
	e1 = NULL;
}
/*********************************************************************
** Function Name: AI_class
** Parameters: N/A
** Description: This function choosing whether to move orshoot the arrow instead of asking the user 
** Pre-Conditions: N/A.
** Post-Consitions: In output, it tells us the choice instead of getting the user.
*********************************************************************/

char Room::AI_class(){
	char array[10] = {'1','1','2','2','1','2','1','1','2','2'};
	int num = rand()%10;	
	char count = array[num];
	return count;
}
/*********************************************************************
** Function Name: AI_move_shoot
** Parameters: N/A
** Description: This function choose where to move or shoot the arrow instead of letting the user think about it.
** Pre-Conditions: N/A.
** Post-Consitions: In output, it tels the direction where the user will move.
*********************************************************************/

void Room::AI_class_move_shoot(){
	char array[5] = {'w','a','s','d'};
	int num = rand()%4+1;
	movement_of_user = array[num];	
	if(array_of_cave[new_user_horizontal][new_user_vertical+1]->get_cave_event() == 'w')
		movement_of_user = 'd';
	if(array_of_cave[new_user_horizontal][new_user_vertical-1]->get_cave_event() == 'w')
		movement_of_user = 'a';
	if(array_of_cave[new_user_horizontal+1][new_user_vertical]->get_cave_event() == 'w')
		movement_of_user = 'w';
	if(array_of_cave[new_user_horizontal-1][new_user_vertical]->get_cave_event() == 'w')
		movement_of_user = 's';
}

