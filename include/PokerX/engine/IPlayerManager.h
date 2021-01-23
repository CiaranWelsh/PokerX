//
// Created by Ciaran Welsh on 23/01/2021.
//

#ifndef POKERX_IPLAYERMANAGER_H
#define POKERX_IPLAYERMANAGER_H

#include "PokerX/engine/Player.h"
#include "PokerX/engine/RotatoryContainer.h"

namespace pokerx {
    class IPlayerManager : public RotatoryContainer<SharedPlayerPtr> {
    public:
        [[nodiscard]] virtual bool checkAllPlayersEqual() const = 0;

        virtual SharedPlayerPtr getButton() = 0;

        [[nodiscard]] virtual const SharedPlayerPtr &getCurrentPlayer() const = 0;

        virtual void watch(IGameVariables *variables) = 0;

        virtual void moveButton() = 0;

        virtual void nextPlayer() = 0;

        [[nodiscard]] virtual int getButtonIdx() const = 0;

        virtual void setButtonIdx(int buttonIdx) = 0;

        [[nodiscard]] virtual int getCurrentPlayerIdx() const = 0;

        virtual void setCurrentPlayerIdx(int currentPlayerIdx) = 0;

    protected:
        int button_idx = 0;
        int current_player_idx = 0;

        virtual void moveCurrentPlayer() = 0;

    };
}

#endif //POKERX_IPLAYERMANAGER_H
