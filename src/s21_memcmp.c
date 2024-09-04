#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;

  if (str1 && str2) {
    for (s21_size_t i = 0; i < n && result == 0; i++) {
      int char1 = 0;
      int char2 = 0;
      char1 = ((unsigned char *)str1)[i];
      char2 = ((unsigned char *)str2)[i];

      result += char1 - char2;
    }
  }

  return result;
}