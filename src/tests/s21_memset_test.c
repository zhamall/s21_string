#include "s21_string_tests.h"

START_TEST(s21_memset_test_norm) {
  char str1[14] = "Hello, world!";
  char str2[14] = "Hello, world!";

  s21_memset(str1, 'o', 7);
  memset(str2, 'o', 7);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_memset_test_null) {
  void *str = S21_NULL;
  void *expected = S21_NULL;

  ck_assert_ptr_eq(s21_memset(str, 'o', 7), expected);
}
END_TEST

int s21_memset_test(void) {
  Suite *suite = suite_create("s21_memset");
  TCase *tcase = tcase_create("s21_memset");

  tcase_add_test(tcase, s21_memset_test_norm);
  tcase_add_test(tcase, s21_memset_test_null);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}