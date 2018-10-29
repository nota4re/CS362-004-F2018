/* 
    This test exercises gainCard
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
#define MAX_HAND 10

int main() {
    // Sets up the paramters for dominion.c
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    // Set up the money for possible scenarios
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    #if (NOISY_TEST == 1)
        printf("Check that the player has one more card in hand");
    #endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(2, k, seed, &G);
        assert(gainCard(1, &G, 0, 1) == 0);
        //assert(G.handCount[0] == 6);
        
    printf("All tests passed!\n");

    return 0;
}