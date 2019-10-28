/******************************************************
** Program filename: Aiignment4.cpp/hunt_1.cpp
** Author: Sanchit Chopra
** Date: 25-05-2019
** Description: This is one of the required cpp file for this code and contain the funcitons.
** Input: In input we are paaing different parmeters to diferent functions like some functions want the size of the cave entered bythe user, some want the true or false.
** Output: In output, this functions runs and give the desire outputs. 
******************************************************/ 

#include<iostream>
#include"./hunt_1.h"
#include"./hunt.h"

using namespace std;


/*********************************************************************
** Function Name: if_user_to_move
** Parameters: N/A
** Description: This function is alled if the user want to move and change there position to where they want.
** Pre-Conditions: N/A
** Post-Consitions: In output, it changes the location of the user.
*********************************************************************/
void Room::if_user_want_to_move(){	
	if (movement_of_user == 'w'){	//if the user want to move up.
		 if(checking_the_bounds(new_user_horizontal-1,new_user_vertical) == true){	//checking the bounds
			array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event(' ');	//making the user previous position empty
			new_user_horizontal--;	
			checking_event_next_to_user();	//checking the event where the user want to go.
			if(is_game_finished == false)
				array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event('x');//if nothing happens there setting that point event to x.
		}
		else 
			cout<<"Out of bouwds!!!"<<endl;
	}
	if (movement_of_user == 'a'){ //if the user want to move left.
		if (checking_the_bounds(new_user_horizontal,new_user_vertical-1) == true){	//checking the bounds.
			array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event(' ');	//making the previous poition empty.
			new_user_vertical--;
			checking_event_next_to_user();	//checking the event where the user want go.
			if(is_game_finished == false)
				array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event('x');//if nothing happens there seting that point event to x.
		}
		else
			cout<<"Out of bouwds!!!"<<endl;
	}
	if_user_want_to_move_1();
}
/*********************************************************************
** Function Name: if_user_to_move_1
** Parameters: N/A
** Description: This function is alled if the user want to move and change there position to where they want.
** Pre-Conditions: N/A
** Post-Consitions: In output, it changes the location of the user.
*********************************************************************/

void Room::if_user_want_to_move_1(){	
	if (movement_of_user == 'd'){ //if the user want to hit on the right.
		if (checking_the_bounds(new_user_horizontal,new_user_vertical+1) == true){	//checking thebounds
			array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event(' ');//making the previous position empty.
			new_user_vertical++;
			checking_event_next_to_user();	//checking the event where the user want to go.
			if(is_game_finished == false)
				array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event('x');//if nothing hapens there setting that point to x.
		}
		else
			cout<<"Out of bouwds"<<endl;
	}
	if (movement_of_user == 's'){ //if the user want to move down.
		if (checking_the_bounds(new_user_horizontal+1,new_user_vertical) == true){//checking the bounds.
			array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event(' ');//making the previous position empty.
			new_user_horizontal++;
			checking_event_next_to_user();//checking the event where the user want to go.
			if(is_game_finished == false)
				array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event('x');//if nothing happens there setting that point to x.
		}
		else
			cout<<"Out of bounds!!!"<<endl;
	}
}
/*********************************************************************
** Function Name: if_user_want_to_shoot_arrow
** Parameters: N/A
** Description: This function is called if the user want to shoot an arrow and checks that the direction where the user want to shootthe arrrow is not out of bounds.
** Pre-Conditions: N/A
** Post-Consitions: In output, it shoots the arrow to the desire direction.
*********************************************************************/
void Room::if_the_user_want_to_shoot_arrow(){
	bool check = false;
	int count=3,i=1,count_1=3,j=1;
	if (movement_of_user ==  'w'){	//if the user want to hit up.
		while(count > 0){
			if (checking_the_bounds(new_user_horizontal+i,new_user_vertical) == true) //checking the bounds
				if (array_of_cave[new_user_horizontal+i][new_user_vertical]->get_cave_event() == 'w'){//checking the event if it is wumpus.
				cout << "wumpus got killed by your arrow!" << endl;
				check = num_of_wumpus_dead = true;//making the wumpus dead.
				array_of_cave[new_user_horizontal+i][new_user_vertical]->set_cave_event(' ');
				break;
			}
			count--,i++;
		}	
		if(check == false)	
			cout << "You did not killed the wumpus or maybe you were out of bounds." << endl;
	}
	else if (movement_of_user == 'a'){ //if the user want to hit on the left
		while(count_1 > 0){
			if (checking_the_bounds(new_user_horizontal,new_user_vertical-j) == true) //checking the bounds.
				if (array_of_cave[new_user_horizontal][new_user_vertical-j]->get_cave_event() == 'w'){//checking the event if it is wumpus.
				cout << "wumpus got killed by your arrow!" << endl;
				check = num_of_wumpus_dead = true;//making the wumpus dead.
				array_of_cave[new_user_horizontal][new_user_vertical-j]->set_cave_event(' ');
				break;
			}
			count_1--,j++;
		}	
		if(check == false) 
			cout << "You did wot kill the wumpus oryou maybe out of bounds!!" << endl;
	}
	if_the_user_want_to_shoot_arrow_1(check,movement_of_user);
}	
/*********************************************************************
** Function Name: if_user_want_to_shoot_arrow
** Parameters: N/A
** Description: This function is called if the user want to shoot an arrow and checks that the direction where the user want to shootthe arrrow is not out of bounds.
** Pre-Conditions: N/A
** Post-Consitions: In output, it shoots the arrow to the desire direction.
*********************************************************************/
void Room::if_the_user_want_to_shoot_arrow_1(bool check, char movement_of_user){
	int count = 3,i=1,count_1 = 3,j=3;
	if (movement_of_user == 'd') { //if the user want to shoot the arrow on the right.
		while(count > 0){
			if (checking_the_bounds(new_user_horizontal,new_user_vertical+j) == true) //checking the bounds
				if(array_of_cave[new_user_horizontal][new_user_vertical+j]->get_cave_event() == 'w'){//checking the the event.
					cout << "wumpus got killed by your arrow!" << endl;
					check = num_of_wumpus_dead = true;//making the wumpus dead.
					array_of_cave[new_user_horizontal][new_user_vertical+j]->set_cave_event(' ');
					break;
			}
			count--,i++;
		}	
		if(check == false)	
			 cout << "You did wot kill the wumpus!" << endl;
	}
	if (movement_of_user == 's'){
		while(count_1 > 0){ //if the user want to hit down.
			if (checking_the_bounds(new_user_horizontal-j,new_user_vertical) == true) //checking the bounds
				if (array_of_cave[new_user_horizontal-j][new_user_vertical]->get_cave_event() == 'w'){//checking the event.
				cout << "wumpus got killed by your arrow!" << endl;
				check = num_of_wumpus_dead = true;//making the wumpus dead.
				array_of_cave[new_user_horizontal-j][new_user_vertical]->set_cave_event(' ');
				break;
			}
			count_1--,j++;
		}	
		if(check == false)	
			cout << "You did wot kill the wumpus!" << endl;
	}

}

