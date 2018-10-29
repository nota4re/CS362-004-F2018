/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
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
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int hands[maxHandCount];

    for (i = 0; i < maxHandCount; i++)
        hands[i] = adventurer;

#if (NOISY_TEST == 1)
                printf("Test adventurer");
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[1] = handCount;            // set the number of cards on hand
                memcpy(G.hand[1], hands, sizeof(int) * maxHandCount);
                assert(cardEffect(1, 0, 0, 0, &G, 1, &bonus));
                // We expect 2 more treasure cards in hand
                assert(G.handCount[0] == 5);

    printf("All tests passed!\n");

    return 0;
}