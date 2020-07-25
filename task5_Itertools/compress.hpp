//
// Created by CyberLab on 7/25/2020.
//

#ifndef TASK5_ITERTOOLS_COMPRESS_H

namespace itertools {
    template <typename CONT, typename BOOL_CONT>
    class compress {
        CONT &_cont;
        BOOL_CONT& _bool_cont;
        typedef typename CONT::value_type value_type;
    public:

         compress( CONT& cont,  BOOL_CONT& bool_cont)
                : _cont(cont), _bool_cont(bool_cont) {}
        compress(  CONT&& cont,  BOOL_CONT& bool_cont)
                : _cont(cont), _bool_cont(bool_cont) {}
        compress(  CONT& cont,  BOOL_CONT&& bool_cont)
                : _cont(cont), _bool_cont(bool_cont) {}
        compress(  CONT&& cont,  BOOL_CONT&& bool_cont)
                : _cont(cont), _bool_cont(bool_cont) {}

        compress(const compress &other) = default;

        class iterator {
            typename CONT::iterator _cont_itr;
            typename CONT::iterator _cont_end;
            typename BOOL_CONT::iterator _bool_itr;
            typename BOOL_CONT::iterator _bool_end;

        public:
            iterator(typename CONT::iterator cont_itr,
                     typename CONT::iterator cont_end,
                     typename BOOL_CONT::iterator bool_itr,
                     typename BOOL_CONT::iterator bool_end
            ): _cont_itr(cont_itr), _cont_end(cont_end), _bool_itr(bool_itr), _bool_end(bool_end)
            {
                while (_cont_itr != _cont_end && !*_bool_itr) {
                    ++(_bool_itr);
                    ++(_cont_itr);
                }
            }

            iterator(const iterator &other) = default;

            // Operations

            iterator &operator++() {
                do {
                    ++(_bool_itr);
                    ++(_cont_itr);
                } while (_cont_itr != _cont_end && !*_bool_itr);
                return *this;
            }

            iterator operator++(int) {
                iterator temp = *this;
                ++(*this);
                return temp;
            }

            value_type operator*() { return *(_cont_itr); }

            bool operator==(const iterator &other) // Check iter values only
            { return _cont_itr == (other._cont_itr); }

            bool operator!=(const iterator &other) // Check iter values only
            { return _cont_itr != (other._cont_itr); }

            iterator &operator=(const iterator &other) // To assing const and unconst vals
            {
                if (this != &other) {
                    this->_cont_itr = other._cont_itr;
                    this->_cont_end = other._cont_end;
                    this->_bool_itr = other._bool_itr;
                    this->_end = other._end;
                }
                return *this;
            };


        };// End of iterator


        iterator begin() {
            return iterator(_cont.begin(), _cont.end(), _bool_cont.begin(), _bool_cont.end());
        }

        iterator end() {
            return iterator(_cont.end(), _cont.end(), _bool_cont.end(), _bool_cont.end());
        }

    };// End of compress
};// End of itertools
#define TASK5_ITERTOOLS_COMPRESS_H

#endif //TASK5_ITERTOOLS_COMPRESS_H
