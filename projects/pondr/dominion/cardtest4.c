/* 
    This test exercises cardEffect
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
    int p, r, hands[5];
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    for (i = 0; i < maxHandCount; i++)
        hands[i] = steward;

    #if (NOISY_TEST == 1)
        printf("After playing village the number of actions should increase by 2, +1card");
    #endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(2, k, seed, &G);
        assert(cardEffect(1, 0, 0, 0, &G, 1, &bonus));
        // We expect 3 more cards in hand, but the action card will be discarded
        assert(G.handCount[0] == 5);
        assert(G.numActions = 2);
        
    printf("All tests passed!\n");

    return 0;
}