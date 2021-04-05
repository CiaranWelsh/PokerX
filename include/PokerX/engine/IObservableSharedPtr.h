//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_IOBSERVABLERAWPTR_H
#define POKERSIMULATIONSINCPP_IOBSERVABLERAWPTR_H

#include <vector>
#include <memory>
#include "PokerX/engine/IObserver.h"


namespace pokerx {

    /**
     * @brief implementation of the Observable portion of the Observer
     * pattern. Uses SharedPtr<T> to store references to Observers
     */
    template<class T>
    class [[maybe_unused]] IObservableSharedPtr {
        using SharedObserverPtr = std::shared_ptr<IObserver < T>>;

    public:

        virtual ~IObservableSharedPtr<T>() = default;

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
        void registerObserver(SharedObserverPtr observer) {
            observers_.push_back(observer);
        }


        /**
         * @brief remove a observer from the list of observers
         */
        void removeObserver(SharedObserverPtr observer) {
            for (int i = 0; i < observers_.size(); i++) {
                if (observers_[i] == observer) {
                    observers_.erase(i);
                }
            }
        }

    private:
        std::vector<SharedObserverPtr> observers_{};

        //todo add mutex lock to enable thread safety
    };


}
#endif //POKERSIMULATIONSINCPP_ISUBJECT_H
