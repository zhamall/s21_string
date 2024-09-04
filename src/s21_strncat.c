#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t destLength = 0;

  if (dest && src) {
    while (dest[destLength]) destLength++;

    for (s21_size_t i = 0; i < n && src[i]; i++) {
      dest[destLength + i] = src[i];
    }
  }

  return dest;
}