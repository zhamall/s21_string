#ifndef _S21_STRING_TESTS
#define _S21_STRING_TESTS

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

int s21_memcmp_test();
int s21_strncat_test();
int s21_strncpy_test();
int s21_to_upper_test();
int s21_to_lower_test();
int s21_insert_test();
int s21_trim_test();
int s21_strlen_test();
int s21_strpbrk_test();
int s21_strerror_test();
int s21_memcpy_test();
int s21_strchr_test();
int s21_strcspn_test();
int s21_strncmp_test();
int s21_sprintf_test();
int s21_memset_test();
int s21_memchr_test();
int s21_strrchr_test();
Suite *s21_strrchr_suite();
int s21_strstr_test();
Suite *s21_strstr_suite();
int s21_strtok_test();
Suite *s21_strtok_suite();
int s21_sprintf_plus_test();
Suite *s21_sprintf_plus_suite();

#endif