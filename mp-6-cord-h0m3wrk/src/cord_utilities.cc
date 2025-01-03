
#include "cord_utilities.hpp"

#include <stdexcept>

SharedPointer<Cord> UnevenSubstring(const SharedPointer<Cord>& curr_cord,
                                    unsigned int upper_idx,
                                    unsigned int left_length,
                                    unsigned int lower_idx) {
  SharedPointer<Cord> substr = curr_cord;
  Cord* to_add = new Cord();
  to_add->SetLength(upper_idx - lower_idx);
  if (upper_idx - left_length == substr.Get()->Right()->Length()) {
    to_add->SetRight(substr.Get()->Right());
  } else {
    to_add->SetRight(
        SubString(substr.Get()->Right(), 0, upper_idx - left_length));
  }

  if (left_length - lower_idx == substr.Get()->Left()->Length()) {
    to_add->SetLeft(substr.Get()->Left());
  } else {
    to_add->SetLeft(SubString(substr.Get()->Left(), lower_idx, left_length));
  }
  return {to_add, kSharedPointerType::kObject};
}

SharedPointer<Cord> SubstringHelper(const SharedPointer<Cord>& curr_cord,
                                    unsigned int upper_idx,
                                    unsigned int lower_idx) {
  SharedPointer<Cord> substr = curr_cord;
  unsigned int left_length = substr.Get()->Left().Get()->Length();
  if (upper_idx <= left_length) {
    return SubString(substr.Get()->Left(), lower_idx, upper_idx);
  }
  if (lower_idx >= left_length) {
    return SubString(
        substr.Get()->Right(), lower_idx - upper_idx, upper_idx - left_length);
  }
  return UnevenSubstring(curr_cord, upper_idx, left_length, lower_idx);
}

SharedPointer<Cord> SubString(SharedPointer<Cord> curr_cord,
                              unsigned int lower_idx,
                              unsigned int upper_idx) {
  if (upper_idx > curr_cord->Length() || lower_idx >= upper_idx ||
      lower_idx < 0) {
    throw std::runtime_error("substring not possible");
  }
  if (upper_idx == curr_cord->Length() && lower_idx == 0) {
    return curr_cord;
  }
  SharedPointer<Cord> substr = curr_cord;
  if (substr.Get()->IsDataEmpty()) {
    return SubstringHelper(curr_cord, upper_idx, lower_idx);
  }
  char* to_return = new char[upper_idx - lower_idx + 1];
  for (unsigned int idx = lower_idx; idx < upper_idx; ++idx) {
    to_return[idx - lower_idx] = substr.Get()->Data().at(idx);
  }
  to_return[upper_idx - lower_idx] = '\0';
  return *(new SharedPointer<Cord>(new Cord(to_return),
                                   kSharedPointerType::kObject));
}