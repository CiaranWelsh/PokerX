//
// Created by Ciaran Welsh on 25/01/2021.
//

#ifndef POKERX_BEST5_H
#define POKERX_BEST5_H

#include "PokerX/engine/RestrictedCardCollection.h"

namespace pokerx {

    class RestrictedCardCollection;

    class Best5 : public RestrictedCardCollection{

    public:
        explicit Best5(const std::vector<ICardPtr >& cards);

    };

}

#endif //POKERX_BEST5_H
