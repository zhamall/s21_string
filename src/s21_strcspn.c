#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t cnt = 0;
  const char *start_str2 = str2;
  int flag = 0;

  if (str1 && str2) {
    for (; *str1; str1++) {
      flag = 0;
      str2 = start_str2;
      for (; *str2; str2++) {
        if (*str1 == *str2) {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        cnt++;
      } else
        break;
    }
  }

  return cnt;
}