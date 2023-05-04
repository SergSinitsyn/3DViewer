#include "reading_obj_file.h"

#define N 500

/**
 * @brief Функция подсчета количества вершин в фасете (грани).
 *
 * @param str Строка с вершинами фасета (грани) - f...
 * @return int Количество вершин в фасете (грани).
 */
int num_vertex_in_faset(char *str);

/**
 * @brief Функция сбора статистики файла .obj. Считает количество вершин, граней
 * и количество фасетов модели.
 *
 * @param file Имя файла .obj.
 * @param data Указатель на структуру хранения данных модели.
 * @return int Возвращает количество вершин модели в случае удачного
 * прочтения файла; либо 0 - в слуае ошибки.
 */
int obj_statistics(FILE *file, obj_data *data);

/**
 * @brief Функция записи вершин, граней и фасетов в структуру:
 *
 * @param file Имя файла .obj.
 * @param data Указатель на структуру хранения данных модели.
 * @return int Возвращает количество вершин модели в случае удачного
 * прочтения файла; либо 0 - в слуае ошибки.
 */
int parsing_obj(FILE *file, obj_data *data);
/**
 * @brief Инициализация матрицы координат
 *
 * @param rows Количество точек в модели (строк матрицы)
 * @param columns Количество координат точки в модели (столбцов матрицы)
 * @param result Указатель на инициализрованную матрицу
 */
void s21_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief Очищает матрицу
 *
 * @param A Указатель на матрицу
 */
void s21_remove_matrix(matrix_t *A);

/**
 * @brief Ракировка значений параметров
 *
 * @param x Значение 1-го параметра
 * @param y Значение 2-го параметра
 */
void castling(int *x, int *y);

/**
 * @brief Сортировка массива

 *
 * @param s_arr Указатель на массив
 * @param first Начальный индекс
 * @param last Конечный индекс
 */
void qs(int *s_arr, int first, int last);

/**
 * @brief Уникализаци ребер в модели
 *
 * @param data Указател на структуру модели
 */
void uniqueization_edges(obj_data *data);

/**
 * @brief Сортировка ребер в модели
 *
 * @param data
 */
void sort_edges(obj_data *data);

void castling(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void qs(int *s_arr, int first, int last) {
  if (first < last) {
    int left = (int)first, right = (int)last,
        middle = s_arr[(left / 2 + right / 2) / 2 * 2],
        middle_1 = s_arr[(left / 2 + right / 2) / 2 * 2 + 1];
    do {
      while (s_arr[left] > middle ||
             (s_arr[left] == middle && s_arr[left + 1] > middle_1))
        left += 2;
      while (s_arr[right] < middle ||
             (s_arr[right] == middle && s_arr[right + 1] < middle_1))
        right -= 2;
      if (left <= right) {
        castling(&s_arr[left], &s_arr[right]);
        castling(&s_arr[left + 1], &s_arr[right + 1]);
        left += 2;
        right -= 2;
      }
    } while (left <= right);
    qs(s_arr, first, right);
    qs(s_arr, left, last);
  }
}

void sort_edges(obj_data *data) {
  qs(data->edges, 0, (data->number_of_edges - 1) * 2);
}

void uniqueization_edges(obj_data *data) {
  for (int i = 0; i < data->number_of_edges * 2; i += 2) {
    if (data->edges[i] < data->edges[i + 1])
      castling(&data->edges[i], &data->edges[i + 1]);
  }
  sort_edges(data);
  for (int i = 0; i < (int)data->number_of_edges * 2 - 2; i += 2) {
    if (data->edges[i] == data->edges[i + 2] &&
        data->edges[i + 1] == data->edges[i + 3]) {
      data->edges[i] = data->edges[i + 1] = 0;
    }
  }
  sort_edges(data);
  int light = 0;
  int flag = data->edges[0];
  while (flag) {
    light += 1;
    flag = data->edges[light * 2];
  }
  data->number_of_edges = light;
  data->edges = realloc(data->edges, data->number_of_edges * 2 * sizeof(int));
}

int num_vertex_in_faset(char *str) {
  int res = 0;
  while (*str != '\0') {
    if (*str == ' ' && *(str + 1) >= '0' && *(str + 1) <= '9') res++;
    str++;
  }
  return res;
}

int obj_statistics(FILE *file, obj_data *data) {
  char string[N];
  data->number_of_vertex = 0;
  data->number_of_facetes = 0;
  data->number_of_edges = 0;
  while (!feof(file)) {
    char *flag = fgets(string, N, file);
    if (flag && *string == 'v' && *(string + 1) == ' ')
      data->number_of_vertex++;
    else if (flag && *string == 'f' && *(string + 1) == ' ') {
      data->number_of_facetes++;
      int n = num_vertex_in_faset(string);
      if (n <= 2)
        data->number_of_edges += n - 1;
      else
        data->number_of_edges += n;
    }
  }
  return data->number_of_vertex;
}

int parsing_obj(FILE *file, obj_data *data) {
  s21_create_matrix(data->number_of_vertex + 1, 3, &data->matrix_3d);
  data->edges = calloc(data->number_of_edges * 2, sizeof(int));
  int v = 0, f = 0, edg = 0, err_f = 1;
  while (!feof(file) && err_f) {
    char *string;
    char *string_temp;
    string_temp = calloc(N, sizeof(char));
    string = string_temp;
    char *str = fgets(string, N, file);
    if (str && *string == 'v' && *(string + 1) == ' ') {
      v++;
      string = string + 2;
      for (int i = 0; i <= 2; i++) {
        if (*string == ' ') string++;
        char *temp;
        data->matrix_3d.matrix[v][i] = strtod(string, &temp);
        string = temp;
      }
    } else if (str && *string == 'f' && *(string + 1) == ' ') {
      int n = num_vertex_in_faset(string);
      string = string + 2;
      for (int i = 0; i < n; i++) {
        if (*string == ' ') string++;
        char *temp;
        double x = strtod(string, &temp);
        if (x > data->number_of_vertex || x < 1) {
          err_f = 0;
          v = 0;
          break;
        }
        data->edges[edg++] = (int)x - 1;
        if (i > 0 && n > 2) {
          data->edges[edg++] = (int)x - 1;
          if (i == n - 1) {
            data->edges[edg] = data->edges[edg - n * 2 + 1];
            edg++;
          }
        }
        string = temp;
        while (*string != ' ' && *string != '\n') {
          string++;
        }
      }
      f++;
    }
    free(string_temp);
  }
  return v;
}

int obj_in_data(obj_data *data, char *file_obj) {
  int flag = 1;
  setlocale(LC_ALL, "en_US.UTF-8");  // борьба с передачей строки из ++ в СИ.
                                     // Чтобы заменить "," на "."
  FILE *file;
  file = fopen(file_obj, "r");
  if (file) {
    data->name_file = malloc(strlen(file_obj) + 1);
    strcpy(data->name_file, file_obj);
    flag = obj_statistics(file, data);
    fclose(file);
    if (flag) {
      file = fopen(file_obj, "r");
      flag = parsing_obj(file, data);
      fclose(file);
      if (flag) uniqueization_edges(data);
    }
  } else {
    flag = 0;
  }
  return flag;
}

void remove_data(obj_data *data) {
  s21_remove_matrix(&data->matrix_3d);
  if (data->edges != NULL) free(data->edges);
  if (data->name_file != NULL) free(data->name_file);
}

void s21_create_matrix(int rows, int columns, matrix_t *result) {
  result->rows = rows;
  result->columns = columns;
  double **matr = NULL;
  matr = (double **)malloc(rows * sizeof(double *) +
                           columns * rows * sizeof(double));
  matr[0] = (double *)(matr + rows);
  for (int i = 1; i < rows; i++) {
    matr[i] = matr[0] + i * columns;
  }
  result->matrix = matr;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
}

void init_data(obj_data *data) {
  data->name_file = NULL;
  data->number_of_edges = 0;
  data->number_of_facetes = 0;
  data->number_of_edges = 0;
  data->matrix_3d.matrix = NULL;
  data->edges = NULL;
}
