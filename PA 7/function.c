#include "header.h"

/* shuffle cards in deck */
void shuffle(int deck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (deck[row][column] != 0);

		/* place card number in chosen slot of deck */
		deck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int deck[][13], const char* face[], const char* suit[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = 1; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (deck[row][column] == card)
				{
					printf("%5s of %-8s%c", face[column], suit[row], card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}

//Displays the rules of the game
void disp_rules(void)
{
	printf("You will be dealt five random cards from the deck. You may choose to discard one or more cards\n");
	printf("from your hand and the dealer will replace as many cards as you have discarded. Each round ends\n");
	printf("when all players (you) are satisfied with your current hand and choose to not discard anymore.\n");
	printf("The winner of the game is the one who posseses the best combos. Speaking of which, from lowest\n");
	printf("to highest:\n");
	printf("- A pair (A pair of the same faces)\n");
	printf("- Two pairs (Two pairs of the same faces)\n");
	printf("- Three of a kind (Three of the same faces)\n");
	printf("- A Straight (Five cards with faces in a sequence)\n");
	printf("- A Flush (Five cards of the same suit)\n");
	printf("- Four of a kind (Four of the same faces)\n\n");
}

//Assigns the player, five cards.
void get_cards(Hand* player, int deck[][13])
{
	int suit = 0, face = 0;
	for (int index = 0; index < 5; index++) //Assigns five cards from the deck to the hand.
	{
		suit = rand() % 4; //Randomly decides a suit.
		face = rand() % 13; //Randomly decides a face.
		while (deck[suit][face] == 0) //Checks if the card has already been drawn before
		{
			suit = rand() % 4;
			face = rand() % 13;
		}
		deck[suit][face] = 0;
		player->cards[index].ind_suit = suit; //Stores the index of the index of the suit.
		player->cards[index].ind_face = face; //Stores the value of the index of the face.
	}	
}

//Redraws the chosen cards.
void redraw(Hand* player, int deck[][13], int index)
{
	int suit = 0, face = 0;
	suit = rand() % 4; //Randomly decides a suit.
	face = rand() % 13; //Randomly decides a face.
	while (deck[suit][face] == 0) //Checks if the card has already been drawn before
	{
		suit = rand() % 4;
		face = rand() % 13;
	}
	deck[suit][face] = 0;
	player->cards[index].ind_suit = suit; //Stores the index of the index of the suit.
	player->cards[index].ind_face = face;
}

//Asks the player how many cards they want to discard, and deal them the same amount of cards discarded.
int choose_draw(Hand* player, int deck[][13], const char* face[], const char* suit[])
{
	int choice = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0;

	system("cls");
	printf("You currently have in your hand: \n");
	printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
	printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
	printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
	printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
	printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
	printf("From this, how many cards do you want to discard?\n");
	printf("(Input 0 if you are content with your current hand and input 5 if you want a new hand)\n");
	scanf("%d", &choice);

	while (choice < 0 || choice > 6) //Checks for invalid input.
	{
		system("cls");
		printf("That's not a valid input.\n\n");
		printf("You currently have in your hand: \n");
		printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
		printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
		printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
		printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
		printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
		printf("From this, how many cards do you want to discard?\n");
		scanf("%d", &choice);
	}

	system("cls");
	if (choice == 5) //Player chose to discard their entire hand.
	{
		get_cards(player, deck);
		return 0;
	}
	else if (choice == 4) //Player chose to discard four cards.
	{
		printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
		printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
		printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
		printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
		printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
		printf("From these, which cards do you want to discard?\n");
		scanf("%d%d%d%d", &c1, &c2, &c3, &c4);

		while (c1 < 1 || c1 > 5 || c2 < 1 || c2 > 5 || c3 < 1 || c3 > 5 || c4 < 1 || c4 > 5) //Checks for invalid input.
		{
			system("cls");
			printf("That's not a valid input.\n\n");
			printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
			printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
			printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
			printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
			printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
			printf("From these, which cards do you want to discard?\n");
			scanf("%d%d%d%d", &c1, &c2, &c3, &c4);
		}

		redraw(player, deck, c1 - 1);
		redraw(player, deck, c2 - 1);
		redraw(player, deck, c3 - 1);
		redraw(player, deck, c4 - 1);
		return 0;
	}
	else if (choice == 3) //Player chose to discard three cards.
	{
		printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
		printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
		printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
		printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
		printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
		printf("From these, which cards do you want to discard?\n");
		scanf("%d%d%d", &c1, &c2, &c3);

		while (c1 < 1 || c1 > 5 || c2 < 1 || c2 > 5 || c3 < 1 || c3 > 5) //Checks for invalid input.
		{
			system("cls");
			printf("That's not a valid input.\n\n");
			printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
			printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
			printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
			printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
			printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
			printf("From these, which cards do you want to discard?\n");
			scanf("%d%d%d", &c1, &c2, &c3);
		}

		redraw(player, deck, c1 - 1);
		redraw(player, deck, c2 - 1);
		redraw(player, deck, c3 - 1);
		return 0;
	}
	else if (choice == 2) //Player chose to discard two cards.
	{
		printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
		printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
		printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
		printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
		printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
		printf("From these, which cards do you want to discard?\n");
		scanf("%d%d", &c1, &c2);

		while (c1 < 1 || c1 > 5 || c2 < 1 || c2 > 5) //Checks for invalid input.
		{
			system("cls");
			printf("That's not a valid input.\n\n");
			printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
			printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
			printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
			printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
			printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
			printf("From these, which cards do you want to discard?\n");
			scanf("%d%d", &c1, &c2);
		}

		redraw(player, deck, c1 - 1);
		redraw(player, deck, c2 - 1);
		return 0;
	}
	else if (choice == 1) //Player chose to discard one card.
	{
		printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
		printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
		printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
		printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
		printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
		printf("From these, which card do you want to discard?\n");
		scanf("%d", &c1);

		while (c1 < 1 || c1 > 5) //Checks for invalid input.
		{
			system("cls");
			printf("That's not a valid input.\n\n");
			printf("1.) The %s of %s\n", face[player->cards[0].ind_face], suit[player->cards[0].ind_suit]);
			printf("2.) The %s of %s\n", face[player->cards[1].ind_face], suit[player->cards[1].ind_suit]);
			printf("3.) The %s of %s\n", face[player->cards[2].ind_face], suit[player->cards[2].ind_suit]);
			printf("4.) The %s of %s\n", face[player->cards[3].ind_face], suit[player->cards[3].ind_suit]);
			printf("5.) The %s of %s\n\n", face[player->cards[4].ind_face], suit[player->cards[4].ind_suit]);
			printf("From these, which cards do you want to discard?\n");
			scanf("%d", &c1);
		}

		redraw(player, deck, c1 - 1);
		return 0;
	}
	else
		return 1;
}

//Automatically decides how many cards to discard and deal the same amount.
int choose_draw_auto(Hand* player, int deck[][13], const char* face[], const char* suit[])
{
	int discard = rand() % 2, choice = rand() % 5, c1 = rand() % 5, c2 = rand() % 5, c3 = rand() % 5, c4 = rand() % 5;
	if (discard == 1) //Discarding.
	{
		if (choice == 4) //Discarding all.
		{
			get_cards(player, deck);
			return 0;
		}
		else if (choice == 3) //Discarding 4.
		{
			redraw(player, deck, c1);
			redraw(player, deck, c2);
			redraw(player, deck, c3);
			redraw(player, deck, c4);
			return 0;
		}
		else if (choice == 2) //Discarding 3.
		{
			redraw(player, deck, c1);
			redraw(player, deck, c2);
			redraw(player, deck, c3);
			return 0;
		}
		else if (choice == 1) //Discarding 2.
		{
			redraw(player, deck, c1);
			redraw(player, deck, c2);
			return 0;
		}
		else //Discarding 1.
		{
			redraw(player, deck, c1);
			return 0;
		}
	}
	else //No discarding.
		return 1;
}

//Checks to see if the deck is empty or not.
int check_deck(int deck[][13])
{
	int count = 0;
	for (int index1 = 0; index1 < 4; index1++)
	{
		for (int index2 = 0; index2 < 13; index2++)
		{
			if (deck[index1][index2] == 0)
				count++;
		}
	}
	return count;
}

//Asks the player if they want to play again.
int replay(void)
{
	char play_again = '\0';

	system("cls");
	printf("Do you want to play again?\n");
	scanf(" %c", &play_again);

	while (play_again != 'Y' && play_again != 'y' && play_again != 'N' && play_again != 'n')
	{
		system("cls");
		printf("That's not a valid input.\n");
		printf("Do you want to play again?");
		scanf(" %c", &play_again);
	}

	if (play_again == 'N' || play_again == 'n')
		return 0;
	else
		return 1;
}

//Checks if the player has a pair.
int pair(Hand player)
{
	int count = 0;
	for (int index1 = 0; index1 < 4; index1++)
	{
		for (int index2 = 1; index1 + index2 < 5; index2++)
		{
			if (player.cards[index1].ind_face == player.cards[index1 + index2].ind_face)
				count++;
		}
	}

	if (count >= 1)
		return 1;
}

//Checks if the player has two pairs.
int two_pairs(Hand player, int result)
{
	int count = 0;
	for (int index1 = 0; index1 < 4; index1++)
	{
		for (int index2 = 1; index1 + index2 < 5; index2++)
		{
			if (player.cards[index1].ind_face == player.cards[index1 + index2].ind_face)
				count++;
		}
	}

	if (count >= 2)
		return 2;
	else
		return result;
}

//Checks if the player has a three of a kind.
int three_oa_kind(Hand player, int result)
{
	int count = 0;
	for (int index1 = 0; index1 < 3; index1++)
	{
		for (int index2 = 1; index1 + index2 < 4; index2++)
		{
			if (player.cards[index1].ind_face == player.cards[index1 + index2].ind_face && 
				player.cards[index1].ind_face == player.cards[index1 + index2 + 1].ind_face && 
				player.cards[index1 + index2].ind_face == player.cards[index1 + index2 + 1].ind_face)
				count++;
		}
	}

	if (count >= 1)
		return 3;
	else
		return result;
}

//Sorts the faces of the player's hand.
void sort_hand(Hand player, int* face[])
{
	int passes = 0, temp = 0;

	for (int index = 0; index < 5; index++)
	{
		face[index] = player.cards[index].ind_face;
	}

	for (passes = 1; passes < 5; passes++)
	{
		for (int index2 = 0; index2 < 5 - passes; index2++)
		{
			if (face[index2] > face[index2 + 1])
			{
				temp = face[index2];
				face[index2] = face[index2 + 1];
				face[index2 + 1] = temp;
			}
		}
	}
}

//Checks if the player has a straight.
int straight(Hand player, int result)
{
	int count = 0, face[5];

	sort_hand(player, face);

	for (int index = 0; index < 4; index++)
	{
		if (face[index] + 1 == face[index + 1])
			count++;
	}

	if (count == 4)
		return 4;
	else
		return result;
}

//Checks if the player has a flush.
int flush(Hand player, int result)
{
	int count = 0;
	for (int index = 0; index < 4; index++)
	{
		if (player.cards[index].ind_suit == player.cards[index + 1].ind_suit)
			count++;
	}

	if (count == 4)
		return 5;
	else
		return result;
}

//Checks if the player has a four of a kind.
int four_oa_kind(Hand player, int result)
{
	int count = 0;
	for (int index1 = 0; index1 < 2; index1++)
	{
		for (int index2 = 1; index1 + index2 < 3; index2++)
		{
			if (player.cards[index1].ind_face == player.cards[index1 + index2].ind_face &&
				player.cards[index1].ind_face == player.cards[index1 + index2 + 1].ind_face &&
				player.cards[index1].ind_face == player.cards[index1 + index2 + 2].ind_face &&
				player.cards[index1 + index2].ind_face == player.cards[index1 + index2 + 1].ind_face &&
				player.cards[index1 + index2].ind_face == player.cards[index1 + index2 + 2].ind_face &&
				player.cards[index1 + index2 + 1].ind_face == player.cards[index1 + index2 + 2].ind_face)
				count++;
		}
	}

	if (count >= 1)
		return 6;
	else
		return result;
}

//Checks which player has the bigger combination.
int check_combo(Hand p1, Hand p2)
{
	int p1_combo = 0, p2_combo = 0;
	p1_combo = pair(p1);
	p1_combo = two_pairs(p1, p1_combo);
	p1_combo = three_oa_kind(p1, p1_combo);
	p1_combo = straight(p1, p1_combo);
	p1_combo = flush(p1, p1_combo);
	p1_combo = four_oa_kind(p1, p1_combo);

	p2_combo = pair(p2);
	p2_combo = two_pairs(p2, p2_combo);
	p2_combo = three_oa_kind(p2, p2_combo);
	p2_combo = straight(p2, p2_combo);
	p2_combo = flush(p2, p2_combo);
	p2_combo = four_oa_kind(p2, p2_combo);

	if (p1_combo == p2_combo) //A tie.
		return 2;
	else if (p1_combo > p2_combo) //Player 1 wins
		return 1;
	else //Player 2 wins
		return 0;
}
