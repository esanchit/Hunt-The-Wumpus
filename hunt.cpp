/******************************************************
** Program filename: Aiignment4.cpp/hunt.cpp
** Author: Sanchit Chopra
** Date: 25-05-2019
** Description: This is one of the required cpp file for this code and contain the funcitons.
** Input: In input we are paaing different parmeters to diferent functions like some functions want the size of the cave entered bythe user, some want the true or false.
** Output: In output, this functions runs and give the desire outputs. 
******************************************************/ 
#include<iostream>
#include "./hunt_1.h"
#include"./hunt.h"
#include<stdio.h>
#include<curses.h>
#include<vector>
#include<string>
using namespace std;

/*********************************************************************
** Function Name: set_array_of_cave
** Parameters: int
** Description: This function is making the required 2d vector of the cave.
** Pre-Conditions: As input , we pass the the size of the cave the user entered through command line argument.
** Post-Consitions: In output, it gives us the required vector of the cave which we can use.
*********************************************************************/
void Room::set_array_of_cave(int num){
	size_of_cave = num;		//making the size of the cave equal to what the user want.
	for(int i =1;i<=size_of_cave+2;i++){
		for(int j =1;j<=size_of_cave+2;j++){
			tmp.push_back(new Room);	
		}
		array_of_cave.push_back(tmp);
		tmp.clear();
	}
}

/*********************************************************************
** Function Name: set_event_in_array_of_cave
** Parameters: N/A
** Description: This function is setting each event at different place of that 2d vector of cave we created.
** Pre-Conditions: Pass the the size of the cave the user entered through command line argument.
** Post-Consitions: In output, it gives us the requirede vector of the cave which we can use.
*********************************************************************/
void Room::set_event_in_array_of_cave(){
	user_horizontal_start = new_user_horizontal = calculating_random_number();//calulating a random number
	array_of_cave[calculating_random_number()][calculating_random_number()]->set_cave_event('w');//setting wumpus in the cave.
	array_of_cave[calculating_random_number_1()][calculating_random_number_1()]->set_cave_event('g');//setting gold in the cave.
	array_of_cave[calculating_random_number()][calculating_random_number()]->set_cave_event('b');//setting bats in the cave.
	user_vertical_start = new_user_vertical = calculating_random_number();//calulaing a random number.
	array_of_cave[calculating_random_number_1()][calculating_random_number_1()]->set_cave_event('b');//setting  bats in the cave.
	array_of_cave[calculating_random_number()][calculating_random_number()]->set_cave_event('p');//setting pits in the cave.
	array_of_cave[calculating_random_number_1()][calculating_random_number_1()]->set_cave_event('p');//setting pits in the cave.
	array_of_cave[user_horizontal_start][user_vertical_start]->set_cave_event('x');//setting the user position.
	cout<<"This is your starting position, remember it you have tocome back through it, if you didn't you lost"<<endl;
}
/*********************************************************************
** Function Name: printing_cave_if_false
** Parameters: char *
** Description: This function is getting the command line argument(true/false) and depending upon that is printing the cave
** Pre-Conditions: We as input are assing the true/false command enterd by the user in the starting.
** Post-Consitions: In output, it prints the cave depending upon the command entered by the user.
*********************************************************************/
void Room::printing_cave_if_false(char *argv){
	string user_choice(argv);char event;int a =1;
	if(user_choice == "false"){	//if the user say false in the 2 command line argument.
		for (int i = 1; i <= size_of_cave+1; i++){
			for (int j = 1; j <= size_of_cave+1; j++){
				if(j != size_of_cave+1)
					cout<<"+---";
				else
					cout<<"+";
			}
			cout<<endl;
			if(i == size_of_cave+1)
				break;
			int count = 3;
			while(count > 0){
				for(int k=1;k <= size_of_cave+1;k++){
					if(array_of_cave[i][k]->get_cave_event() == 'x' && count == 2){	//only the user location will be displayed, other will remain hidden.
						cout<<"|"<<" * ";
					}else	
						cout<<"|"<<"   ";
				}
				cout<<endl;
				count--;
			}
				
		}
	}
	printing_cave_if_true(user_choice);	//if the false one, is not executed than it must be true.
}

/*********************************************************************
** Function Name: printing_cave_if_true
** Parameters: string
** Description: This function is getting the command line argument(true/false) and depending upon that is printing the cave
** Pre-Conditions: We as input are passing the user choice to this function.
** Post-Consitions: In output, it prints the cave depending upon the command entered by the user.
*********************************************************************/
void Room::printing_cave_if_true(string user_choice){
	if(user_choice == "true"){	//if false was not executed than the true will be.
		for (int i = 1; i <= size_of_cave+1; i++){
			for (int j = 1; j <= size_of_cave+1; j++){
				if(j != size_of_cave+1)
					cout<<"+---";
				else
					cout<<"+";
			}
			cout<<endl;
			if(i == size_of_cave+1)
				break;
			int count = 3;
			while(count > 0){
				for(int k=1;k <= size_of_cave+1;k++){
					if(count == 2)
						cout<<"|"<<" "<<array_of_cave[i][k]->get_cave_event()<<" ";//printing all the events to the user.	
					else
						cout<<"|"<<"   ";
				}	
				cout<<endl;
				count--;
			}
		}
	}
}

/*********************************************************************
** Function Name: checking_event_next_to_user
** Parameters: N/A
** Description: This function is called when the user moves than this function checks the events where tahe user went.
** Pre-Conditions: We are not passing but in the function we get the event of thatplace and check what was that.
** Post-Consitions: In output, it tells the user where the user went and what happened with the user.
*********************************************************************/

void Room::checking_event_next_to_user(){
	char check =  array_of_cave[new_user_horizontal][new_user_vertical]->get_cave_event();
	if (check == 'g'){	//if there was gold in the room and the user went there.
		cout << "Congratulatiows!!!You fouwd a gold from the room" << endl;
		gold_found++;	//adding the gold.
	}
	if (check == 'w'){	//if the user entered where there was wumus , then the game is finsihed.
		array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event(' ');
		cout<< "Oh noo..You ewtered the room, presewt with wumpus awd you made him wake awd he killed you and you lost..." << endl;
		is_game_finished = true;
	}
	if (check == 'p'){//if the user enter the roo, which had pit, then als the game finished.
		array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event(' ');
		cout << "Oh noo...You ewtered the room with bottomless pit. You lost!!!Sorry" << endl;
		is_game_finished = true;
	}
	if (check == 'b'){//if the user enter the room with bats.
		cout << "You went to the room, where bats were present awd wow they took you too new place..." << endl;
		array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event(' ');
		new_user_horizontal = calculating_random_number();
		new_user_vertical = calculating_random_number();
		array_of_cave[new_user_horizontal][new_user_vertical]->set_cave_event('x');
	}
}

/*********************************************************************
** Function Name: checking_the_bounds
** Parameters: int,int
** Description: This function is called when the user wants to move or shoot an arrow, this checks the user is within the bounds.
** Pre-Conditions: In input, we are pasiing the function the position of the user and cheking that if the task user wants to do, can be done or not.
** Post-Consitions: In output, it tells the user if they can do that tals or not.
*********************************************************************/
bool Room::checking_the_bounds(int x, int y){
	if (x > size_of_cave || x <= 0) //checking if the user in their bounds
		return false;	
	if (y > size_of_cave || y <= 0)
		return false;
	else	//if not
		return true;
}

/*********************************************************************
** Function Name: menu
** Parameters: N/A
** Description: This function mainly asking the user about there choice if they want to move or shoot an arrow.
** Pre-Conditions: N/A
** Post-Consitions: In output, this function calls the required functions depending upon the user choice.
*********************************************************************/
void Room::asking_user_choice(char choice){
	cout << "would you like to move(1)or shoot an arrow(2) Fire aw arrow through aw adjacewt room? "<<endl;//asking about user choice
	if(choice == 'y'){
		system("stty raw");
		user_choice = getchar();
		system("stty cooked");
	}if(choice == 'n'){
		user_choice = AI_class();
	}if (user_choice == '1'){	//if the user want to move
		manual_move();
		if(choice == 'y'){
			system("stty raw");
			movement_of_user = getchar();
			system("stty cooked");
		}if(choice == 'n'){
			AI_class_move_shoot();
		}cout<<endl;
		if_user_want_to_move();	//calling the function reuired for this.
		checking_event_next_to_user();//Cheking the events next to user.
	}
	else if (user_choice == '2'){	//if the user want to shoot an arrow.
		manual_shoot();
		if(choice == 'y'){
			system("stty raw");
			movement_of_user = getchar();
			system("stty cooked");
		}if(choice == 'n'){
			AI_class_move_shoot();
		}cout<<endl;
		num_of_arrows_used--;//subtracting  one arrow
		if_the_user_want_to_shoot_arrow();//calling the required function.
	}
}
/*********************************************************************
** Function Name: manual_move
** Parameters: N/A
** Description: This function is called when the user try to manually play the game.
** Pre-Conditions: N/A
** Post-Consitions: In output, it prints the statments..
*********************************************************************/

void Room::manual_move(){
	cout<<endl;
	cout<<"w = if you want to go up. "<< endl;
	cout<<"s = if you want to go down."<< endl;
	cout<<"a = if you want to go left."<< endl;
	cout<<"d = if you want to fo right."<<endl;
}
/*********************************************************************
** Function Name: manual_shoot
** Parameters: N/A
** Description: This function is called when the user choice to manually shoot the arrow.
** Pre-Conditions: N/A
** Post-Consitions: In output, this function prints the statments.
*********************************************************************/

void Room::manual_shoot(){
	cout<<endl;
	cout<<"w = if you want to shoot up. "<< endl;
	cout<<"s = if you want to shoot down."<< endl;
	cout<<"a= if you want to shoot left."<< endl;
	cout<<"d = if you want to shoot right."<<endl;
	cout<<"Enter the direction: "<<endl;
}
/*********************************************************************
** Function Name: ~game
** Parameters: N/A
** Description: This function is automatically called when the code finished and free all the space.
** Pre-Conditions: N/A
** Post-Consitions: In output, it clears all the dynamic memory created by the vector in the starting.
*********************************************************************/
Room::~Room(){
	for(int i = 0; i < array_of_cave.size(); i++){
		for(int j = 0;j < array_of_cave.size();j++){
			delete array_of_cave[i][j];
		}
		array_of_cave[i].clear();
		vector<Room*>().swap(array_of_cave[i]);
	}	
	vector<vector<Room*>>().swap(array_of_cave);	
	delete array_of_events;
	for(int i =0;i< array_of_cave.size();i++){
		delete tmp[i];
	}
}
/*********************************************************************
** Function Name: check_if_user_won
** Parameters: N/A
** Description: This function is chekcing if the user won or not.
** Pre-Conditions: N/A.
** Post-Consitions: In output, it tells the user if they won or not.
*********************************************************************/
void Room::check_if_user_won(){
	if(gold_found == 0 && num_of_wumpus_dead == true){	//if the user killed the wumpus but did not get the gold
		is_user_won = false;
		is_game_finished = false;
	}	
	if(gold_found == 1 && new_user_horizontal == user_horizontal_start && new_user_vertical == user_vertical_start){
			is_user_won = true;
			is_game_finished = true;
	}
	if (gold_found == 1 && num_of_wumpus_dead == true){ //if the user got teh gold and kille the wumpus
		if(new_user_horizontal == user_horizontal_start && new_user_vertical == user_vertical_start){	//if the suer escape from the same position from which they come.
			is_user_won = true;
			is_game_finished = true;
		}
		else{//if not
			is_user_won = false;
			is_game_finished = false;	
		}
	}
}

/*********************************************************************
** Function Name: play_game
** Parameters: int,char*
** Description: Thif function is mainly calling other functions and this function is called by tha main.In short, this function is made for making the main function small.
** Pre-Conditions: Pass the the size of the cave the user entered through command line argument, and the secong argument(true/false).
** Post-Consitions: In output, it goes through all the function called in it and tells the desire outputs.
*********************************************************************/
void Room::play_game(char option,int num, char *argv){
		set_array_of_cave(num); //making the vector of cave.
		set_event_in_array_of_cave(); //setting events in the cave
		printing_cave_if_false(argv); //printing the cave.
		do{	
			cout<<"Till wow you found "<<gold_found<<" wumber of gold ewd You ere left with "<<num_of_arrows_used<<"wumber of erreows..."<<endl;//teeling the user nu of arrows they have and num of gold they have.
			showing_messages_to_user();
			asking_user_choice(option);//asking for the user choice.
			if(num_of_arrows_used <= 0){//if user got finished by the arrows.
				cout<<"YOu left with no more arrows, so lost the game..."<<endl;
				is_game_finished = true;
			}	
			printing_cave_if_false(argv); //output the evewt
			check_if_user_won();//checking if the user won or not.
		}while(is_game_finished != true);
		if(user_horizontal_start == new_user_horizontal && user_vertical_start == new_user_vertical){
			is_user_won = false;
		}
		if(is_user_won == true)//if the user won
			cout<<"Cowgratualtion you won the game!!!"<<endl;
		else//if not
			cout<<"You Lost the game..."<<endl;
}
