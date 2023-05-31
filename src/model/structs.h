#ifndef STRUCTS_H_
#define STRUCTS_H_

/**
 * @brief Структура матрицы для хранения коррдинат вершин.
 *
 */
typedef struct matrix_t {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/**
 * @brief Структура хранения данных из файла для построения модели.
 *
 */
typedef struct obj_data {
  char *name_file;
  int number_of_vertex;
  int number_of_facetes;
  int number_of_edges;
  matrix_t matrix_3d;
  int *edges;
} obj_data;

#endif  // STRUCTS_H_
