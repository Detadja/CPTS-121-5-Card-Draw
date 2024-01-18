#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct card
{
	int ind_suit;
	int ind_face;
} Card;

typedef struct hand
{
	Card cards[5];
} Hand;

void shuffle(int deck[][13]);
void deal(const int deck[][13], const char* face[], const char* suit[]);

void disp_rules(void);
void get_cards(Hand* player, int deck[][13]);
int choose_draw(Hand* player, int deck[][13], const char* face[], const char* suit[]);
void redraw(Hand* player, int deck[][13], int index);
int choose_draw_auto(Hand* player, int deck[][13], const char* face[], const char* suit[]);

int check_deck(int deck[][13]);
int check_combo(Hand p1, Hand p2);
int pair(Hand player);
int two_pairs(Hand player, int result);
int three_oa_kind(Hand player, int result);
int four_oa_kind(Hand player, int result);
int flush(Hand player, int result);
int straight(Hand player, int result);
void sort_hand(Hand* player, int* face[]);
int replay(void);

#endif

