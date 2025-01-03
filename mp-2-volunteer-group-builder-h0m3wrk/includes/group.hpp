#ifndef GROUP_HPP
#define GROUP_HPP

#include <iostream>  //was istream
#include <vector>

#include "volunteer.hpp"

class Group {
public:
  void AddVolunteer(const Volunteer& vol);

  double GetAvgBuildingExp() const;

  int GetReturningMembers() const;

  double GetAvgStamina() const;

  friend std::ostream& operator<<(std::ostream& os, const Group& g_in);

  Volunteer& GetRandomVolunteer();

  int SizeOfGroup() const;

private:
  std::vector<Volunteer> volunteers_;
};

std::ostream& operator<<(std::ostream& os, const Group& g_in);

#endif
