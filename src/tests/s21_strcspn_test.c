#include "s21_string_tests.h"

START_TEST(test_s21_strcspn_fn) {
  const char source[] = "Hello, world!";
  const char str2[] = "world";
  const char str3[] = "Hello";
  const char str4[] = "!";

  ck_assert_uint_eq(s21_strcspn(source, str2), strcspn(source, str2));
  ck_assert_uint_eq(s21_strcspn(source, str3), strcspn(source, str3));
  ck_assert_uint_eq(s21_strcspn(source, str4), strcspn(source, str4));
}
END_TEST

int s21_strcspn_test() {
  Suite *suite = suite_create("s21_strcspn");
  TCase *tcase = tcase_create("s21_strcspn");

  tcase_add_test(tcase, test_s21_strcspn_fn);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}