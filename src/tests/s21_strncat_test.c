#include "s21_string_tests.h"

START_TEST(s21_strncat_test_eq) {
  char str[30] = "Hello, world!";
  char str2[30] = "Hello, world!";
  char str3[13] = "Привет";

  ck_assert_str_eq(s21_strncat(str, str3, 13), strncat(str2, str3, 13));
}
END_TEST

int s21_strncat_test() {
  Suite *suite = suite_create("s21_strncat");
  TCase *tcase = tcase_create("s21_strncat");

  tcase_add_test(tcase, s21_strncat_test_eq);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}