//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_CARDCOLLECTIONOBSERVER_H
#define POKERSIMULATIONSINCPP_CARDCOLLECTIONOBSERVER_H


class CardCollectionObserver {
public:
    virtual ~CardCollectionObserver() = default;

    virtual void Update(const CardCollection &cardCollection) = 0;
};

#endif //POKERSIMULATIONSINCPP_CARDCOLLECTIONOBSERVER_H

