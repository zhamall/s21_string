#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t n = 0;
  if (str != S21_NULL) {
    while (str[n] != '\0') {
      n++;
    }
  }
  return n;
}