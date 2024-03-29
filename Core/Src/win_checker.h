/*
 * win_checker.cpp
 *
 *  Created on: Oct 29, 2023
 *      Author: kazma
 */

/*
When target is hit:
locations_on = [...]
connected = 1
directions = [[[1, 0], [-1, 0]]
                        [[0, 1], [0, -1]]
                        [[1, 1], [-1, -1]]
                        [[1, -1], [-1, 1]]]
Loop through directions list
-loop through nested direction list
--curr_location = [target_location[0] + direction[0], target_location[1] + direction[1]]
--loop until next location is not on
---connected += 1
---if connected == 4: return true
---curr_location = [curr_location[0] + direction[0], curr_location[1] + direction[1]]
-connected = 1
return false
 */

#include<iostream>
#include<list>
#include<set>

using namespace std;

int turn_num = 1;

//Locations of the pieces for each player
set<list<int>> player1_locations = {{}};
set<list<int>> player2_locations = {{}};

//Locations of the pieces for the player who is currently taking their turn
set<list<int>> turn_player_locations = player1_locations;

//Changes the turn to the other player
void change_turn() {
	//Changes the turn to player 2 if it was player 1's turn
    if (turn_num == 1) {
        player1_locations = turn_player_locations;
        turn_player_locations = player2_locations;
        turn_num = 2;
        return;
    }

    //Changes the turn to player 1 if it was player 2's turn
    player2_locations = turn_player_locations;
    turn_player_locations = player1_locations;
    turn_num = 1;
}

//Returns true if the player won after they added a new piece to the board
bool check_win(list<int> location) {
	turn_player_locations.insert(turn_player_locations.end(), location);
	int connected = 1;

	set<set<list<int>>> directions_lists = {{{1, 0}, {-1, 0}},
					                    	{{0, 1}, {0, -1}},
											{{1, 1}, {-1, -1}},
											{{1, -1}, {-1, 1}}};
	for (set<list<int>> directions:directions_lists) {
		for (list<int> direction:directions) {
			list<int> curr_location = {*location.begin() + *direction.begin(), *location.rbegin() + *direction.rbegin()};
			while (turn_player_locations.find(curr_location) != turn_player_locations.end()) {
				connected++;
				if (connected == 4) {
					return true;
			    }
			    curr_location = {*curr_location.begin() + *direction.begin(), *curr_location.rbegin() + *direction.rbegin()};
			}
		}
		connected = 1;
	}

	return false;
}
