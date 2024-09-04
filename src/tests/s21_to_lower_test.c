#include "s21_string_tests.h"

START_TEST(s21_to_lower_test_eq) {
  char str[14] = "Hello, world!";
  char *result = s21_to_lower(str);

  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

int s21_to_lower_test() {
  Suite *suite = suite_create("s21_to_lower");
  TCase *tcase = tcase_create("s21_to_lower");

  tcase_add_test(tcase, s21_to_lower_test_eq);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}