#ifndef OTHER_STRUCTS_H
#define OTHER_STRUCTS_H

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

#endif  // OTHER_STRUCTS_H