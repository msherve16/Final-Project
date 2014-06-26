#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "card.h"
#include "PlayerHand.h"
using namespace std;

const int NUMPLAYERS = 2;
const int NUMCARDS = 7;
vector<int> tmp;

void Welcome()
{
	int menu = 0;
 	
 	    cout << "Welcome to UNO!!" << endl;
 	
 	    // Continue until they want to exit
 	    while (menu != 3) {
 	        cout << "Main Menu: " << endl;
 	        cout << "1. Start Game " << endl;
 	        cout << "2. Tutorial "<< endl;
 	        cout << "3. Quit "<< endl;
 	        cout << "Pick a choice: "<< endl;
 	        cin >> menu;

 	        switch (menu) 
			{
 	        // Play
 	        case 1:
				void filldeck();
 	            break;
	 		//Tutorial
 	        case 2:
					cout << "~~~How to play UNO~~~" << endl;
					cout << "1. Play a card by entering the number on the left of the card." << endl
					<< "2. A card can only be played if the color or the value of the card is same " << endl
					<< " as the top card card on the pile." << endl
					<< "3. If you are unable to play, you must draw a card." << endl
					<< "4. The last card in your hand can be a power card." << endl
					<< "5. Draw Two and Draw Four will cause the next player to be skipped." << endl
 					<< "6. The first player to play all their cards wins! " << endl << endl;
					break;
 	
 	            // Quit   
 	        case 3:
				{ menu = 3;}
 	            break;
 	
 	            // Invalid selection    
 	        default:
 	            cout << "Invalid" << endl;
 	            break;
 	        }
 	    }

}

//shuffle cards
void Shuffle(stack<Card*>& cards) {
	srand((unsigned int) time(NULL));
//initialize cards
	for (unsigned int s = 0; s < tmp.size(); s++)
	{
		tmp[s] = s;
	}

	for (unsigned int s = 0; s < tmp.size(); s++)
		{
			int index = rand() % tmp.size();
			int temp = tmp[s];
			tmp[s] = tmp[index];
			tmp[index] = temp;
		}
}

void filldeck(stack<Card*>& cards) {
		int color;
		int value;
	//read from file
    ifstream file("UnoGame.txt");
		
		//if file opens and not at end, read in data
 	    if (!file.fail()){
			while (!file.eof())
			{
        		string line;
         		while (getline(file, line))
				{
					file >> ws;
					stringstream ss;
					ss << line;
 
 	            Card* card = nullptr;
 	
					ss >> value;
					ss >> color;
 	
 	            srand((unsigned int)time(NULL));
 	
 				 // Make the new card and put it in the deck vector
 				 card = new Card(value, color);
 				 cards.push(card);
 				}
			}
					file.close();
 	    }
}

//deal from deck, repeat for the number of players, add to player's hand array, remove from deck.
void deal(stack<Card*>& deck, PlayerHand players[], int numplayers) {
	for (int c = 0; c < 8; c++) {
		for (int p = 0; p < numplayers; p++) {
			players[p] += deck.top();
			deck.pop();
		}
	}
}

//play game with deck, discard pile, cards, each player's hand, and number of players
void PlayGame(stack<Card*>& deck,stack<Card*>& discardpile, vector<Card*> cards, PlayerHand players[], int numplayers)
{
	while (players[numplayers].size() != 0)
	{
		for (int p = 0; p < numplayers; p++) {
			//show top card on discard pile
			cout << discardpile.top() << endl;
			//show player's cards
			for (unsigned int h = 0; h < cards.size(); h++)
			{cout << cards[h]<< ", " << endl; }
			int choice;
			int color;
			int value;
			cout  <<  "Choose 1 to Draw or 2 to Play a Card" << endl;
			cin >> choice;
			 if (choice = 2)
			{
				cout << "Enter a number for color 1) Red 2) Yellow 3) Green 4)Blue " << endl;
				cin >> color;
				cout << "Enter card number value or: " << endl;
				cout << " 10) skip 11) Reverse 12) Draw Two 13)Wild 14)Wild Draw 4" << endl;
				cin >> value;
		
			//skip next player
				if (value = 10)
				{
					players[p+1];
				}
		
			//reverse order of play
				if (value = 11)
				{
					for (int n= (p+1); n <NUMCARDS; n++)
					{players[p-n];}
				}
		
			//add two cards to next player’s hand and skip next player
				if (value = 12)
				{
					for (int i=0; i < 2; i++)
					{
						players[p+1]+=deck.top();
						deck.pop();
					}
					players[p+2];
				}
		
			//let player choose card color
				if (value = 13)
				{
		 			int entry;

					cout << "Wild! Choose a number: 1)Red 2)Blue 3)Yellow 4)Green" << endl;
					cin >> entry;
					entry = color;
				}
		
			//let player choose new color, next player draws 4, skips next player
				if (value = 14)
				{
		
			//4 cards added to player’s hand
				for (int i=0; i < 4; i++){
				players[p+1]+=deck.top();
					deck.pop();
				}
			//player chooses new color
					int entry;
					cout << "Wild! Choose a number: 1)Red 2)Blue 3)Yellow 4)Green" <<endl;
					cin >> entry;
					entry = color;
				players[p+2];

				}
			}
		 //draw
			else
			{
				players[p]+=deck.top();
				deck.pop();
			}
		//Congratulate winner
			int win = 0;
			if(win = players[p].size()) 
			{ cout << "Congratulations " << players[p] << "!! You won!" << endl;}
		}	
	}
}

//cleanup
void cleanup(PlayerHand& cards) {
	for (int i = 0; i < cards.size(); i++)
		delete cards[i];
}

void cleanup(stack<Card*>& cards) {
	while (!cards.empty()) {
		delete cards.top();
		cards.pop();
	}
}


int main()
{
	Welcome();
	srand((unsigned int)time(NULL));
	stack<Card*> deck;
	stack<Card*> discardpile;
	vector<Card*> cards;
	PlayerHand players[NUMPLAYERS];
	void PlayGame(stack<Card*>& deck,stack<Card*>& discardpile, vector<Card*> cards, PlayerHand players[], int numplayers);

	filldeck(deck);
	Shuffle(deck);
	deal(deck, players, NUMPLAYERS);

	for (int p = 0; p < NUMPLAYERS; p++) {
		cout << "player " << p << ":\n" << players[p];
		 PlayGame(deck, discardpile, cards, players, NUMPLAYERS);
	}

	cleanup(deck);
	cleanup(discardpile);

	for (int p = 0; p < NUMPLAYERS; p++)
		cleanup(players[p]);
}
