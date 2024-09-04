#include "s21_string_tests.h"

START_TEST(test_S_strpbrk) {
  ck_assert_ptr_eq(s21_strpbrk("hello", "world"), &"hello"[2]);
  ck_assert_ptr_eq(s21_strpbrk("hello", "xyz"), S21_NULL);
  ck_assert_ptr_eq(s21_strpbrk("", "xyz"), S21_NULL);
  ck_assert_ptr_eq(s21_strpbrk("hello", ""), S21_NULL);
}
END_TEST

int s21_strpbrk_test() {
  Suite *suite = suite_create("s21_strpbrk");
  TCase *tcase = tcase_create("s21_strpbrk");

  tcase_add_test(tcase, test_S_strpbrk);
  suite_add_tcase(suite, tcase);

  SRunner *srunner = srunner_create(suite);

  srunner_run_all(srunner, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}