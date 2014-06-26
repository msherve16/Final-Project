#include "card.h"

Card::Card(int s, int v) {
	setColor(s);
	setValue(v);
}

//mutator and acessor functions for color
int Card::getColor() { return color; }
void Card::setColor(int s) {
	color = (s >= RED && s <= BLUE) ? s :RED;
}

//accessor and mutator functions for value
int Card::getValue() { return value; }
void Card::setValue(int v) {
	value = (v >= 0 && v <= 13) ? v : 0;
}

//output card name;
ostream& operator<<(ostream& str, const Card& c) {
	//output name if card is a power card
	if (c.value == 14) str << "Wild Draw Four";
	else if (c.value == 13) str << "Wild";
	else if (c.value == 12) str << "Skip";
	else if (c.value == 11) str << "Reverse";
	else if (c.value == 10) str << "DrawTwo";
	//output value if card is a number card
	else str << c.value;

	str << " of ";

	switch (c.color) {
	case Card::RED:
		str << "Red";
		break;
	case Card::YELLOW:
		str << "Yellow";
		break;
	case Card::GREEN:
		str << "Green";
		break;
	case Card::BLUE:
		str << "Blue";
		break;
	case Card::WILD:
		str << "Wild";
	}

	return str;

}

bool Card::operator==(Card& c) {
	return (getColor() == c.getColor() && getValue() == c.getValue());
}