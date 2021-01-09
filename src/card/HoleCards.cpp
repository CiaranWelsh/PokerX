//
// Created by CiaranWelsh on 18/12/2019.
//

#include "HoleCards.h"
#include "Error.h"

using namespace std;

namespace cards {


    HoleCards::HoleCards(ICard* card1, ICard* card2)
        : RestrictedCardCollection({card1, card2}, 2){
    }
}