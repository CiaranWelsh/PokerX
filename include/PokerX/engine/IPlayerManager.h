//
// Created by Ciaran Welsh on 23/01/2021.
//

#ifndef POKERX_IPLAYERMANAGER_H
#define POKERX_IPLAYERMANAGER_H

#include <PokerX/engine/hands/Hand.h>
#include "PokerX/engine/Player.h"
#include "PokerX/engine/RotatoryContainer.h"
#include <algorithm>

namespace pokerx {
    class IPlayerManager : public RotatoryContainer<SharedIPlayerPtr> {
    public:
        using RotatoryContainer<SharedIPlayerPtr>::RotatoryContainer;

        [[nodiscard]] virtual bool allPlayersEqual() = 0;

        [[nodiscard]] virtual SharedIPlayerPtr getCurrentPlayer() const = 0;

        virtual void watch(IGameVariables *variables) = 0;

        virtual void moveButton() = 0;

        virtual void nextPlayer() = 0;

        virtual SharedIPlayerPtr getPlayer(unsigned int n) = 0;

        [[nodiscard]] virtual int getCurrentPlayerIdx() const = 0;

        virtual void setCurrentPlayerIdx(int currentPlayerIdx) = 0;

        virtual void setCurrentPlayerByName(const std::string &name) = 0;

        virtual SharedIPlayerPtr getPlayerByName(const std::string &name) = 0;

        virtual SharedIPlayerPtr getButton() = 0;

        virtual void setButton(std::string playerName) = 0;

        virtual int getIndexOfPlayer(const SharedIPlayerPtr &player) = 0;

        virtual void setStackSizeTo(float amount) = 0;

        virtual void enumeratePlayerNames() = 0;

        virtual void enumerateEmptyPlayerNames() = 0;

        virtual std::vector<std::string> getPlayerNames() = 0;

        virtual void resetAmountContribThisStreet() = 0;

        virtual std::vector<Hand> getPlayerHands() = 0;

        virtual void reset() = 0;

        virtual SharedIPlayerPtr getSmallBlind() = 0;

        virtual SharedIPlayerPtr getBigBlind() = 0;

        virtual bool allPlayersTakenAtLeastOneTurn() = 0;

        virtual int getNumPlayersStillInPot() = 0;

    protected:
        int current_player_idx = 0;

    };
}

#endif //POKERX_IPLAYERMANAGER_H
