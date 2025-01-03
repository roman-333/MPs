#ifndef PATH_IMAGE_H
#  define PATH_IMAGE_H

#  include <cstdlib>  // for size_t
#  include <string>
#  include <vector>

#  include "color.hpp"
#  include "elevation_dataset.hpp"
#  include "grayscale_image.hpp"
#  include "path.hpp"

class PathImage {
public:
  PathImage(const GrayscaleImage& image, const ElevationDataset& dataset);

  void AssignGreen(const std::vector<std::vector<int>>& data_copy,
                   std::vector<std::vector<Color>>& image_copy);
  size_t Width() const;

  size_t Height() const;

  unsigned int MaxColorValue() const;

  const std::vector<Path>& Paths() const;

  const std::vector<std::vector<Color>>& GetPathImage() const;

  void ToPpm(const std::string& name) const;

private:
  std::vector<Path> paths_;
  size_t width_ = 0;
  size_t height_ = 0;
  std::vector<std::vector<Color>> path_image_;
  static const int kMaxColorValue = 255;
  static const int kRedR = 252;
  static const int kRedG = 25;
  static const int kRedB = 63;
  static const int kGreenR = 31;
  static const int kGreenG = 253;
  static const int kGreenB = 13;
};

#endif
