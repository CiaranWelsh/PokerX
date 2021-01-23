//
// Created by Ciaran Welsh on 23/01/2021.
//

#ifndef POKERX_IGAMEVARIABLES_H
#define POKERX_IGAMEVARIABLES_H

#include "PokerX/engine/Pot.h"
#include "PokerX/engine/Streets.h"
#include "PokerX/engine/Observable.h"

namespace pokerx {

    template<class T>
    class Observable;

    class IGameVariables : public Observable<IGameVariables> {
    public:

        [[nodiscard]] virtual Pot getPot() const = 0;

        [[nodiscard]] virtual float getAmountToCall() const = 0;

        virtual void setAmountToCall(float amountToCall) = 0;

        virtual void addToPot(const Pot &pot) = 0;

        [[nodiscard]] virtual bool isCheckAvailable() const = 0;

        virtual void setCheckAvailable(bool checkAvailable) = 0;

        [[nodiscard]] virtual Street getStreet() const = 0;

        virtual void setStreet(Street street) = 0;

        [[nodiscard]] virtual float getSmallBlind() const = 0;

        virtual void setSmallBlind(float smallBlind) = 0;

        [[nodiscard]] virtual float getBigBlind() const = 0;

        virtual void setBigBlind(float bigBlind) = 0;

    private:

        Pot pot_;

        float amount_to_call_ = 0.0;

        bool checkAvailable_ = true;

        Street street_ = PREFLOP_STREET;

        float smallBlind_ = 1.0;

        float bigBlind_ = 2.0;

    };

}
#endif //POKERX_IGAMEVARIABLES_H
