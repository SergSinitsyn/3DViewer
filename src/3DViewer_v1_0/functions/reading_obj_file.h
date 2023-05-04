#ifndef READING_OBJ_FILE_H_
#define READING_OBJ_FILE_H_

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

/**
 * @brief Функция записи данных из файла .obj в стуктуру с данными модели
 *
 * @param data Указатель на структуру хранения данных модели.
 * @param file_obj Строка содержащая имя файла
 * @return int Возвращает 1 в случае удачного
 * прочтения файла; либо 0 - в слуае ошибки.
 */
int obj_in_data(obj_data *data, char *file_obj);

/**
 * @brief Функция очистки структуры с данными модели
 *
 * @param data Указатель на структуру хранения данных модели.
 */
void remove_data(obj_data *data);

/**
 * @brief Инициализация структуры модели
 *
 * @param data Указатель на структуру модели
 */
void init_data(obj_data *data);

#endif  // READING_OBJ_FILE_H_
