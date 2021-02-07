//
// Created by CiaranWelsh on 08/12/2019.
//

#ifndef POKERSIMULATIONSINCPP_DECK_H
#define POKERSIMULATIONSINCPP_DECK_H

#include "PokerX/engine/Card.h"
#include <vector>
#include "RestrictedCardCollection.h"

namespace pokerx {

    /**
     * A Deck is a CardCollection which is instantiated
     * with all 52 unique cards
     */
    class Deck : public RestrictedCardCollection {
    public:

        using RestrictedCardCollection::add;

        Deck();

        ~Deck() override;

        Deck(const Deck& deck);

        Deck(Deck&& deck) noexcept ;

        Deck& operator=(const Deck& deck);

        Deck& operator=(Deck&& deck) noexcept;

        /**
         * @brief deletes the current deck and
         * restarts with a fresh one
         */
        void reset();


    private:

        /**
         * @brief deletes the resources allocated for storing cards
         */
        void deleteCards();

        /**
         * Create a deck
         */
        std::vector<ICard*> buildDeck();
    };

}
#endif //POKERSIMULATIONSINCPP_DECK_H
