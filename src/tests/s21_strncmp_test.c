#include "s21_string_tests.h"

START_TEST(s21_strncmp_test_eq) {
  char str[14] = "Hello, world!";
  char str2[14] = "Hello, world!";

  ck_assert_int_eq(s21_strncmp(str, str2, 10), strncmp(str, str2, 10));
}
END_TEST

START_TEST(s21_strncmp_test_not_eq) {
  char str[14] = "Hello world!";
  char str2[14] = "Hello, world!";

  ck_assert_int_eq(s21_strncmp(str, str2, 10), strncmp(str, str2, 10));
}
END_TEST

START_TEST(s21_strncmp_test_null) {
  const char *str1 = S21_NULL;
  const char *str2 = "hello";
  int expected = 0;

  ck_assert_int_eq(s21_strncmp(str1, str2, 5), expected);
}
END_TEST

int s21_strncmp_test(void) {
  Suite *suite = suite_create("s21_strncmp");
  TCase *tcase = tcase_create("s21_strncmp");

  tcase_add_test(tcase, s21_strncmp_test_eq);
  tcase_add_test(tcase, s21_strncmp_test_not_eq);
  tcase_add_test(tcase, s21_strncmp_test_null);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}