#include "s21_string_tests.h"

int main(void) {
  s21_memcmp_test();
  s21_strncat_test();
  s21_strncpy_test();
  s21_to_upper_test();
  s21_to_lower_test();
  s21_insert_test();
  s21_trim_test();
  s21_strlen_test();
  s21_strpbrk_test();
  s21_strerror_test();
  s21_memcpy_test();
  s21_strchr_test();
  s21_strcspn_test();
  s21_strncmp_test();
  s21_memset_test();
  s21_memchr_test();
  s21_strrchr_test();
  s21_strstr_test();
  s21_strtok_test();
  s21_sprintf_test();
  s21_sprintf_plus_test();

  return 0;
}