#include "s21_string_tests.h"

START_TEST(test_s21_strchr_fn) {
  const char *source = "Hello, world!";

  ck_assert_ptr_eq(s21_strchr(source, 'l'), strchr(source, 'l'));
  ck_assert_ptr_eq(s21_strchr(source, 'h'), strchr(source, 'h'));
  ck_assert_ptr_eq(s21_strchr(source, 'z'), strchr(source, 'z'));
  ck_assert_ptr_eq(s21_strchr(source, ' '), strchr(source, ' '));
}
END_TEST

int s21_strchr_test() {
  Suite *suite = suite_create("s21_strchr");
  TCase *tcase = tcase_create("s21_strchr");

  tcase_add_test(tcase, test_s21_strchr_fn);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}