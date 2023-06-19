#ifndef VIEWER_2_MODEL_VMODEL_H_
#define VIEWER_2_MODEL_VMODEL_H_
// #include <float.h>  // для DBL_MAX? надо поменять на с++ библтотеку

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
  VModel() : edges_num_(0), facetes_num_(0), file_name_(""), vertex_num_(0) {}
  ~VModel() {}

  std::vector<int>& GetEdges() { return edges_; }
  std::vector<double>& GetVertices() { return vertex_; }

  // int GetEdgesNum() const { return edges_num_; }
  // int GetFacetesNum() const { return facetes_num_; }
  std::string GetFileName() const { return file_name_; }
  // int GetVertexNum() const { return vertex_num_; }
  ModelInformation GetInformation() const {
    ModelInformation info;
    info.edges_number = edges_num_;
    info.facetes_number = facetes_num_;
    info.file_name = file_name_;
    info.vertices_number = vertex_num_;
    return info;
  }

  enum CoordinateAxis { kX, kY, kZ };

  void Inscribe();
  void ReadModelFile(std::string file_name);
  void Scaling(double scale);
  void XRotation(double x_rot);
  void XShift(double x_shift);
  void YRotation(double y_rot);
  void YShift(double y_shift);
  void ZRotation(double z_rot);
  void ZShift(double z_shift);
  void Shift(double shift, CoordinateAxis ca);

 private:
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
  void UniquelizationEdges();
  void VertexAdd(std::string line);
  void XScaling(double scale);
  void YScaling(double scale);
  void ZScaling(double scale);
};
}  // namespace s21

#endif  //  VIEWER_2_MODEL_VMODEL_H_
