#include <iostream>
#include <array>
#include <algorithm>
#include <random>
using namespace std;

//a)
enum CardSuit
{
	clubs,
	diamonds,
	hearts,
	spades,

	maxsuit
};

enum CardRank
{
	r2,
	r3,
	r4,
	r5,
	r6,
	r7,
	r8,
	r9,
	r10,
	jack,
	queen,
	king,
	ace,

	maxrank
};

// b)
struct Card 
{
	CardSuit suit{};
	CardRank rank{};
};

//c)
void printCard(const Card& card)
{
	
	switch (card.rank)
	{
	case CardRank::r2:      std::cout << '2';   break;
	case CardRank::r3:     std::cout << '3';   break;
	case CardRank::r4:      std::cout << '4';   break;
	case CardRank::r5:      std::cout << '5';   break;
	case CardRank::r6:      std::cout << '6';   break;
	case CardRank::r7:      std::cout << '7';   break;
	case CardRank::r8:      std::cout << '8';   break;
	case CardRank::r9:      std::cout << '9';   break;
	case CardRank::r10:     std::cout << 'T';   break;
	case CardRank::jack:   std::cout << 'J';   break;
	case CardRank::queen:  std::cout << 'Q';   break;
	case CardRank::king:   std::cout << 'K';   break;
	case CardRank::ace:    std::cout << 'A';   break;
	default:
		std::cout << '?';
		break;
	}
	switch (card.suit)
	{
	case CardSuit::clubs:       std::cout << 'C';   break;
	case CardSuit::diamonds:    std::cout << 'D';   break;
	case CardSuit::hearts:      std::cout << 'H';   break;
	case CardSuit::spades:      std::cout << 'S';   break;
	default:
		std::cout << '?';
		break;
	}
	
}

//d) 
using Deck = std::array<Card, 52>;
using Index = Deck::size_type;

Deck createDeck()
{
	Deck deck{};

	// We could initialize each card individually, but that would be a pain.  Let's use a loop.

	Index index{ 0 };

	for (int suit{ 0 }; suit < static_cast<int>(CardSuit::maxsuit); ++suit)
	{
		for (int rank{ 0 }; rank < static_cast<int>(CardRank::maxrank); ++rank)
		{
			deck[index].suit = static_cast<CardSuit>(suit);
			deck[index].rank = static_cast<CardRank>(rank);
			++index;
		}
	}

	return deck;
}

//e)
void printDeck(const Deck& deck)
{
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << " ";
	}
	std::cout << endl;
}

//f) 
void shuffleDeck(Deck& deck)
{
	//shuffle(deck.begin(), deck.end(), default_random_engine());

	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

	std::shuffle(deck.begin(), deck.end(), mt);
}

//g)
int getcard(Card& card)
{
		switch (card.rank)
		{
		case CardRank::r2:      return 2;   break;
		case CardRank::r3:      return 3;   break;
		case CardRank::r4:      return 4;   break;
		case CardRank::r5:      return 5;   break;
		case CardRank::r6:      return 6;   break;
		case CardRank::r7:      return 7;   break;
		case CardRank::r8:      return 8;   break;
		case CardRank::r9:      return 9;   break;
		case CardRank::r10:     return 10;   break;
		case CardRank::jack:    return 10;   break;
		case CardRank::queen:   return 10;   break;
		case CardRank::king:    return 10;   break;
		case CardRank::ace:     return 11;   break;
		default:
			std::cout << "error";
			return 0;
		}
}


int main()
{
	Deck deck{ createDeck() };
	printDeck(deck);
	shuffleDeck(deck);
	printDeck(deck);
	return 0;
}
