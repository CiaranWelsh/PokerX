
#include <iostream>
#include "PokerX/engine/PlayerToAct.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"
#include "PokerX/engine/Check.h"
#include "PokerX/engine/Fold.h"
#include "PokerX/engine/Raise.h"
#include "PokerX/engine/Call.h"
#include "PokerX/engine/AllIn.h"
#include "PokerX/Error.h"

namespace pokerx {

    void PlayerToAct::enter(StateMachine *machine) {
        std::cout << "Entering TurnToAct" << std::endl;

    }

    void PlayerToAct::action(StateMachine *machine) {

        // downcast to the poker engine
        auto *engine = dynamic_cast<PokerEngine *>(machine);
        
        // get reference to currently active player
        SharedPlayerPtr player = engine->getPlayers()->getCurrentPlayer();
        
        // select action using whatever strategy Player types define
        Action action = player->selectAction(machine);

        switch (action) {
            case CHECK : {
                engine->setState(Check::getInstance());
                break;
            }
            
            case FOLD : {
                engine->setState(Fold::getInstance());
                break;
            }

            case CALL : {
                engine->setState(Call::getInstance());
                break;
            }

            case RAISE : {
                engine->setState(Raise::getInstance());
                break;
            }

            case ALL_IN : {
                engine->setState(AllIn::getInstance());
                break;
            }
            default:
                LOGIC_ERROR << "Shouldn't ever get here" << std::endl;

        }
    }

    void PlayerToAct::exit(StateMachine *machine) {}

    PlayerToAct &PlayerToAct::getInstance() {
        static PlayerToAct singleton;
        return singleton;
    }

    unsigned int PlayerToAct::getType() const {
        return PLAYER_TO_ACT_STATE;
    }
}
