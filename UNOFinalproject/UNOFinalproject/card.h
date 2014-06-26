#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;

class Card {

public:
	static const int RED = 1; 
	static const int YELLOW = 2; 
	static const int GREEN = 3; 
	static const int BLUE = 4;
	static const int WILD = 5;
	int color;
	int value;
	Card(int s, int v);

	int getColor();
	void setColor(int s);
	int getValue();
	void setValue(int v);

	friend ostream& operator<<(ostream& str, Card& c);
	bool operator==(Card& c);
};

#endif