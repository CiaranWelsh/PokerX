//
// Created by Ciaran on 09/01/2021.
//

#ifndef POKERSIMULATIONSINCPP_CARDCOLLECTIONOBSERVER_H
#define POKERSIMULATIONSINCPP_CARDCOLLECTIONOBSERVER_H


namespace pokerx {

    template<class T>
    class IObserver {
    public:
        virtual ~IObserver() = default;

        virtual void update(T& source, const std::string& data_field) = 0;
    };


}
#endif //POKERSIMULATIONSINCPP_CARDCOLLECTIONOBSERVER_H

