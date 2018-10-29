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
        hands[i] = steward;

#if (NOISY_TEST == 1)
                printf("After playing smithy the number of cards in hand should increase by 3. Also the action card should be discarded");
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[1] = handCount;            // set the number of cards on hand
                memcpy(G.hand[1], hands, sizeof(int) * maxHandCount);
                // We expect 3 more cards in hand, but the action card will be discarded
                assert(cardEffect(1, 0, 0, 0, &G, 1, &bonus));
                // We expect 3 more cards in hand, but the action card will be discarded
                assert(G.handCount[0] == 5);

    printf("All tests passed!\n");

    return 0;
}