#pragma once
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <ctime>

typedef int Suit;
constexpr int spade = 0, club = 1, diamond = 2, heart = 3;

struct Card {
	int num;	// Ace is 0, King is 12
	Suit suit;	// Spade 0, Club 1, Diamond 2, Heart 3
	Card() : num(0), suit(spade) {}
	Card(int num, Suit suit) : num(num), suit(suit) {}
	friend std::ostream& operator<<(std::ostream&, const Card&);
};

class Deck {
public:
	Deck();
	Deck(int);		// Deck with variable size
	Deck(Deck&);
	Deck& operator=(const Deck&);	// Copy assignment
	~Deck();

	int currentSize() const;
	void displayDeck() const;
	/*
	O(2*size) space
	Input:
		- Number of times to shuffle
		- If no number is inputted, shuffle 1000 times
	Process:
		- Pull random numbers a and b
		- Move everything from a to b inclusive to the front
	*/
	void shuffle(int = 1000);

	//	Checking/Removing Card
	Card checkCard(int) const;
	Card takeCard(int);
	Card takeFrontCard();
	Card takeEndCard();

	//	Adding Card
	bool addCard(Card, int);
	bool addCardtoEnd(Card);
	bool addCardtoFront(Card);

	void fullempty();					// Change the size and current size to 0
	void empty();						// Change only the current size to 0
	void reset();						// Start with a fresh 52-card deck

	friend std::ostream& operator<<(std::ostream& out, const Deck&);

private:
	Card* deck;		// Last index is the top of the deck. Index 0 is bottom of deck (head face up)
	int size;		// Can be used for current size (generally 52)
	int current_size;	// For games, magic tricks, etc.
};

//	Games
void Solitaire();
void BlackJack();
