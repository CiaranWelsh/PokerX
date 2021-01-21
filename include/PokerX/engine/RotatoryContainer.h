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
        explicit RotatoryContainer(T current)
                : Container<T>(), current_(current) {};

        RotatoryContainer(std::initializer_list<T> init)
            : Container<T>(init), current_(init.begin()){}

        void operator++() {
            rotateBackwards();
        }


    protected:
        /**
         * Needed because superclass is a template
         */
        using Container<T>::contents_;

        /**
         * @brief rotateBackwards
         * @details vector {1, 2, 3} becomes {1, 3, 2}
         */
        void rotate() {
            if (contents_.size() == 1){
                return;
            }
            if (contents_.size() == 2){
                // question: will this work with pointers?
                // create a new test to figure this out.
                T temp = contents_[0];
                contents_[0] = contents_[1];
                contents_[1] = temp;
                return ;
            }
            std::vector<int> new_contents(contents_.size());
            for (int i = 0; i < contents_.size() - 1; i++){ // -1 for penultimate element
                new_contents[i+1] = contents_[i];
            }
            // deal with last
            new_contents[0] = contents_[contents_.size()-1];
            contents_ = new_contents;
            /*
             * Makes this method recursive. Keep rotating until you find a
             * player who is still in the game. All players should be inplace=true
//             * when the game begins
//             */
//            if (!current_player_->isInPlay()) {
//                rotate();
//            }
        }
    private:
        const T* current_;
    };

}
#endif //POKERX_ROTATORYCONTAINER_H
