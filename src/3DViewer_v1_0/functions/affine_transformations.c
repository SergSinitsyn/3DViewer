#include "affine_transformations.h"

#include <stdio.h>

#define MY_PI 3.14159265358979323846

/**
 * @brief Функция поиска координат крайних точек модели (максимальное и
 * минималное значение координаты)
 *
 * @param data Указатель на структуру хранения данных модели.
 * @param x_min Минимальная координата модели по оси х.
 * @param x_max Максимальная координата модели по оси х.
 * @param y_min Минимальная координата модели по оси y.
 * @param y_max Максимальная координата модели по оси y.
 * @param z_min Минимальная координата модели по оси z.
 * @param z_max Максимальная координата модели по оси z.
 */
void max_min_coordinats(obj_data *data, double *x_min, double *x_max,
                        double *y_min, double *y_max, double *z_min,
                        double *z_max);

/**
 * @brief Функция вращения модели по оси х.
 *
 * @param data Указатель на структуру хранения данных модели.
 * @param rot_x Угол поворота по оси x (в градусах).
 */
void x_rotation(obj_data *data, double rot_x);

/**
 * @brief Функция вращения модели по оси y.
 *
 * @param data Указатель на структуру хранения данных модели.
 * @param rot_x Угол поворота по оси y (в градусах).
 */
void y_rotation(obj_data *data, double rot_y);

/**
 * @brief Функция вращения модели по оси z.
 *
 * @param data Указатель на структуру хранения данных модели.
 * @param rot_x Угол поворота по оси z (в градусах).
 */
void z_rotation(obj_data *data, double rot_z);

/**
 * @brief Функция перевода градусов в радианы.
 *
 * @param rotation Значение угла в градусах.
 * @return double Значение угла в радианах.
 */
double in_radian(double rotation);

double inscribe(obj_data *data) {
  double x_min, y_min, z_min;
  double x_max, y_max, z_max;
  max_min_coordinats(data, &x_min, &x_max, &y_min, &y_max, &z_min, &z_max);
  double max_size = x_max - x_min;
  if (max_size < y_max - y_min) max_size = y_max - y_min;
  if (max_size < z_max - z_min) max_size = z_max - z_min;
  model_shift(data, -(x_min + x_max) / 2, -(y_min + y_max) / 2,
              -(z_min + z_max) / 2);
  return 1.0 / max_size;
}

void model_shift(obj_data *data, double shift_x, double shift_y,
                 double shift_z) {
  for (int i = 1; i <= data->number_of_vertex; i++) {
    data->matrix_3d.matrix[i][0] += shift_x;
    data->matrix_3d.matrix[i][1] += shift_y;
    data->matrix_3d.matrix[i][2] += shift_z;
  }
}
void rotation_model(obj_data *data, double rot_x, double rot_y, double rot_z) {
  if (rot_x) x_rotation(data, rot_x);
  if (rot_y) y_rotation(data, rot_y);
  if (rot_z) z_rotation(data, rot_z);
}

void model_scaling(obj_data *data, double scale) {
  if (scale != 1 && scale != 0)
    for (int i = 1; i <= data->number_of_vertex; i++) {
      data->matrix_3d.matrix[i][0] *= scale;
      data->matrix_3d.matrix[i][1] *= scale;
      data->matrix_3d.matrix[i][2] *= scale;
    }
}

void max_min_coordinats(obj_data *data, double *x_min, double *x_max,
                        double *y_min, double *y_max, double *z_min,
                        double *z_max) {
  *x_min = data->matrix_3d.matrix[1][0];
  *x_max = data->matrix_3d.matrix[1][0];
  *y_min = data->matrix_3d.matrix[1][1];
  *y_max = data->matrix_3d.matrix[1][1];
  *z_min = data->matrix_3d.matrix[1][2];
  *z_max = data->matrix_3d.matrix[1][2];
  for (int i = 2; i <= data->number_of_vertex; i++) {
    if (data->matrix_3d.matrix[i][0] < *x_min)
      *x_min = data->matrix_3d.matrix[i][0];
    else if (data->matrix_3d.matrix[i][0] > *x_max)
      *x_max = data->matrix_3d.matrix[i][0];
    if (data->matrix_3d.matrix[i][1] < *y_min)
      *y_min = data->matrix_3d.matrix[i][1];
    else if (data->matrix_3d.matrix[i][1] > *y_max)
      *y_max = data->matrix_3d.matrix[i][1];
    if (data->matrix_3d.matrix[i][2] < *z_min)
      *z_min = data->matrix_3d.matrix[i][2];
    else if (data->matrix_3d.matrix[i][2] > *z_max)
      *z_max = data->matrix_3d.matrix[i][2];
  }
}

void x_rotation(obj_data *data, double rot_x) {
  double y, z;
  double sin_rot_x, cos_rot_x;
  sin_rot_x = sin(in_radian(rot_x));
  cos_rot_x = cos(in_radian(rot_x));
  for (int i = 1; i <= data->number_of_vertex; i++) {
    y = data->matrix_3d.matrix[i][1];
    z = data->matrix_3d.matrix[i][2];
    data->matrix_3d.matrix[i][1] = y * cos_rot_x + z * sin_rot_x;
    data->matrix_3d.matrix[i][2] = z * cos_rot_x - y * sin_rot_x;
  }
}

void y_rotation(obj_data *data, double rot_y) {
  double x, z;
  double sin_rot_y, cos_rot_y;
  sin_rot_y = sin(in_radian(rot_y));
  cos_rot_y = cos(in_radian(rot_y));
  for (int i = 1; i <= data->number_of_vertex; i++) {
    x = data->matrix_3d.matrix[i][0];
    z = data->matrix_3d.matrix[i][2];
    data->matrix_3d.matrix[i][0] = x * cos_rot_y + z * sin_rot_y;
    data->matrix_3d.matrix[i][2] = z * cos_rot_y - x * sin_rot_y;
  }
}

void z_rotation(obj_data *data, double rot_z) {
  double x, y;
  double sin_rot_z, cos_rot_z;
  sin_rot_z = sin(in_radian(rot_z));
  cos_rot_z = cos(in_radian(rot_z));
  for (int i = 1; i <= data->number_of_vertex; i++) {
    x = data->matrix_3d.matrix[i][0];
    y = data->matrix_3d.matrix[i][1];
    data->matrix_3d.matrix[i][1] = y * cos_rot_z + x * sin_rot_z;
    data->matrix_3d.matrix[i][0] = x * cos_rot_z - y * sin_rot_z;
  }
}

double in_radian(double angle_of_rotation) {
  double result;
  result = angle_of_rotation * MY_PI / 180;
  return result;
}
