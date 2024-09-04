#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *temp = S21_NULL;

  if (str) {
    temp = calloc(s21_strlen(str) + 1, sizeof(char));
  }

  if (temp) {
    for (int i = 0; *str && temp != S21_NULL; i++) {
      if (*str >= 65 && *str <= 90)
        temp[i] = *str + 32;
      else
        temp[i] = *str;

      str++;
    }
  }

  return temp;
}