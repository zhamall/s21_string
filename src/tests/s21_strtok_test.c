#include "s21_string_tests.h"

START_TEST(test_s21_strtok_fn) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  const char *delim = " ,!";

  char *token1 = s21_strtok(str1, delim);
  char *token2 = strtok(str2, delim);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(S21_NULL, delim);
    token2 = strtok(S21_NULL, delim);
  }
  ck_assert_ptr_eq(token1, token2);

  // Additional tests
  char str3[] = "abc,def,ghi";
  char str4[] = "abc,def,ghi";
  const char *delim2 = ",";

  token1 = s21_strtok(str3, delim2);
  token2 = strtok(str4, delim2);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(S21_NULL, delim2);
    token2 = strtok(S21_NULL, delim2);
  }
  ck_assert_ptr_eq(token1, token2);

  char str5[] = "abc,,def,,ghi";
  char str6[] = "abc,,def,,ghi";
  const char *delim3 = ",";

  token1 = s21_strtok(str5, delim3);
  token2 = strtok(str6, delim3);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(S21_NULL, delim3);
    token2 = strtok(S21_NULL, delim3);
  }
  ck_assert_ptr_eq(token1, token2);

  // Edge cases
  char str7[] = "";
  char str8[] = "";
  const char *delim4 = ",";

  token1 = s21_strtok(str7, delim4);
  token2 = strtok(str8, delim4);
  ck_assert_ptr_eq(token1, token2);

  char str9[] = "a,b,c";
  char str10[] = "a,b,c";
  const char *delim5 = ",";

  token1 = s21_strtok(str9, delim5);
  token2 = strtok(str10, delim5);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(S21_NULL, delim5);
    token2 = strtok(S21_NULL, delim5);
  }
  ck_assert_ptr_eq(token1, token2);

  char str11[] = "a,,b,,c";
  char str12[] = "a,,b,,c";
  const char *delim6 = ",";

  token1 = s21_strtok(str11, delim6);
  token2 = strtok(str12, delim6);
  while (token1 != S21_NULL && token2 != S21_NULL) {
    ck_assert_str_eq(token1, token2);
    token1 = s21_strtok(S21_NULL, delim6);
    token2 = strtok(S21_NULL, delim6);
  }
  ck_assert_ptr_eq(token1, token2);
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strtok");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strtok_fn);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_strtok_test(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_strtok_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}