#include "s21_string_tests.h"

START_TEST(test_S_strerror) {
  for (int i = -1000; i < 150; i++) {
    char *got = s21_strerror(i);
    char *expected = strerror(i);
    ck_assert_str_eq(got, expected);
  }
}
END_TEST

int s21_strerror_test() {
  Suite *suite = suite_create("s21_strerror");
  TCase *tcase = tcase_create("s21_strerror");

  tcase_add_test(tcase, test_S_strerror);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}