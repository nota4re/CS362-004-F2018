/* 
    This test exercises initializeGame
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
    int seed = 1;
    int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    int kbad[10] = {adventurer, council_room, feast, gardens, mine
                , remodel, smithy, baron, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;

    #if (NOISY_TEST == 1)
        printf("Checking number of players is correctly handled");
    #endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        assert(-1 == initializeGame(0, k, seed, &G));
        assert(-1 == initializeGame(1, k, seed, &G));
        assert(-1 == initializeGame(5, k, seed, &G));
        r = initializeGame(2, k, seed, &G);
        assert(G.numPlayers == 2);

    #if (NOISY_TEST == 1)
        printf("Check duplicate kingdom cards returns error");
    #endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        assert(-1 == initializeGame(2, kbad, seed, &G)); // initialize a new game
    
    #if (NOISY_TEST == 1)
        printf("Check number of curse cards, victory cards, treasure cards");
    #endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(2, k, seed, &G);
        assert(G.supplyCount[curse] == 10);
        assert(G.supplyCount[estate] == 8);
        assert(G.supplyCount[duchy] == 8);
        assert(G.supplyCount[province] == 8);

    #if (NOISY_TEST == 1)
        printf("Check that for each player the number 5 cards are drawn");
    #endif
        assert(G.handCount[0] == 5);
        
    printf("All tests passed!\n");

    return 0;
}