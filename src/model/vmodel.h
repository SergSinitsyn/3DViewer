#ifndef VIEWER_2_MODEL_VMODEL_H_
#define VIEWER_2_MODEL_VMODEL_H_

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../other/structs.h"

#define _USE_MATH_DEFINES  // for M_PI

namespace s21 {
class VModel {
 public:
  VModel()
      : edges_num_(0),
        facetes_num_(0),
        file_name_(""),
        vertex_num_(0),
        x_min_(0),
        x_max_(0),
        y_min_(0),
        y_max_(0),
        z_min_(0),
        z_max_(0) {}
  ~VModel() {}

  std::vector<int>& GetEdges() { return edges_; }
  std::vector<double>& GetVertices() { return vertex_; }
  ModelInformation GetInformation() const {
    ModelInformation info;
    info.edges_number = edges_num_;
    info.facetes_number = facetes_num_;
    info.file_name = file_name_;
    info.vertices_number = vertex_num_;
    return info;
  }

  virtual void Inscribe();
  virtual void RestoreModel() { throw std::runtime_error("Not implemented"); };
  void ReadModelFile(std::string file_name);
  void Scaling(double scale);
  void XRotation(double x_rot);
  void XShift(double x_shift);
  void YRotation(double y_rot);
  void YShift(double y_shift);
  void ZRotation(double z_rot);
  void ZShift(double z_shift);

 protected:
  enum CoordinateAxis { kX, kY, kZ };
  std::vector<int> edges_;
  int edges_num_;
  int facetes_num_;
  std::string file_name_;
  std::vector<double> vertex_;
  int vertex_num_;

  double x_min_;
  double x_max_;
  double y_min_;
  double y_max_;
  double z_min_;
  double z_max_;

  void Centering();
  void EdgesAdd(std::string line);
  int EdgesCount(std::string line);
  void EdgeDuplicateDel();
  void EdgeSort();
  void EdgeVertexSort();
  void ExtremesSearch();
  double InRadian(double angle_of_rotation);
  double MaxSize();
  void ModelClean();
  void QuickSort(int first, int last);
  void Shift(double shift, CoordinateAxis ca);
  void UniquelizationEdges();
  void VertexAdd(std::string line);
};
}  // namespace s21

#endif  //  VIEWER_2_MODEL_VMODEL_H_
