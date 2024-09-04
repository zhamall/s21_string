#include "s21_string_tests.h"

START_TEST(test_s21_strrchr_fn) {
  const char *str = "Hello, world!";
  int c = 'o';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  ck_assert_ptr_eq(s21_strrchr(str, 'z'), strrchr(str, 'z'));
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));

  // Additional tests
  ck_assert_ptr_eq(s21_strrchr("", 'a'), strrchr("", 'a'));
  ck_assert_ptr_eq(s21_strrchr("abcabcabc", 'a'), strrchr("abcabcabc", 'a'));
  ck_assert_ptr_eq(s21_strrchr("abcabcabc", 'b'), strrchr("abcabcabc", 'b'));
  ck_assert_ptr_eq(s21_strrchr("abcabcabc", 'c'), strrchr("abcabcabc", 'c'));

  // Edge cases
  ck_assert_ptr_eq(s21_strrchr("a", 'a'), strrchr("a", 'a'));
  ck_assert_ptr_eq(s21_strrchr("a", 'b'), strrchr("a", 'b'));
  ck_assert_ptr_eq(s21_strrchr("a\0b", 'b'), strrchr("a\0b", 'b'));
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strrchr");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strrchr_fn);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_strrchr_test(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_strrchr_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}