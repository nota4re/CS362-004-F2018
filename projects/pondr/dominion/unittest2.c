/* 
    This test exercises isGameOver
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
    int i;
    int seed = 1;
    int r;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    #if (NOISY_TEST == 1)
        printf("Checking if isGameOver exits correctly");
    #endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(2, k, seed, &G);
        G.supplyCount[province] = 0;
        assert(isGameOver(&G) == 1);
        G.supplyCount[0] == 0;
        G.supplyCount[1] == 0;
        G.supplyCount[2] == 0;
        assert(isGameOver(&G) == 1);
        
    printf("All tests passed!\n");

    return 0;
}