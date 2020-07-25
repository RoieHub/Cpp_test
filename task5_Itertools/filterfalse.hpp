//
// Created by Roie Malykin
//

#ifndef FORCPPEXAM_FILTERFALSE_H
#define FORCPPEXAM_FILTERFALSE_H
#include <iostream>
#include <vector>
namespace itertools {
    template < typename FUNC , typename CONT>
    class filterfalse {

         FUNC _filter;
        CONT& _cont;
        typedef typename CONT::value_type value_type; // Hold the type inside the container
    public:
         filterfalse(FUNC filter,CONT &cont  )
                :  _filter(filter),_cont(cont) {};

        filterfalse(const filterfalse& other) = default;

        class iterator {
            typename CONT::iterator _iter;
            typename CONT::iterator _end;
            FUNC _function;
        public:
            explicit iterator(typename CONT::iterator iter,typename CONT::iterator end, FUNC func)
                    : _iter(iter), _end(end), _function(func)
                    {
                            while (_iter != _end && _function(*_iter)) // Iterate over the container until the first occurrence of a legal val
                            { ++_iter; }
                    }

            iterator(filterfalse::iterator &other) = default;


            /**
             * This operator iterates over the conteiner ,  untill we found the first occurance of a good value;
               * if none found , return _end;
             * @return
             */
            iterator &operator++() {
                do { ++_iter; }
                while (_iter != _end && _function(*_iter)) ;//
                return *this;
            }

            iterator operator++(int) {
                filterfalse::iterator temp = *this;
                ++(*this);
                return temp;
            }

            bool operator==(const iterator &other) {
                return _iter == other.iter;
            }

            bool operator!=(const iterator &other) {
                return _iter != other._iter;
            }

            iterator operator =
            (
            const iterator &other
            )
            {
                if (this != &other)

                    this->_iter = other._iter;
                this->_end = other._end;
                this->_function = other._function;
            }

            value_type operator*() { return *_iter;}


        }; // End iterator

        iterator begin() {
            return iterator(_cont.begin(), _cont.end(), _filter);
        }

        iterator end() {
            return iterator(_cont.end(), _cont.end(), _filter);
        }


    };// ENd filterfalse
}// End of itertools





#endif //FORCPPEXAM_FILTERFALSE_H
