#include <iostream>
#include <vector>
#include <fstream>

#define ROYAL_FLUSH 1
#define STRAIGHT_FLUSH 2
#define FOUR_OF_A_KIND 3
#define FULL_HOUSE 4
#define FLUSH 5
#define STRAIGHT 6
#define THREE_OF_A_KIND 7
#define TWO_PAIRS 8
#define ONE_PAIR 9
#define HIGH_CARD 10

using namespace std;

typedef struct Card {
	char value;
	char suit;
} Card;

/*
Return true if the cards are all of the same suit
*/
bool are_same_suit(vector<Card> cards)
{
	int spades = 0, diamonds = 0, clubs = 0, hearts = 0;
	for(vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		if(it->suit == 'S') spades++;
		else if(it->suit == 'D') diamonds++;
		else if(it->suit == 'C') clubs++;
		else if(it->suit == 'H') hearts++;
	}
	return (spades == 5 || diamonds == 5 || clubs == 5 || hearts == 5);
}

/*
Convert a value char into an int
*/
int convert_char_value_to_int(char c)
{
	if(c == 'T') return 10;
	if(c == 'J') return 11;
	else if(c == 'Q') return 12;
	else if(c == 'K') return 13;
	else if(c == 'A') return 14;
	else return c - '0';
}

/*
Royal Flush check
*/
bool has_royal_flush(vector<Card> cards)
{
	// check if there is a Ten, Jack, Queen, King and Ace
	bool has_ten = false, has_jack = false, has_queen = false, has_king = false, has_ace = false;
	for(vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		if(it->value == 'T') has_ten = true;
		else if(it->value == 'J') has_jack = true;
		else if(it->value == 'Q') has_queen = true;
		else if(it->value == 'K') has_king = true;
		else if(it->value == 'A') has_ace = true;
		
	}
	return (are_same_suit(cards) && has_ten && has_jack && has_queen && has_king && has_ace);
}

/*
Straight Flush check
*/
int has_straight_flush(vector<Card> cards)
{
	int values[15]; for(int i = 0; i < 15; i++) values[i] = 0;
	for(vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		if(it->value == 'T') values[10]++;
		else if(it->value == 'J') values[11]++;
		else if(it->value == 'Q') values[12]++;
		else if(it->value == 'K') values[13]++;
		else if(it->value == 'A') values[14]++;
		else values[it->value - '0']++;
	}
	
	for(int i = 2; i <= 14; i++)
	{
		if(values[i] != 0 && values[i+1] != 0 && values[i+2] != 0 && values[i+3] != 0 && values[i+4] != 0)
			if(are_same_suit(cards)) { return i; }
	}
	return -1;
}

/*
Four of a Kind check
*/
int has_four_of_a_kind(vector<Card> cards)
{
	int values[15]; for(int i = 0; i < 15; i++) values[i] = 0;
	for(vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		if(it->value == 'T') values[10]++;
		else if(it->value == 'J') values[11]++;
		else if(it->value == 'Q') values[12]++;
		else if(it->value == 'K') values[13]++;
		else if(it->value == 'A') values[14]++;
		else values[it->value - '0']++;
	}
	
	for(int i = 2; i <= 14; i++)
		if(values[i] == 4) return i;
	return -1;
}

/*
Full House check
*/
bool has_full_house(vector<Card> cards)
{
	int values[15]; for(int i = 0; i < 15; i++) values[i] = 0;
	for(vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		if(it->value == 'T') values[10]++;
		else if(it->value == 'J') values[11]++;
		else if(it->value == 'Q') values[12]++;
		else if(it->value == 'K') values[13]++;
		else if(it->value == 'A') values[14]++;
		else values[it->value - '0']++;
	}
	
	bool has_pair = false, has_three = false;
	for(int i = 2; i <= 14; i++)
	{
		if(values[i] == 2) has_pair = true;
		else if(values[i] == 3) has_three = true;
	}
	return (has_pair && has_three);
}

/*
Flush check
*/
bool has_flush(vector<Card> cards)
{
	return are_same_suit(cards);
}

/*
Straight check
*/
int has_straight(vector<Card> cards)
{
	int values[15]; for(int i = 0; i < 15; i++) values[i] = 0;
	for(vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		if(it->value == 'T') values[10]++;
		else if(it->value == 'J') values[11]++;
		else if(it->value == 'Q') values[12]++;
		else if(it->value == 'K') values[13]++;
		else if(it->value == 'A') values[14]++;
		else values[it->value - '0']++;
	}
		
	for(int i = 2; i <= 10; i++)
	{
		if(values[i] != 0 && values[i+1] != 0 && values[i+2] != 0 && values[i+3] != 0 && values[i+4] != 0)
			return i;
	}
	return -1;
}

/*
Three of a Kind check
*/
int has_three_of_a_kind(vector<Card> cards)
{
	int values[15]; for(int i = 0; i < 15; i++) values[i] = 0;
	for(vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		if(it->value == 'T') values[10]++;
		else if(it->value == 'J') values[11]++;
		else if(it->value == 'Q') values[12]++;
		else if(it->value == 'K') values[13]++;
		else if(it->value == 'A') values[14]++;
		else values[it->value - '0']++;
	}
		
	for(int i = 2; i <= 14; i++)
		if(values[i] == 3) return i;
	return -1;
}

/*
Two Pairs check
*/
int has_two_pairs(vector<Card> cards)
{
	int values[15]; for(int i = 0; i < 15; i++) values[i] = 0;
	for(vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		if(it->value == 'T') values[10]++;
		else if(it->value == 'J') values[11]++;
		else if(it->value == 'Q') values[12]++;
		else if(it->value == 'K') values[13]++;
		else if(it->value == 'A') values[14]++;
		else values[it->value - '0']++;
	}
	
	int pairs = 0;
	int minpair = 1000;
	for(int i = 2; i <= 14; i++)
	{
		if(values[i] == 2) 
		{ 
			if(i < minpair) minpair = i;
			pairs++; 
		}
	}
	
	if(pairs != 2) return -1;
	else return minpair;
}

/*
One Pair check
*/
int has_pair(vector<Card> cards)
{
	int values[15]; for(int i = 0; i < 15; i++) values[i] = 0;
	for(vector<Card>::iterator it = cards.begin(); it != cards.end(); it++)
	{
		if(it->value == 'T') values[10]++;
		else if(it->value == 'J') values[11]++;
		else if(it->value == 'Q') values[12]++;
		else if(it->value == 'K') values[13]++;
		else if(it->value == 'A') values[14]++;
		else values[it->value - '0']++;
	}
	
	for(int i = 2; i <= 14; i++)
		if(values[i] == 2) return i;
	return -1;
}

/*
Return the one with the highest card, according to ties
*/
int highest_card_of_pair(vector<Card> c1, vector<Card> c2)
{
	vector<int> vals1, vals2;
	for(int i = 0; i < 5; i++)
	{
		vals1.push_back(convert_char_value_to_int(c1[i].value));
		vals2.push_back(convert_char_value_to_int(c2[i].value));
	}
	sort(vals1.begin(), vals1.end());
	sort(vals2.begin(), vals2.end());
	
	for(int i = 0; i < 5; i++) cout << vals1[i] << " ";
	cout << endl;
	for(int i = 0; i < 5; i++) cout << vals2[i] << " ";
	cout << endl;
	
	for(int i = 4; i >= 0; i--)
	{
		if(vals1[i] > vals2[i]) return 0;
		else if(vals1[i] < vals2[i]) return 1;
	}
		
	return 1;
}

pair<int, int> rank(vector<Card> cards) // return a pair with <rank, value>
{
	int v = has_royal_flush(cards);
	if(v == 1) return make_pair(ROYAL_FLUSH, -1);
	
	v = has_straight_flush(cards);
	if(v != -1) return make_pair(STRAIGHT_FLUSH, v);
	
	v = has_four_of_a_kind(cards);
	if(v != -1) return make_pair(FOUR_OF_A_KIND, v);
	
	v = has_full_house(cards);
	if(v == 1) return make_pair(FULL_HOUSE, -1);
	
	v = has_flush(cards);
	if(v == 1) return make_pair(FLUSH, -1);
	
	v = has_straight(cards);
	if(v != -1) return make_pair(STRAIGHT, v);
	
	v = has_three_of_a_kind(cards);
	if(v != -1) return make_pair(THREE_OF_A_KIND, v);
	
	v = has_two_pairs(cards);
	if(v != -1) return make_pair(TWO_PAIRS, v);
	
	v = has_pair(cards);
	if(v != -1) return make_pair(ONE_PAIR, v);
	
	return make_pair(HIGH_CARD, -1);
}

Card make_card(string c)
{
	Card card; card.value = c[0]; card.suit = c[1];
	return card;
}

int main(int argc, char *argv[]) 
{
	int whitewins = 0;
	int o = 0;
	
	fstream fin("poker.txt");
	for(int i = 0; i < 1000; i++)
	{
		vector<Card> pair1, pair2;
		for(int j = 0; j < 5; j++)
		{
			string c; fin >> c;
			cout << c << " ";
			pair1.push_back(make_card(c));
		}
		cout << endl;
		for(int j = 0; j < 5; j++)
		{
			string c; fin >> c;
			cout << c << " ";
			pair2.push_back(make_card(c));
		}
		cout << endl;
		
		pair<int, int> r1 = rank(pair1);
		pair<int, int> r2 = rank(pair2);
		
		cout << "rank 1: " << r1.first << ", rank 2: " << r2.first << endl;
		
		if(r1.first < r2.first) { cout << "white wins" << endl; whitewins++; }
		else if(r1.first == r2.first)
		{
			if(r1.first == 10)
			{
				if(highest_card_of_pair(pair1, pair2) == 0) { cout << "white wins" << endl; whitewins++; }
			}
			else
			{
				if(r1.second > r2.second) { cout << "white wins on rank" << endl; whitewins++; }
				else if(r1.second == r2.second)
				{
					cout << "TIE rank" << endl;
					if(highest_card_of_pair(pair1, pair2) == 0) { cout << "white wins" << endl; whitewins++; }
				}
			}
		}
		cout << endl;
	}
	cout << whitewins << endl;
	cout << o << endl;
}