#include "s21_string_tests.h"

START_TEST(s21_insert_test_eq) {
  char str[14] = "Hello, world!";
  char str2[14] = "Hello, world!";
  char *result = s21_insert(str, str2, 6);

  if (result) {
    ck_assert_str_eq(result, "Hello,Hello, world! world!");
    free(result);
  }

  char *result2 = s21_insert(S21_NULL, str2, 6);

  ck_assert_ptr_null(result2);
}
END_TEST

int s21_insert_test() {
  Suite *suite = suite_create("s21_insert");
  TCase *tcase = tcase_create("s21_insert");

  tcase_add_test(tcase, s21_insert_test_eq);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}