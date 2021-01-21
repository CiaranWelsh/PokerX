//
// Created by Ciaran Welsh on 21/01/2021.
//

#ifndef POKERX_ROTATORYCONTAINER_H
#define POKERX_ROTATORYCONTAINER_H

#include "PokerX/engine/Container.h"

namespace pokerx {

    /**
     * @brief container that has ability of rotating the
     * ordering of its contents
     */
    template<class T>
    class RotatoryContainer : public Container<T> {
    public:
        using Container<T>::Container;

    protected:
        /**
         * Needed because superclass is a template
         */
        using Container<T>::contents_;

        /**
         * @brief rotateBackwards
         * @details vector {1, 2, 3} becomes {1, 3, 2}
         * @returns a copy of containing items with order displaced by 1
         */
        virtual void rotateContainerContents() = 0;


    };

}
#endif //POKERX_ROTATORYCONTAINER_H
