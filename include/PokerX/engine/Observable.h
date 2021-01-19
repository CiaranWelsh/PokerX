//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_ISUBJECT_H
#define POKERSIMULATIONSINCPP_ISUBJECT_H

#include <vector>
#include "PokerX/engine/Observer.h"

namespace pokerx {


    template<typename T>
    class Observable {
    public:
        void notify(T &source, const std::string &data_field) {
            for (auto* it : observers_){
                it->update(source, data_field);
            }
        }

        void addSubscriber(Observer<T> *observer) {
            observers_.push_back(observer);
        }

        void removeSubscriber(Observer<T> *observer) {
            for (int i = 0; i < observers_.size(); i++) {
                if (observers_[i] == observer) {
                    observers_.erase(i);
                }
            }
        }

    private:
        std::vector<Observer<T> *> observers_{};
    };

}
#endif //POKERSIMULATIONSINCPP_ISUBJECT_H
