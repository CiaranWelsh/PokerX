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

        virtual ~RotatoryContainer() = default;

        /**
         * @brief rotate
         * @details vector {1, 2, 3} becomes {1, 3, 2}
         * @returns a copy of containing items with order displaced by 1
         */
        virtual void rotateContainerContents() {
            {
                if (contents_.size() == 1) {
                    return;
                }
                std::vector<T> new_contents(contents_.size());

                for (int i = 0; i < contents_.size() - 1; i++) { // -1 for penultimate element
                    new_contents[i + 1] = contents_[i];
                }

                // deal with last
                new_contents[0] = contents_[contents_.size() - 1];
                // assign new contents vector to old
                contents_ = new_contents;
            }
        };

    protected:
        /**
         * Needed because superclass is a template
         */
        using Container<T>::contents_;



    };

}
#endif //POKERX_ROTATORYCONTAINER_H
