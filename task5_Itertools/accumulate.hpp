//
// Created by Roie Malykin Inspired by the work of Nethanel Albert and his grate useage of move constructor!

#ifndef FORCPPEXAM_ACCUMULATE_H
#define FORCPPEXAM_ACCUMULATE_H

#include<iostream>

namespace itertools
{
    typedef struct
    {
        template <typename T>
        T operator () (T a , T b) const{return a+b;}
    } plus; // End of Plus

    template <typename CONT , typename FUNC = plus>
    class accumulate
    {
        CONT& _container;
        FUNC _function;
        typedef typename CONT::value_type value_type;  // Hold the type inside the container
    public:


        explicit accumulate(CONT& container , FUNC func = plus() )
            : _container(container) , _function(func){}



        //// Iterator Calss ////
        class iterator
        {
            value_type _data;
            typename CONT::iterator _iter;
            typename CONT::iterator _end;
            FUNC _function;
        public:
            // Constructors
            explicit iterator(typename CONT::iterator iter , typename CONT::iterator end , FUNC func)
                : _iter(iter), _end(end), _function(func)
            {
                if(_iter != _end)
                    _data = *iter;
            };
            // default copy constructor https://en.cppreference.com/w/cpp/language/copy_constructor
            iterator(const iterator& other) = default;
            // Operators
            iterator& operator=(const iterator& other) // To assing const and unconst vals
            {
                if(this != &other)
                {
                    this->_data = other._data;
                    this->_iter = other._iter;
                    this->_end = other._end;
                    this->_function = other._function;
                }
                return *this;
            };

            iterator& operator ++() // Better optimized
            {
                ++_iter;
                if( _iter != _end) // Must to avoid dereferenccing end() iterator;
                    _data = _function(_data , *_iter);
                return *this;
            }

            iterator operator ++(int){
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            /**
             * for Use to check it.begin() == it.end()
             * @param other
             * @return
             */
            bool operator == (const iterator& other) // Problematic , may not work sometimes
            {
                return _iter == other.iter;
            }
            bool operator != (const iterator& other)
            {
                return _iter != other._iter;
            }

            value_type operator *()
            {
                return this->_data;
            }

        };// End of iterator

        iterator begin()
        {
            return iterator(_container.begin() , _container.end() , _function);
        }

        iterator end()
        {
            return iterator(_container.end() , _container.end() , _function);
        }



    }; // End of accumulate

};// End of nameSpace

#endif //FORCPPEXAM_ACCUMULATE_H
