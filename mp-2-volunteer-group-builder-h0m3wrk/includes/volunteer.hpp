#ifndef VOLUNTEER_HPP
#define VOLUNTEER_HPP

#include <string>

#include "constants.hpp"

const int kMinBuildingExp = 0;
const int kMinStamina = 0;

const int kMaxBuildingExp = 10;
const int kMaxStamina = 10;

class Volunteer {
public:
  Volunteer(const std::string& name,
            int building_experience,
            int physical_stamina,
            bool returning);

  std::string GetName() const;

  int GetBuildingExperience() const;

  int GetPhysicalStamina() const;

  bool IsReturning() const;

private:
  std::string name_;
  int building_experience_ = 0;
  int physical_stamina_ = 0;
  bool returning_;
};

#endif