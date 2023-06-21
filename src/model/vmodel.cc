#include "vmodel.h"

namespace s21 {

void VModel::ReadModelFile(std::string file_name) {
  ModelClean();
  std::ifstream file(file_name);
  if (!file.is_open())
    throw std::invalid_argument("File read error. The file is missing.");
  file_name_ =
      file_name.substr(file_name.find_last_of("/") + 1, std::string::npos);
  std::string line;
  while (std::getline(file, line)) {
    char first_ch = line[0];
    char second_ch = line[1];
    if (first_ch == 'v' && second_ch == ' ') {
      vertex_num_++;
      VertexAdd(line);
    }
    if (first_ch == 'f' && second_ch == ' ') {
      facetes_num_++;
      edges_num_ += EdgesCount(line);
      EdgesAdd(line);
    }
  }
  if (!edges_.empty()) UniquelizationEdges();
}

void VModel::Inscribe() {
  Centering();
  Scaling(1 / MaxSize());
}

void VModel::Centering() {
  ExtremesSearch();
  XShift(-(x_min_ + x_max_) / 2);
  YShift(-(y_min_ + y_max_) / 2);
  ZShift(-(z_min_ + z_max_) / 2);
}

void VModel::Scaling(double zoom_index) {
  if (zoom_index != 1 && zoom_index != 0) {
    for (size_t i = 0; i < vertex_.size(); ++i) {
      vertex_.at(i) *= zoom_index;
    }
  }
}

void VModel::XRotation(double x_rot) {
  double sin_rot_x = sin(InRadian(x_rot)), cos_rot_x = cos(InRadian(x_rot));
  for (size_t i = 0; i < vertex_.size(); i += 3) {
    double y = vertex_.at(i + 1);
    double z = vertex_.at(i + 2);
    vertex_.at(i + 1) = y * cos_rot_x - z * sin_rot_x;
    vertex_.at(i + 2) = z * cos_rot_x + y * sin_rot_x;
  }
}

void VModel::YRotation(double y_rot) {
  double sin_rot_y = sin(InRadian(y_rot)), cos_rot_y = cos(InRadian(y_rot));
  for (size_t i = 1; i < vertex_.size(); i += 3) {
    double x = vertex_.at(i - 1);
    double z = vertex_.at(i + 1);
    vertex_.at(i - 1) = x * cos_rot_y + z * sin_rot_y;
    vertex_.at(i + 1) = z * cos_rot_y - x * sin_rot_y;
  }
}

void VModel::ZRotation(double z_rot) {
  double sin_rot_z = sin(InRadian(z_rot)), cos_rot_z = cos(InRadian(z_rot));
  for (size_t i = 2; i < vertex_.size(); i += 3) {
    double x = vertex_.at(i - 2);
    double y = vertex_.at(i - 1);
    vertex_.at(i - 1) = y * cos_rot_z + x * sin_rot_z;
    vertex_.at(i - 2) = x * cos_rot_z - y * sin_rot_z;
  }
}

void VModel::UniquelizationEdges() {
  EdgeVertexSort();
  EdgeSort();
  EdgeDuplicateDel();
  edges_num_ = edges_.size() / 2;
}

void VModel::EdgeVertexSort() {
  for (size_t i = 0; i < edges_.size(); i += 2) {
    if (edges_.at(i) < edges_.at(i + 1))
      std::swap(edges_.at(i), edges_.at(i + 1));
  }
}

void VModel::EdgeDuplicateDel() {
  std::vector<int> temp;
  temp.push_back(edges_.at(0));
  temp.push_back(edges_.at(1));
  for (size_t i = 2; i < edges_.size() - 2; i += 2) {
    if ((temp.at(temp.size() - 1) != edges_.at(i + 1)) ||
        (temp.at(temp.size() - 1) == edges_.at(i + 1) &&
         temp.at(temp.size() - 2) != edges_.at(i))) {
      temp.push_back(edges_.at(i));
      temp.push_back(edges_.at(i + 1));
    }
  }
  edges_ = temp;
}

void VModel::EdgeSort() { QuickSort(0, edges_.size() - 2); }

void VModel::QuickSort(int first, int last) {
  if (first < last) {
    // int count = 0;
    int left = first, right = last,
        middle = edges_.at((left / 2 + right / 2) / 2 * 2),
        middle_1 = edges_.at((left / 2 + right / 2) / 2 * 2 + 1);
    do {
      // count++;
      while (edges_.at(left) > middle ||
             (edges_.at(left) == middle && edges_.at(left + 1) > middle_1))
        left += 2;
      while (edges_.at(right) < middle ||
             (edges_.at(right) == middle && edges_.at(right + 1) < middle_1))
        right -= 2;
      if (left <= right) {
        std::swap(edges_.at(left), edges_.at(right));
        std::swap(edges_.at(left + 1), edges_.at(right + 1));
        left += 2;
        right -= 2;
      }
    } while (left <= right);
    QuickSort(first, right);
    QuickSort(left, last);
  }
}

void VModel::ExtremesSearch() {
  if (vertex_.size() >= 3) {
    x_max_ = x_min_ = vertex_.at(kX);
    y_max_ = y_min_ = vertex_.at(kY);
    z_max_ = z_min_ = vertex_.at(kZ);
  }
  for (size_t i = 3; i < vertex_.size(); i += 3) {
    if (vertex_.at(i + kX) > x_max_) {
      x_max_ = vertex_.at(i + kX);
    } else if (vertex_.at(i + kX) < x_min_) {
      x_min_ = vertex_.at(i + kX);
    }
    if (vertex_.at(i + kY) > y_max_) {
      y_max_ = vertex_.at(i + kY);
    } else if (vertex_.at(i + kY) < y_min_) {
      y_min_ = vertex_.at(i + kY);
    }
    if (vertex_.at(i + kZ) > z_max_) {
      z_max_ = vertex_.at(i + kZ);
    } else if (vertex_.at(i + kZ) < z_min_) {
      z_min_ = vertex_.at(i + kZ);
    }
  }
}

void VModel::Shift(double shift, CoordinateAxis ca) {
  for (size_t i = ca; i < vertex_.size(); i += 3) {
    vertex_.at(i) += shift;
  }
}

void VModel::XShift(double x_shift) { Shift(x_shift, kX); }
void VModel::YShift(double y_shift) { Shift(y_shift, kY); }
void VModel::ZShift(double z_shift) { Shift(z_shift, kZ); }

double VModel::MaxSize() {
  double max_size = x_max_ - x_min_;
  if (max_size < y_max_ - y_min_) max_size = y_max_ - y_min_;
  if (max_size < z_max_ - z_min_) max_size = z_max_ - z_min_;
  return max_size;
}

double VModel::InRadian(double angle_of_rotation) {
  return angle_of_rotation * M_PI / 180;
}

int VModel::EdgesCount(std::string line) {
  int count = 0;
  for (size_t i = 1; i < line.size(); i++) {
    if (isdigit(line.at(i)) && line.at(i - 1) == ' ') count++;
  }
  if (count == 2) count--;
  return count;
}

void VModel::VertexAdd(std::string line) {
  size_t vertex_count = 0;
  for (size_t i = 1; i < line.size() && vertex_count < 3;) {
    size_t num_size = 0;
    if (line.at(i) != ' ') {
      throw std::invalid_argument(
          "Error reading vertex coordinates. Wrong data.");
    }
    double d = std::stod(&line.at(i), &num_size);
    vertex_.push_back(d);

    ++vertex_count;
    i += num_size;
  }
  if (vertex_count < 3)
    throw std::invalid_argument(
        "Error reading vertex coordinates. Less than three vertex "
        "coordinates.");
}

void VModel::EdgesAdd(std::string line) {
  std::vector<int> temp;
  for (size_t i = 2; i < line.size();) {
    if (line.at(i - 1) != ' ')
      throw std::invalid_argument("Failed to read facet data. Wrong data.");
    int d = std::stoi(&line.at(i)) - 1;
    if (d < 0 || d >= vertex_num_)
      throw std::invalid_argument(
          "Failed to read facet data. The vertex number is out of range.");
    temp.push_back(d);
    temp.push_back(d);
    if (line.find(" ", i) != line.npos) {
      i = line.find(" ", i + 1) + 1;
      for (; i < line.size() && !isdigit(line.at(i));) {
        ++i;
      }
    } else {
      i = line.size();
    }
  }
  edges_.insert(edges_.end(), (++temp.begin()), temp.end());
  edges_.emplace(edges_.end(), *temp.begin());
}

void VModel::ModelClean() {
  file_name_ = "";
  vertex_num_ = 0;
  facetes_num_ = 0;
  edges_num_ = 0;
  if (!vertex_.empty()) vertex_.clear();
  if (!edges_.empty()) edges_.clear();
}

};  // namespace s21
