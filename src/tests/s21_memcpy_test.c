#include "s21_string_tests.h"

START_TEST(test_s21_memcpy_fn) {
  char *src = "Hello, world! C is great!";
  char dest[1000] = {0};

  ck_assert_ptr_eq(s21_memcpy(dest, src, 10), memcpy(dest, src, 10));
}
END_TEST

START_TEST(test_s21_memcpy_null) {
  char *src = "Test string";
  char dest[20] = {0};

  ck_assert_ptr_eq(s21_memcpy(NULL, src, 5), NULL);

  ck_assert_ptr_eq(s21_memcpy(dest, NULL, 5), NULL);

  ck_assert_ptr_eq(s21_memcpy(NULL, NULL, 5), NULL);
}
END_TEST

int s21_memcpy_test() {
  Suite *suite = suite_create("s21_memcpy");
  TCase *tcase = tcase_create("s21_memcpy");

  tcase_add_test(tcase, test_s21_memcpy_fn);
  tcase_add_test(tcase, test_s21_memcpy_null);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}