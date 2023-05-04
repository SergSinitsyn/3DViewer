#ifndef AFFINE_TRANSFORMATIONS_H_
#define AFFINE_TRANSFORMATIONS_H_

#include <math.h>
#include <stddef.h>
#include <stdlib.h>

#include "structs.h"

/**
 * @brief Центрует модель.
 *
 * @param data Указатель на структуру хранения данных модели.
 * @return double Возвращает коэффициент масштабировани модели при
 вписывании.
 */
double inscribe(obj_data *data);

/**
 * @brief Функци сдвига модели.
 *
 * @param data Указатель на структуру хранения данных модели.
 * @param shift_x Сдвиг модели по оси x.
 * @param shift_y Сдвиг модели по оси y.
 * @param shift_z Сдвиг модели по оси z.
 */
void model_shift(obj_data *data, double shift_x, double shift_y,
                 double shift_z);

/**
 * @brief Функция вращения модели по трем осям.
 *
 * @param data Указатель на структуру хранения данных модели.
 * @param rot_x Угол поворота по оси x (в градусах).
 * @param rot_y Угол поворота по оси y (в градусах).
 * @param rot_z Угол поворота по оси z (в градусах).
 */
void rotation_model(obj_data *data, double rot_x, double rot_y, double rot_z);

/**
 * @brief Функция масштабирования модели.
 *
 * @param data Указатель на структуру хранения данных модели.
 * @param scale Масштаб: <1 -уменьшение; >1 -увеличение.
 */
void model_scaling(obj_data *data, double scale);

#endif  // AFFINE_TRANSFORMATIONS_H_
