//
// Created by Roie Malykin on 7/22/2020.
//
/**
 * This Class
 */
#ifndef FORCPPEXAM_RANGE_H
#define FORCPPEXAM_RANGE_H

namespace itertools
{
    class range{
        int _begin;
        int _end;


    public:
        typedef int value_type; // For other classes use
        // Constructor
        range(int begin , int end): _begin(begin) , _end(end){}

        class iterator{
            int _data;
        public:
            // Explicit Constructor
            explicit iterator(int data) : _data(data) {}
            // Copy Constructor
            iterator( const iterator& other ) = default;
            // Assing "=" operator
            iterator& operator=( const iterator& other)
            {
                if(this != &other)
                    this->_data = other._data;
                return *this;
            }
            // Increment opertaor "++()"
            iterator& operator ++()
            {
                ++_data;
                return *this;
            }
            iterator operator ++(int)
            {
                iterator tmp = *this;
                ++_data;
                return tmp;
            }
            // Compare operator "=="
            bool operator ==(const iterator& other){ return _data == other._data;}

            // Not equal operator
            bool operator !=(const iterator& other){ return _data != other._data;}

            value_type operator *(){return _data;}
        }; // End of Iterator

        iterator begin() {return iterator(_begin);}
        iterator end() {return iterator(_end);}



    }; //End of range

};// End of itertools

#endif //FORCPPEXAM_RANGE_H
