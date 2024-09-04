#include "s21_string_tests.h"

START_TEST(test_S_strlen) {
  ck_assert_int_eq(s21_strlen("helloiiiiii"), 11);
  ck_assert_int_eq(s21_strlen(""), 0);
  ck_assert_int_eq(s21_strlen(S21_NULL), 0);
}
END_TEST

int s21_strlen_test() {
  Suite *suite = suite_create("s21_strlen");
  TCase *tcase = tcase_create("s21_strlen");

  tcase_add_test(tcase, test_S_strlen);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}