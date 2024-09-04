#include "s21_string.h"

char* s21_strchr(const char* str, int c) {
  int i = 0;
  char* ptr = (char*)str;

  if (str) {
    while (str[i] && str[i] != c) ++i;
    ptr = c == str[i] ? (char*)str + i : S21_NULL;
  }
  return ptr;
}