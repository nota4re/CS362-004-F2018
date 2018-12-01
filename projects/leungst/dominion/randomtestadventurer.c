#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 100

//This randomly tests Adventurer

int main() {
	srand(time(0));
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		sea_hag, tribute, smithy};

	int i, j, n, players, player, handCount, deckCount, seed, address;
	struct gameState state;

	printf("Running Random Test: Adventurer\n");

	for (i = 0; i < MAX_TESTS; i++) {

	// Test 0-4 players
	players = rand() % 5;
	player = 1;
	seed = rand();
	printf("Num Players: %d,  Seed: %d\n", players, seed);
	initializeGame(players, k, seed, &state);

	//Use known globals to setup hands
	state.deckCount[player] = rand() % MAX_DECK + 1;
	state.discardCount[player] = rand() % MAX_DECK + 1;
	state.handCount[player] = rand() % MAX_HAND + 1;

	//Get state variables
	handCount = state.handCount[player];
	deckCount = state.deckCount[player];

	if (seed % 5 == 0)
		state.deckCount[player] = 0;
	
	printf("Result: %d\n", cardEffect(adventurer, 1, 1, 1, &state));

	}
	  
	printf("Tests Complete\n");
	memset(&state, 23, sizeof(struct gameState));
	return 0;
}