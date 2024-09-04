#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t len = 0;
  s21_size_t len2 = 0;
  char *temp = S21_NULL;
  char *temp2 = S21_NULL;

  if (src && str) {
    len = s21_strlen(src);
    len2 = s21_strlen(str);
    temp = calloc(len + len2 + 2, sizeof(char));
    temp2 = calloc(len + 1, sizeof(char));
  }

  if (temp && temp2) {
    s21_strncpy(temp, src, len);
    s21_strncpy(temp2, src, len);
    len = s21_strncpy_from(temp, start_index, str);
    s21_strncpy_from(temp, len, &temp2[start_index]);
  } else if (temp) {
    free(temp);
  }

  if (temp2) {
    free(temp2);
  }

  return temp;
}