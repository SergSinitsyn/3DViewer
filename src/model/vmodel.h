#ifndef VIEWER_2_MODEL_VMODEL_H_
#define VIEWER_2_MODEL_VMODEL_H_
#include <float.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const double kMy_pi = 3.14159265358979323846;

namespace s21 {
class VModel {
 public:
  VModel() : edges_num_(0), facetes_num_(0), file_name_(""), vertex_num_(0) {}
  ~VModel() {}

  std::vector<int> GetEdges() { return edges_; }
  int GetEdgesNum() const { return edges_num_; }
  int GetFacetesNum() const { return facetes_num_; }
  std::string GetFileName() const { return file_name_; }
  std::vector<double> GetVertex() const { return vertex_; }
  int GetVertexNum() const { return vertex_num_; }

  void Inscribe();
  void ReadModelFile(std::string file_name);
  void Scaling(double scale);
  void XRotation(double x_rot);
  void XShift(double x_shift);
  void YRotation(double y_rot);
  void YShift(double y_shift);
  void ZRotation(double z_rot);
  void ZShift(double z_shift);

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
  bool IsDigit(const char &element);
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