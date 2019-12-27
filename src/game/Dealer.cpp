/**
 * Project PokerSimulationsInCpp
 */


#include "Dealer.h"
#include "cards/Card.h"
#include "cards/CardCollection.h"
#include "cards/CommunityCards.h"

/**
 * Dealer implementation
 */



Dealer::Dealer(Dealer &dealer) {}

/**
 * @return HoleCards
 */
HoleCards Dealer::dealHoleCards() {
    return HoleCards();
}

/**
 * @return Card
 */
Card Dealer::dealCard() {
    return Card;
}

/**
 * @return void
 */
void Dealer::discardTopCard() {
    return;
}

/**
 * @return CardCollection
 */
CardCollection Dealer::dealFlop() {
    return null;
}

/**
 * @return Card
 */
Card Dealer::dealTurn() {
    return null;
}

/**
 * @return Card
 */
Card Dealer::dealRiver() {
    return null;
}

/**
 * @param Player &player
 */
void Dealer::presentOptions(void Player &player) {

}
/**
 * Class1 implementation
 */
