#include "s21_string_tests.h"

START_TEST(s21_memchr_test_normal) {
  char *str = "Hello, world!";

  ck_assert_ptr_eq(s21_memchr(str, 'o', 7), memchr(str, 'o', 7));
}
END_TEST

START_TEST(s21_memchr_test_null) {
  ck_assert_ptr_eq(s21_memchr(S21_NULL, 'o', 7), S21_NULL);
}
END_TEST

int s21_memchr_test(void) {
  Suite *suite = suite_create("s21_memchr");
  TCase *tcase = tcase_create("s21_memchr");

  tcase_add_test(tcase, s21_memchr_test_normal);
  tcase_add_test(tcase, s21_memchr_test_null);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}