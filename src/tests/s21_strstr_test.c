#include "s21_string_tests.h"

START_TEST(test_s21_strstr_fn) {
  const char *haystack = "Hello, world!";
  const char *needle = "world";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
  ck_assert_ptr_eq(s21_strstr(haystack, "Hello"), strstr(haystack, "Hello"));
  ck_assert_ptr_eq(s21_strstr(haystack, "z"), strstr(haystack, "z"));
  ck_assert_ptr_eq(s21_strstr(haystack, ""), strstr(haystack, ""));

  // Additional tests
  ck_assert_ptr_eq(s21_strstr("", "a"), strstr("", "a"));
  ck_assert_ptr_eq(s21_strstr("abcabcabc", "a"), strstr("abcabcabc", "a"));
  ck_assert_ptr_eq(s21_strstr("abcabcabc", "b"), strstr("abcabcabc", "b"));
  ck_assert_ptr_eq(s21_strstr("abcabcabc", "c"), strstr("abcabcabc", "c"));
  ck_assert_ptr_eq(s21_strstr("abcabcabc", "abc"), strstr("abcabcabc", "abc"));
  ck_assert_ptr_eq(s21_strstr("abcabcabc", "abcd"),
                   strstr("abcabcabc", "abcd"));

  // Edge cases
  ck_assert_ptr_eq(s21_strstr("a", "a"), strstr("a", "a"));
  ck_assert_ptr_eq(s21_strstr("a", "b"), strstr("a", "b"));
  ck_assert_ptr_eq(s21_strstr("a\0b", "b"), strstr("a\0b", "b"));

  ck_assert_ptr_eq(s21_strstr(S21_NULL, "a"), S21_NULL);
  ck_assert_ptr_eq(s21_strstr("a", S21_NULL), S21_NULL);
  ck_assert_ptr_eq(s21_strstr(S21_NULL, S21_NULL), S21_NULL);
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strstr");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strstr_fn);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_strstr_test(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_strstr_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}