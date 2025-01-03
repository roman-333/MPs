#include "cord.hpp"

#include <stdexcept>

#include "cord_utilities.hpp"

Cord::Cord(std::string_view sv): left_(nullptr), right_(nullptr) {
  if (sv.empty()) {
    throw std::runtime_error("empty string");
  }
  try {
    data_ = new char[sv.size() + 1];
  } catch (std::bad_alloc&) {
  }
  for (size_t i = 0; i < sv.size(); ++i) {
    data_[i] = sv.at(i);
  }
  data_[sv.size()] = '\0';
  length_ = sv.size();
}

Cord::~Cord() { delete data_; }

// InorderTraversal

SharedPointer<char> Cord::ToString() const {
  char* to_point_to = new char[length_ + 1];
  int count = 0;
  this->ToStringHelper(to_point_to, count);
  to_point_to[length_] = '\0';
  return *(new SharedPointer<char>(to_point_to, kSharedPointerType::kArray));
}

void Cord::ToStringHelper(char* string, int& count) const {
  if (data_ != nullptr) {
    unsigned int i = 0;
    while (i != length_) {
      string[count] = data_[i];
      count++;
      i++;
    }
    return;
  }
  left_.Get()->ToStringHelper(string, count);
  right_.Get()->ToStringHelper(string, count);
}

SharedPointer<Cord> ConcatCords(const SharedPointer<Cord>& left_cord,
                                const SharedPointer<Cord>& right_cord) {
  if (left_cord.Get() == nullptr || right_cord.Get() == nullptr) {
    throw std::runtime_error("empty cord");
  }
  Cord* address = new Cord;
  address->SetLeft(left_cord);
  address->SetRight(right_cord);
  address->SetLength(left_cord.Get()->Length() + right_cord.Get()->Length());
  return *(new SharedPointer<Cord>(address, kSharedPointerType::kObject));
}