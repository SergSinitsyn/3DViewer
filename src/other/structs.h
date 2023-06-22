#ifndef VIEWER_2_OTHER_STRUCTS_H_
#define VIEWER_2_OTHER_STRUCTS_H_

#include <string>
#include <vector>

struct ModelInformation {
  int edges_number;
  int facetes_number;
  std::string file_name;
  int vertices_number;
};

struct ModelData {
  std::vector<double> vertices;
  std::vector<int> edges;
};

#endif  // VIEWER_2_OTHER_STRUCTS_H_
