//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_IOBSERVABLESHAREDPTR_H
#define POKERSIMULATIONSINCPP_IOBSERVABLESHAREDPTR_H

#include <vector>
#include <memory>
#include "PokerX/engine/IObserver.h"


namespace pokerx {


    /**
     * @brief implementation of the Observable portion of the Observer
     * pattern. Uses raw pointers to store references to Observers
     */
    template<class T>
    class IObservableRawPtr {

    public:

        virtual ~IObservableRawPtr<T>() = default;

        /**
         * @brief notify all subscribed observers (@see registerObserver)
         * that the @param data_field of object @param source has changed
         */
        void notifyObservers(T &source, const std::string &data_field) {
            for (auto observer : observers_) {
                observer->update(source, data_field);
            }
        }

        /**
         * @brief regester an observer (or subscriber) to this
         * observable.
         * @details Once subscribed, Observers are informed of
         * any changes when the notifyObservers method is called.
         * A shared pointer is created from the raw input pointer.
         * @param observer A shared pointer to an Observer<T>
         */
        void registerObserver(IObserver <T> *observer) {
            observers_.push_back(observer);
        }

        /**
         * @brief erase a observer from the list of observers
         */
        void removeObserver(IObserver <T> *observer) {
            for (int i = 0; i < observers_.size(); i++) {
                if (observers_[i] == observer) {
                    observers_.erase(i);
                }
            }
        }

    private:
        std::vector<IObserver < T>*> observers_{};

        //todo add mutex lock to enable thread safety
    };


}
#endif //POKERSIMULATIONSINCPP_ISUBJECT_H
