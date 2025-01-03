#ifndef CORD_UTILITIES_HPP
#define CORD_UTILITIES_HPP

#include <stdexcept>

#include "cord.hpp"
#include "shared_pointer.hpp"

SharedPointer<Cord> ConcatCords(const SharedPointer<Cord>& left_cord,
                                const SharedPointer<Cord>& right_cord);

SharedPointer<Cord> SubString(SharedPointer<Cord> curr_cord,
                              unsigned int lower_idx,
                              unsigned int upper_idx);

SharedPointer<Cord> SubstringHelper(const SharedPointer<Cord>& curr_cord,
                                    unsigned int upper_idx,
                                    unsigned int lower_idx);

SharedPointer<Cord> UnevenSubstring(const SharedPointer<Cord>& curr_cord,
                                    unsigned int upper_idx,
                                    unsigned int left_length,
                                    unsigned int lower_idx);

#endif