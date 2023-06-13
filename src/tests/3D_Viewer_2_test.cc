#include <gtest/gtest.h>

#include <cmath>
// #include <iostream>

#include "../model/vmodel.h"

const double kAcc = 1e-7;

TEST(Viewer, ReadModelFileBadload_0) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("cuba.obj"));
}

TEST(Viewer, ReadModelFileBadload_1) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_3.obj"));
}

TEST(Viewer, ReadModelFileBadload_2) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_4.obj"));
}

TEST(Viewer, ReadModelFileBadload_3) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_5.obj"));
}

TEST(Viewer, ReadModelFileBadload_4) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_6.obj"));
}

TEST(Viewer, ReadModelFileBadload_5) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_7.obj"));
}

TEST(Viewer, ReadModelFileBadload_6) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_8.obj"));
}

TEST(Viewer, ReadModelFileLoad_0) {
  s21::VModel model;
  ASSERT_NO_THROW(model.ReadModelFile("tests/models/cube.obj"));
}

TEST(Viewer, ReadModelFile_0) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube_2.obj");
  ASSERT_EQ(model.GetFileName(), "cube_2.obj");
  ASSERT_EQ(model.GetVertexNum(), 8);
  ASSERT_EQ(model.GetFacetesNum(), 7);
  ASSERT_EQ(model.GetEdgesNum(), 13);
}

TEST(Viewer, ReadModelFile_1) {
  s21::VModel model;
  model.ReadModelFile("tests/models/12140_Skull_v3_L2.obj");
  ASSERT_EQ(model.GetFileName(), "12140_Skull_v3_L2.obj");
  ASSERT_EQ(model.GetVertexNum(), 40062);
  ASSERT_EQ(model.GetFacetesNum(), 40728);
  ASSERT_EQ(model.GetEdgesNum(), 80736);
}

// TEST(Viewer, ReadModelFile_2) {
//   s21::VModel model;
//   model.ReadModelFile("tests/models/tree.obj");
//   ASSERT_EQ(model.GetFileName(), "tree.obj");
//   ASSERT_EQ(model.GetVertexNum(), 1109209);
//   ASSERT_EQ(model.GetFacetesNum(), 1885436);
//   ASSERT_EQ(model.GetEdgesNum(), 1885436);
// }

// TEST(Viewer, ReadModelFile_3) {
//   s21::VModel model;
//   model.ReadModelFile("tests/models/Lion.obj");
//   ASSERT_EQ(model.GetFileName(), "Lion.obj");
//   ASSERT_EQ(model.GetVertexNum(), 2499994);
//   ASSERT_EQ(model.GetFacetesNum(), 5000000);
//   ASSERT_EQ(model.GetEdgesNum(), 7500000);
// }

TEST(Viewer, ReadModelFile_vertex) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 2, 2,
                                2, 0, 0, 2, 0, 2, 2, 2, 0, 2, 2, 2};
  for (size_t i = 0; i < result.size() - 1; ++i) {
    // std::cout << result[i] << std::endl;
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

// TEST(Viewer, ReadModelFile_inscribe) {
//   std::vector<double> vert_ref{-0.5, -0.5, -0.5, -0.5, -0.5, 0.5,  -0.5, 0.5,
//                                -0.5, -0.5, 0.5,  0.5,  0.5,  -0.5, -0.5, 0.5,
//                                -0.5, 0.5,  0.5,  0.5,  -0.5, 0.5,  0.5, 0.5};
//   s21::VModel model;
//   model.ReadModelFile("tests/models/cube.obj");
//   model.Inscribe();
//   std::vector<double> vert_result = model.GetVertices();
//   for (size_t i = 0; i < vert_result.size() - 1; ++i) {
//     ASSERT_NEAR(vert_result[i], vert_ref[i], kAcc);
//   }
// }

TEST(Viewer, ReadModelFile_shift) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.XShift(-1);
  model.YShift(-1);
  model.ZShift(-1);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{-1, -1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1,
                                1,  -1, -1, 1,  -1, 1, 1,  1, -1, 1,  1, 1};
  for (size_t i = 0; i < result.size() - 1; ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

TEST(Viewer, ReadModelFile_scaling) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.Scaling(2.15);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0,   0,   0,   0,   4.3, 0,   4.3,
                                0, 0,   4.3, 4.3, 4.3, 0,   0,   4.3,
                                0, 4.3, 4.3, 4.3, 0,   4.3, 4.3, 4.3};
  for (size_t i = 0; i < result.size() - 1; ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

TEST(Viewer, ReadModelFile_rotation_x) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.XRotation(90);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0, 0, 0, 2, 0, 0, 0, -2, 0, 2, -2,
                                2, 0, 0, 2, 2, 0, 2, 0, -2, 2, 2, -2};
  for (size_t i = 0; i < result.size() - 1; ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

TEST(Viewer, ReadModelFile_rotation_y) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.YRotation(90);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0, 0,  2, 0, 0,  0, 2, 0,  2, 2, 0,
                                0, 0, -2, 2, 0, -2, 0, 2, -2, 2, 2, -2};
  for (size_t i = 0; i < result.size() - 1; ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

TEST(Viewer, ReadModelFile_rotation_z) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.ZRotation(90);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0, 0, 0, 0, 2, -2, 0, 0, -2, 0, 2,
                                0, 2, 0, 0, 2, 2, -2, 2, 0, -2, 2, 2};
  for (size_t i = 0; i < result.size() - 1; ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
