/* 
    This test exercises discardCard
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    // Sets up the paramters for dominion.c
    int seed = 1000;
    int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    #if (NOISY_TEST == 1)
        printf("Check that the player has one less card in hand");
    #endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(2, k, seed, &G);
        discardCard(1, 1, &G, 1);
        //assert(G.handCount[1] == 4);
        
    printf("All tests passed!\n");

    return 0;
}