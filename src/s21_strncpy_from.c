#include "s21_string.h"

s21_size_t s21_strncpy_from(char *dest, s21_size_t n, const char *src) {
  for (int i = 0; dest[i] && src[i]; i++) {
    dest[n++] = src[i];
  }

  return n;
}