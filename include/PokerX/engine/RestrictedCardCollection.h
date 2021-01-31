//
// Created by Ciaran on 08/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_RESTRICTEDCARDCOLLECTION_H
#define POKERSIMULATIONSINCPP_RESTRICTEDCARDCOLLECTION_H

#include "CardCollection.h"

namespace pokerx {

    class RestrictedCardCollection : public CardCollection {
    public:

        using CardCollection::CardCollection;

        RestrictedCardCollection() = default;

        ~RestrictedCardCollection() override = default;

        void add(const std::vector<ICard *> &cards) override;

        void add(ICard *card) override;

        void add(const CardCollection &cardCollection) override;

    protected:

        /**
         * @biref Types which derive from RestrictedCardCollection
         * can use this constructor to automatically set the max_cards_
         * variable to the size of the input vector.
         */
        explicit RestrictedCardCollection(std::vector<ICard*> cards);

        /**
         * @brief Types which derive from RestrictedCardCollection
         * can use this constructor to automatically set the max_cards_
         * variable to value of @param max_num_cards.
         */
         RestrictedCardCollection(const std::vector<ICard*>& cards, unsigned int max_num_cards);

         explicit RestrictedCardCollection(unsigned int max_num_cards);

    private:
        /// maximum number of cards in this collection
        unsigned int max_cards_ = 52;

        std::string err_msg_ = "This RestrictedCardCollection can only contain \"" + std::to_string(max_cards_) + "\"";

    };

}
#endif //POKERSIMULATIONSINCPP_RESTRICTEDCARDCOLLECTION_H
