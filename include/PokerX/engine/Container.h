//
// Created by Ciaran Welsh on 21/01/2021.
//

#ifndef POKERX_CONTAINER_H
#define POKERX_CONTAINER_H

namespace pokerx {

    /**
     * todo make CardCollection implement the container
     */

    template<class T>
    class Container {
    public:
        Container() = default;

        virtual ~Container() = default;

        explicit Container(T contents) : contents_(contents) {};

        explicit Container(std::initializer_list<T> init)
                : contents_(std::vector<T>(init.begin(), init.end())) {}

        explicit Container(std::vector<T> init)
                : contents_(init) {};

        virtual void add(T item) {
            contents_.push_back(item);
        };

        [[nodiscard]] const std::vector<T> &getContents() const {
            return contents_;
        }

        virtual int size() {
            return contents_.size();
        };

        virtual typename std::vector<T>::const_iterator begin() const {
            return contents_.begin();
        };

        virtual typename std::vector<T>::const_iterator end() const {
            return contents_.end();
        };

//        std::ostream &operator<<(std::ostream &os) {
//            for (int i = 0; i < size(); i++) {
//                os << contents_[i] << ", " << std::endl;
//            }
//            return os;
//        };

        void reserve(size_t n) {
            contents_.reserve(n);
        }

        Container<T> &operator==(const Container<T> &other) {
            return contents_ == other.contents_;
        }

        Container<T> &operator!=(const Container<T> &other) {
            return contents_ != other.contents_;
        }

        T operator[](int index) {
            return contents_[index];
        }

    protected:
        std::vector<T> contents_{};
    };

}
#endif //POKERX_CONTAINER_H
