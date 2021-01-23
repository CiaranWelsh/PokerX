//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_ISUBJECT_H
#define POKERSIMULATIONSINCPP_ISUBJECT_H

#include <vector>
#include <memory>
#include "PokerX/engine/Observer.h"
#include "PokerX/engine/Player.h"


namespace pokerx {


    template<class T>
    class Observable {
        using SharedObserverPtr = std::shared_ptr<Observer<T>>;

    public:
        void notifyObservers(T &source, const std::string &data_field) {
            for (auto it : observers_) {
                it->updateObservers(source, data_field);
            }
        }

        void registerObserver(SharedObserverPtr observer) {
            observers_.push_back(observer);
        }

        void removeObserver(SharedObserverPtr observer) {
            for (int i = 0; i < observers_.size(); i++) {
                if (observers_[i] == observer) {
                    observers_.erase(i);
                }
            }
        }

    private:
        std::vector<SharedObserverPtr> observers_{};
    };

}
#endif //POKERSIMULATIONSINCPP_ISUBJECT_H
