/*
 * y_getter.cpp
 *
 *  Created on: Nov 3, 2023
 *      Author: kazma
 */

#include<iostream>
#include<list>
#include<set>

using namespace std;

list<int> y_levels = {0, 0, 0, 0, 0, 0, 0};

int get_y(int x) {
	list<int>::iterator pointer = y_levels.begin();
	for (int i=0; i < x; i++) {
		pointer++;
	}

    return (*pointer)++;;
}
