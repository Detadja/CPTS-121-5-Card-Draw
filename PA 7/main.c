/*
Name: Denise Tanumihardja
Class: Cpts 121
Porject: Programming Assingmnet 7
Date: 23/4/2020
Description: 
*/

#include "header.h"

int main(void)
{
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */
	shuffle(deck);

	int num = 0;
	do
	{
		system("cls");
		printf("Welcome, to 5-Card Draw!\n");
		printf("1. Play game\n");
		printf("2. Rules\n");
		printf("3. Exit game\n\n");
		scanf("%d", &num);

		while (num < 1 || num > 3) //Checks for invalid input
		{
			system("cls");
			printf("That's not a valid input.\n\n");
			printf("1. Play game\n");
			printf("2. Rules\n");
			printf("3. Exit game\n\n");
			scanf("%d", &num);
		}

		switch (num)
		{
		case 1: //Plays game.
		{
			Hand player1 = { 0, 0 }, player2 = { 0, 0 };
			get_cards(&player1, deck);
			system("cls");
			printf("Press ENTER to get your five cards.\n\n");
			getch();

			get_cards(&player2, deck);
			printf(". . .\n\n");
			printf(". . .\n\n");
			printf(". . .\n\n");
			printf("Player 2 has gotten their cards.\n");
			printf("Press ENTER to continue.\n");
			getch();
			system("cls");

			int p1 = 0, p2 = 0, check = 0;
			do
			{
				check = check_deck(deck);
				if (check == 52)
				{
					p1 = 1;
					p2 = 1;
					printf("There are no more cards in the deck. Do with what you have. Good luck.\n");
					printf("Press ENTER to continue.\n");
					getch();
				}

				if (p1 == 0)
				{
					p1 = choose_draw(&player1, deck, face, suit);
				}

				if (p2 == 0)
				{
					p2 = choose_draw_auto(&player2, deck, face, suit);
				}
				system("cls");

			} while (p1 == 0 || p2 == 0);

			/*printf("You currently have in your hand: \n");
			printf("1.) The %s of %s\n", face[player1.cards[0].ind_face], suit[player1.cards[0].ind_suit]);
			printf("2.) The %s of %s\n", face[player1.cards[1].ind_face], suit[player1.cards[1].ind_suit]);
			printf("3.) The %s of %s\n", face[player1.cards[2].ind_face], suit[player1.cards[2].ind_suit]);
			printf("4.) The %s of %s\n", face[player1.cards[3].ind_face], suit[player1.cards[3].ind_suit]);
			printf("5.) The %s of %s\n\n", face[player1.cards[4].ind_face], suit[player1.cards[4].ind_suit]);*/
			printf(". . .\n\n");
			printf(". . .\n\n");
			printf(". . .\n\n");
			printf("Press ENTER to continue.\n");
			getch();
			system("cls");

			int win_lose = 0;

			win_lose = check_combo(player1, player2);

			if (win_lose == 1) //Player 1 wins.
			{
				printf("Congrats! You won!\n\n");
				printf("You had in your hand: \n");
				printf("1.) The %s of %s\n", face[player1.cards[0].ind_face], suit[player1.cards[0].ind_suit]);
				printf("2.) The %s of %s\n", face[player1.cards[1].ind_face], suit[player1.cards[1].ind_suit]);
				printf("3.) The %s of %s\n", face[player1.cards[2].ind_face], suit[player1.cards[2].ind_suit]);
				printf("4.) The %s of %s\n", face[player1.cards[3].ind_face], suit[player1.cards[3].ind_suit]);
				printf("5.) The %s of %s\n\n", face[player1.cards[4].ind_face], suit[player1.cards[4].ind_suit]);

				printf("While the other player had: \n");
				printf("1.) The %s of %s\n", face[player2.cards[0].ind_face], suit[player2.cards[0].ind_suit]);
				printf("2.) The %s of %s\n", face[player2.cards[1].ind_face], suit[player2.cards[1].ind_suit]);
				printf("3.) The %s of %s\n", face[player2.cards[2].ind_face], suit[player2.cards[2].ind_suit]);
				printf("4.) The %s of %s\n", face[player2.cards[3].ind_face], suit[player2.cards[3].ind_suit]);
				printf("5.) The %s of %s\n\n", face[player2.cards[4].ind_face], suit[player2.cards[4].ind_suit]);

				printf("Press ENTER to continue.\n");
				getch();
			}
			else if (win_lose == 0)//Player 2 wins.
			{
				printf("Press F in the chats, you lost to a bot. Better luck next time!\n\n");
				printf("You had in your hand: \n");
				printf("1.) The %s of %s\n", face[player1.cards[0].ind_face], suit[player1.cards[0].ind_suit]);
				printf("2.) The %s of %s\n", face[player1.cards[1].ind_face], suit[player1.cards[1].ind_suit]);
				printf("3.) The %s of %s\n", face[player1.cards[2].ind_face], suit[player1.cards[2].ind_suit]);
				printf("4.) The %s of %s\n", face[player1.cards[3].ind_face], suit[player1.cards[3].ind_suit]);
				printf("5.) The %s of %s\n\n", face[player1.cards[4].ind_face], suit[player1.cards[4].ind_suit]);

				printf("While the other player had: \n");
				printf("1.) The %s of %s\n", face[player2.cards[0].ind_face], suit[player2.cards[0].ind_suit]);
				printf("2.) The %s of %s\n", face[player2.cards[1].ind_face], suit[player2.cards[1].ind_suit]);
				printf("3.) The %s of %s\n", face[player2.cards[2].ind_face], suit[player2.cards[2].ind_suit]);
				printf("4.) The %s of %s\n", face[player2.cards[3].ind_face], suit[player2.cards[3].ind_suit]);
				printf("5.) The %s of %s\n\n", face[player2.cards[4].ind_face], suit[player2.cards[4].ind_suit]);

				printf("Press ENTER to continue.\n");
				getch();
			}
			else
			{
				printf("Looks like its a tie!\n\n");
				printf("You had in your hand: \n");
				printf("1.) The %s of %s\n", face[player1.cards[0].ind_face], suit[player1.cards[0].ind_suit]);
				printf("2.) The %s of %s\n", face[player1.cards[1].ind_face], suit[player1.cards[1].ind_suit]);
				printf("3.) The %s of %s\n", face[player1.cards[2].ind_face], suit[player1.cards[2].ind_suit]);
				printf("4.) The %s of %s\n", face[player1.cards[3].ind_face], suit[player1.cards[3].ind_suit]);
				printf("5.) The %s of %s\n\n", face[player1.cards[4].ind_face], suit[player1.cards[4].ind_suit]);

				printf("While the other player had: \n");
				printf("1.) The %s of %s\n", face[player2.cards[0].ind_face], suit[player2.cards[0].ind_suit]);
				printf("2.) The %s of %s\n", face[player2.cards[1].ind_face], suit[player2.cards[1].ind_suit]);
				printf("3.) The %s of %s\n", face[player2.cards[2].ind_face], suit[player2.cards[2].ind_suit]);
				printf("4.) The %s of %s\n", face[player2.cards[3].ind_face], suit[player2.cards[3].ind_suit]);
				printf("5.) The %s of %s\n\n", face[player2.cards[4].ind_face], suit[player2.cards[4].ind_suit]);

				printf("Press ENTER to continue.\n");
				getch();
			}

			int decide = replay(); //Asks if the player wants to try again
			if (decide == 0)
				num = 4;
		}
		break;
		case 2: //Displays rules.
		{
			system("cls");
			disp_rules();
			printf("Press ENTER to continue.\n");
			getch();
		}
		break;
		case 3: //Exits game.
			num = 4; 
		break;
		}
	} while (num >= 1 && num <= 3);

	system("cls");
	printf("See you soon!\n");

	return 0;
}