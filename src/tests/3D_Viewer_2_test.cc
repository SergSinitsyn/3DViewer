#include <gtest/gtest.h>

#include <cmath>
// #include <iostream>

#include "../model/vmodel.h"

const double kAcc = 1e-7;

TEST(Viewer, ReadModelFile_Badload_0) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("cuba.obj"));
}

TEST(Viewer, ReadModelFile_Badload_1) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_3.obj"));
}

TEST(Viewer, ReadModelFile_Badload_2) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_4.obj"));
}

TEST(Viewer, ReadModelFile_Badload_3) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_5.obj"));
}

TEST(Viewer, ReadModelFile_Badload_4) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_6.obj"));
}

TEST(Viewer, ReadModelFile_Badload_5) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_7.obj"));
}

TEST(Viewer, ReadModelFile_Badload_6) {
  s21::VModel model;
  ASSERT_ANY_THROW(model.ReadModelFile("tests/models/cube_8.obj"));
}

TEST(Viewer, ReadModelFile_Load) {
  s21::VModel model;
  ASSERT_NO_THROW(model.ReadModelFile("tests/models/cube.obj"));
}

TEST(Viewer, ReadModelFile_Info) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube_2.obj");
  ModelInformation info = model.GetInformation();
  ASSERT_EQ(info.file_name, "cube_2.obj");
  ASSERT_EQ(info.vertices_number, 8);
  ASSERT_EQ(info.facetes_number, 7);
  ASSERT_EQ(info.edges_number, 13);
}

TEST(Viewer, Vertices) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 2, 2,
                                2, 0, 0, 2, 0, 2, 2, 2, 0, 2, 2, 2};
  for (size_t i = 0; i < result.size(); ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

TEST(Viewer, Edges) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  std::vector<int> result = model.GetEdges();
  std::vector<int> reference{8, 7, 8, 6, 8, 5, 8, 4, 8, 3, 8, 2, 7,
                             5, 7, 3, 7, 1, 6, 5, 6, 4, 6, 2, 6, 1,
                             5, 1, 4, 3, 4, 2, 4, 1, 3, 1, 2, 1};
  for (size_t i = 0; i < result.size(); ++i) {
    ASSERT_EQ(result[i], reference[i] - 1);
  }
}

TEST(Viewer, Inscribe) {
  std::vector<double> vert_ref{-0.5, -0.5, -0.5, -0.5, -0.5, 0.5,  -0.5, 0.5,
                               -0.5, -0.5, 0.5,  0.5,  0.5,  -0.5, -0.5, 0.5,
                               -0.5, 0.5,  0.5,  0.5,  -0.5, 0.5,  0.5,  0.5};
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.Inscribe();
  for (size_t i = 0; i < 10; ++i) {
    model.Scaling(0.5);
  }
  for (size_t i = 0; i < 100; ++i) {
    model.XShift(1);
    model.YShift(1);
    model.ZShift(1);
  }
  for (size_t i = 0; i < 100; ++i) {
    model.XShift(-1);
    model.YShift(-1);
    model.ZShift(-1);
  }
  for (size_t i = 0; i < 360; ++i) {
    model.XRotation(1);
  }
  for (size_t i = 0; i < 360; ++i) {
    model.YRotation(1);
  }
  for (size_t i = 0; i < 360; ++i) {
    model.ZRotation(1);
  }
  model.Inscribe();
  std::vector<double> vert_result = model.GetVertices();
  for (size_t i = 0; i < vert_result.size(); ++i) {
    ASSERT_NEAR(vert_result[i], vert_ref[i], kAcc);
  }
}

TEST(Viewer, Shift) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.XShift(-1);
  model.YShift(-1);
  model.ZShift(-1);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{-1, -1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1,
                                1,  -1, -1, 1,  -1, 1, 1,  1, -1, 1,  1, 1};
  for (size_t i = 0; i < result.size(); ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

TEST(Viewer, Scaling) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.Scaling(2.15);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0,   0,   0,   0,   4.3, 0,   4.3,
                                0, 0,   4.3, 4.3, 4.3, 0,   0,   4.3,
                                0, 4.3, 4.3, 4.3, 0,   4.3, 4.3, 4.3};
  for (size_t i = 0; i < result.size(); ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

TEST(Viewer, Rotation_x) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.XRotation(90);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0, 0, 0, -2, 0, 0, 0, 2, 0, -2, 2,
                                2, 0, 0, 2, -2, 0, 2, 0, 2, 2, -2, 2};
  for (size_t i = 0; i < result.size(); ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

TEST(Viewer, Rotation_y) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.YRotation(90);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0, 0,  2, 0, 0,  0, 2, 0,  2, 2, 0,
                                0, 0, -2, 2, 0, -2, 0, 2, -2, 2, 2, -2};
  for (size_t i = 0; i < result.size(); ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}

TEST(Viewer, Rotation_z) {
  s21::VModel model;
  model.ReadModelFile("tests/models/cube.obj");
  model.ZRotation(90);
  std::vector<double> result = model.GetVertices();
  std::vector<double> reference{0, 0, 0, 0, 0, 2, -2, 0, 0, -2, 0, 2,
                                0, 2, 0, 0, 2, 2, -2, 2, 0, -2, 2, 2};
  for (size_t i = 0; i < result.size(); ++i) {
    ASSERT_NEAR(result[i], reference[i], kAcc);
  }
}
TEST(Viewer, Crash_test) {
  s21::VModel model;
  std::vector<std::string> address_list{//
                                        "tests/models/12140_Skull_v3_L2.obj",
                                        // "tests/models/bat.obj"
                                        // ,
                                        "tests/models/dragon.obj"};
  for (size_t i = 0; i < address_list.size(); ++i) {
    model.ReadModelFile(address_list[i]);
    model.Inscribe();
    std::vector<double> result = model.GetVertices();
    std::vector<double> reference(result);
    for (size_t a = 0; a < 10; ++a) {
      model.Scaling(0.5);
    }
    for (size_t b = 0; b < 100; ++b) {
      model.XShift(1);
      model.YShift(1);
      model.ZShift(1);
    }
    for (size_t c = 0; c < 100; ++c) {
      model.XShift(-1);
      model.YShift(-1);
      model.ZShift(-1);
    }
    for (size_t d = 0; d < 360; ++d) {
      model.XRotation(1);
    }
    for (size_t e = 0; e < 360; ++e) {
      model.YRotation(1);
    }
    for (size_t f = 0; f < 360; ++f) {
      model.ZRotation(1);
    }
    model.Inscribe();
    for (size_t g = 0; g < result.size() - 1; ++g) {
      ASSERT_NEAR(result[i], reference[i], kAcc);
    }
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
