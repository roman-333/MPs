#include "group.hpp"
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

#include "constants.hpp"
#include "volunteer.hpp"

void Group::AddVolunteer(const Volunteer& vol) { volunteers_.push_back(vol); }

double Group::GetAvgBuildingExp() const {
  if (volunteers_.empty()) {
    return 0.0;
  }
  double sum = 0.0;
  for (const Volunteer& vol : volunteers_) {
    sum += vol.GetBuildingExperience();
  }
  auto num_vol = static_cast<double>(volunteers_.size());
  return sum / num_vol;
}

double Group::GetAvgStamina() const {
  if (volunteers_.empty()) {
    return 0.0;
  }
  double sum = 0.0;
  for (const Volunteer& vol : volunteers_) {
    sum += vol.GetPhysicalStamina();
  }
  auto num_vol = static_cast<double>(volunteers_.size());
  return sum / num_vol;
}

int Group::GetReturningMembers() const {
  int returning_count = 0;
  for (const Volunteer& vol : volunteers_) {
    if (vol.IsReturning()) {
      returning_count++;
    }
  }
  return returning_count;
}

Volunteer& Group::GetRandomVolunteer() {
  if (volunteers_.empty()) {
    throw std::out_of_range("Group is empty");
  }
  std::srand(time(nullptr));
  unsigned int random_index = std::rand() % volunteers_.size();
  return volunteers_[random_index];
}

int Group::SizeOfGroup() const {
  size_t count = volunteers_.size();
  auto num_val = static_cast<int>(count);

  return num_val;
}
std::ostream& operator<<(std::ostream& os, const Group& g_in) {
  os << "B-XP: " << g_in.GetAvgBuildingExp() << ", ST: " << g_in.GetAvgStamina()
     << ", RET: " << g_in.GetReturningMembers() << "\n";

  for (const Volunteer& vol : g_in.volunteers_) {
    os << vol.GetName() + "\n";
  }
  return os;
}