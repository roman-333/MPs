#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <ostream>
#include <utility>

#include "constants.hpp"
#include "group.hpp"

/*Write your main driver in this file! Remember to seperate
out things into functions to help with readability and reusability.

See specifications for how to get started and
go to office hours if you need help!*/

std::vector<Group> ReadVolunteerData(const std::string& input_file,
                                     int num_volunteers);
bool Swapping(std::vector<Group>& groups);
void PrintGroupsToFile(const std::vector<Group>& groups,
                       const std::string& outputFilename);

std::vector<Group> ReadVolunteerData(const std::string& input_file,
                                     int num_volunteers) {
  std::vector<Group> groups;
  std::ifstream ifs(input_file);

  std::vector<Volunteer> volunteers;
  std::string name;
  int building_experience = 0;
  int physical_stamina = 0;
  bool returning = false;

  // Or use int i < numVolunteers, are both the sasme thing?
  int i = 0;
  while (i < num_volunteers) {
    ifs >> name >> building_experience >> physical_stamina >> returning;
    volunteers.push_back(
        Volunteer(name, building_experience, physical_stamina, returning));

    if (volunteers.size() == kSizeGroups) {
      Group current_group;
      for (const Volunteer& volunteer : volunteers) {
        current_group.AddVolunteer(volunteer);
      }
      groups.push_back(current_group);

      volunteers.clear();
    }
    ++i;
  }
  ifs.close();
  return groups;
}

bool Swapping(std::vector<Group>& groups) {
  int count = 0;
  while (count < kMaxIterations) {
    unsigned int index1 = std::rand() % groups.size();
    ++count;
    Group& group = groups.at(index1);

    for (unsigned int i = 0; i < groups.size(); ++i) {
      if (groups.at(i).GetAvgBuildingExp() < kMinAvgBuildingExp ||
          groups.at(i).GetAvgStamina() < kMinAvgStamina ||
          groups.at(i).GetReturningMembers() < kMinReturning) {
        if (index1 != i) {
          std::swap(group.GetRandomVolunteer(),
                    groups.at(i).GetRandomVolunteer());
        } else {
          continue;
        }
      }
    }
    if (count > kMaxIterations) {
      std::cout << "No groups found" << std::endl;
      return false;
    }
  }
  return true;
}
// check all groups
//  print"" if are not vaild within iteration

void PrintGroupsToFile(const std::vector<Group>& groups,
                       const std::string& outputFile) {
  std::ofstream out_file(outputFile);

  if (!out_file.is_open()) {
    std::cout << "Error: file did not open" << std::endl;
  }

  for (const Group& group : groups) {
    out_file << group;
  }
  out_file.close();
}

int main(int argc, char* argv[]) {
  // DO NOT EDIT THIS LINE or add another srand call.
  srand(time(nullptr));

  if (argc != 4) {
    std::cout << "error";
    return 1;
  }

  std::string input_file = argv[1];
  int num_volunteers = std::stoi(argv[2]);
  std::string output_file = argv[3];

  std::ifstream ifs(input_file);
  if (!ifs.is_open()) {
    std::cout << "Error opening file: " << std::endl;
    return 1;
  }

  std::vector<Group> groups = ReadVolunteerData(input_file, num_volunteers);
  bool indicatior = Swapping(groups);

  if (indicatior) {
    PrintGroupsToFile(groups, output_file);
  }
  return 0;
}
