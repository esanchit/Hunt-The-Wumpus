/******************************************************
** Program:Hunt_Wumpus.cpp
** Author: Carlos Lopez Molina
** Date: 05/22/2016
** Description: Hunt the Wumpus game 
** Input: Choose size of cave, select where want to go.
** Output: Win or loose game.
******************************************************/ 
#ifndef GAME_H
#define GAME_H

#include"./hunt.h"
#include <iostream>
#include <cstdlib>
#include<vector>
#include<string>
#include <time.h>

using namespace std;

class Room:public Event{
	private:
		char user_choice;
		Event* array_of_events;
		Event* new_array[20];
		int index;
		char cave_event;
		char player;
		vector<Room*>tmp;
		vector<vector<Room*>> array_of_cave;
		int size_of_cave;
		int num_of_arrows_used;
		int gold_found;
		int user_horizontal_start;
		int user_vertical_start;
		int new_user_horizontal;
		int new_user_vertical;
		char movement_of_user;
		bool is_game_finished, is_user_won, num_of_wumpus_dead;
	public:	
		Room();
		char get_cave_event();
		string get_message();
		void set_cave_event(char);
		void set_player(char);
		void set_Wumpus();
		void set_array_of_cave(int);
		void set_event_in_array_of_cave();
		void set_movement_of_user();
		char AI_class();
		void AI_class_move_shoot();
		void manual_move();
		void manual_shoot();
		int calculating_random_number();
		int calculating_random_number_1();
		bool checking_the_bounds(int, int);
		void play_game(char,int, char *);
		void printing_cave_if_false(char *);
		void printing_cave_if_true(string );
		void if_user_want_to_move();
		void if_user_want_to_move_1();
		void checking_event_next_to_user();
		void showing_messages_to_user();
		void if_the_user_want_to_shoot_arrow();
		void asking_user_choice(char);
		void if_the_user_want_to_shoot_arrow_1(bool,char);
		void check_if_user_won();
		~Room();
};

#endif
