#ifndef ELEVATION_DATASET_H
#define ELEVATION_DATASET_H

#include <cmath>
#include <cstdlib>  // for size_t
#include <fstream>
#include <vector>


class ElevationDataset {
public:
  // write behavior declarations here; define in elevation_dataset.cc.
  ElevationDataset(const std::string& filename, size_t width, size_t height);

  size_t Width() const;
  size_t Height() const;

  int MaxEle() const;
  int MinEle() const;

  int DatumAt(size_t row, size_t col) const;

  const std::vector<std::vector<int>>& GetData() const;

private:
  // dimentions of the data set
  size_t width_;
  size_t height_;
  std::vector<std::vector<int>> data_;  // get Data
  int max_ele_;
  int min_ele_;
};

#endif