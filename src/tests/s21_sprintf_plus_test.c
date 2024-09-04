#include "s21_string_tests.h"

START_TEST(test_s21_sprintf_fn) {
  char str1[40] = {0};
  char str2[40] = {0};

  s21_sprintf(str1, "%-10c%d%f%s%utest%%", '$', 1050, 12.12, "hello", 42);
  sprintf(str2, "%-10c%d%f%s%utest%%", '$', 1050, 12.12, "hello", 42);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_g) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "%g", 123.456);
  sprintf(buffer2, "%g", 123.456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%g", 0.000123456);
  sprintf(buffer2, "%g", 0.000123456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%g", 123456.0);
  sprintf(buffer2, "%g", 123456.0);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%g", 0.0);
  sprintf(buffer2, "%g", 0.0);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%g", -123.456);
  sprintf(buffer2, "%g", -123.456);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_G) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "%G", 123.456);
  sprintf(buffer2, "%G", 123.456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%G", 0.000123456);
  sprintf(buffer2, "%G", 0.000123456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%G", 123456.0);
  sprintf(buffer2, "%G", 123456.0);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%G", 0.0);
  sprintf(buffer2, "%G", 0.0);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%G", -123.456);
  sprintf(buffer2, "%G", -123.456);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_e) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "%e", 123.456);
  sprintf(buffer2, "%e", 123.456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%e", -123.456);
  sprintf(buffer2, "%e", -123.456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%e", 0.00123456);
  sprintf(buffer2, "%e", 0.00123456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%e", 0.0);
  sprintf(buffer2, "%e", 0.0);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%e", 1.23456e-10);
  sprintf(buffer2, "%e", 1.23456e-10);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%e", 1.23456e+10);
  sprintf(buffer2, "%e", 1.23456e+10);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_E) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  s21_sprintf(buffer1, "%E", 123.456);
  sprintf(buffer2, "%E", 123.456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%E", -123.456);
  sprintf(buffer2, "%E", -123.456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%E", 0.00123456);
  sprintf(buffer2, "%E", 0.00123456);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%E", 0.0);
  sprintf(buffer2, "%E", 0.0);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%E", 1.23456e-10);
  sprintf(buffer2, "%E", 1.23456e-10);
  ck_assert_str_eq(buffer1, buffer2);

  s21_sprintf(buffer1, "%E", 1.23456e+10);
  sprintf(buffer2, "%E", 1.23456e+10);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_x) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  // Test case 1: Simple number
  s21_sprintf(buffer1, "%x", 123);
  sprintf(buffer2, "%x", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 2: Zero
  s21_sprintf(buffer1, "%x", 0);
  sprintf(buffer2, "%x", 0);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 3: Large number
  s21_sprintf(buffer1, "%x", 4294967295U);
  sprintf(buffer2, "%x", 4294967295U);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 4: Number with width
  s21_sprintf(buffer1, "%10x", 123);
  sprintf(buffer2, "%10x", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 5: Number with zero padding
  s21_sprintf(buffer1, "%010x", 123);
  sprintf(buffer2, "%010x", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 6: Number with left-justified
  s21_sprintf(buffer1, "%-10x", 123);
  sprintf(buffer2, "%-10x", 123);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_X) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  // Test case 1: Simple number
  s21_sprintf(buffer1, "%X", 123);
  sprintf(buffer2, "%X", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 2: Zero
  s21_sprintf(buffer1, "%X", 0);
  sprintf(buffer2, "%X", 0);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 3: Large number
  s21_sprintf(buffer1, "%X", 4294967295U);
  sprintf(buffer2, "%X", 4294967295U);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 4: Number with width
  s21_sprintf(buffer1, "%10X", 123);
  sprintf(buffer2, "%10X", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 5: Number with zero padding
  s21_sprintf(buffer1, "%010X", 123);
  sprintf(buffer2, "%010X", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Test case 6: Number with left-justified
  s21_sprintf(buffer1, "%-10X", 123);
  sprintf(buffer2, "%-10X", 123);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_o) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  // Тест 1: Простое число
  s21_sprintf(buffer1, "%o", 123);
  sprintf(buffer2, "%o", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 2: Ноль
  s21_sprintf(buffer1, "%o", 0);
  sprintf(buffer2, "%o", 0);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 3: Большое число
  s21_sprintf(buffer1, "%o", 4294967295U);
  sprintf(buffer2, "%o", 4294967295U);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 4: Число с заданной шириной
  s21_sprintf(buffer1, "%10o", 123);
  sprintf(buffer2, "%10o", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 5: Число с заполнением нулями
  s21_sprintf(buffer1, "%010o", 123);
  sprintf(buffer2, "%010o", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 6: Число с выравниванием по левому краю
  s21_sprintf(buffer1, "%-10o", 123);
  sprintf(buffer2, "%-10o", 123);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 7: Ноль с заданной шириной
  s21_sprintf(buffer1, "%5o", 0);
  sprintf(buffer2, "%5o", 0);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 8: Ноль с заполнением нулями
  s21_sprintf(buffer1, "%05o", 0);
  sprintf(buffer2, "%05o", 0);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 9: Ноль с выравниванием по левому краю
  s21_sprintf(buffer1, "%-5o", 0);
  sprintf(buffer2, "%-5o", 0);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 10: Маленькое число
  s21_sprintf(buffer1, "%o", 7);
  sprintf(buffer2, "%o", 7);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 11: Несколько восьмеричных чисел
  s21_sprintf(buffer1, "%o %o %o", 7, 8, 9);
  sprintf(buffer2, "%o %o %o", 7, 8, 9);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 12: Восьмеричное число с другими спецификаторами
  s21_sprintf(buffer1, "Восьмеричное %o Десятичное %d", 123, 123);
  sprintf(buffer2, "Восьмеричное %o Десятичное %d", 123, 123);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_s21_sprintf_p) {
  char buffer1[100] = {0};
  char buffer2[100] = {0};

  // Тест 1: Нулевой указатель
  char *null_ptr = S21_NULL;
  s21_sprintf(buffer1, "%p", null_ptr);
  sprintf(buffer2, "%p", null_ptr);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 2: Ненулевой указатель
  int value = 42;
  int *ptr = &value;
  s21_sprintf(buffer1, "%p", ptr);
  sprintf(buffer2, "%p", ptr);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 3: Указатель на массив
  int arr[] = {1, 2, 3};
  s21_sprintf(buffer1, "%p", arr);
  sprintf(buffer2, "%p", arr);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 4: Указатель на строку
  char *str = "Hello, world!";
  s21_sprintf(buffer1, "%p", str);
  sprintf(buffer2, "%p", str);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 5: Указатель на функцию
  void (*func_ptr)(void) = S21_NULL;
  s21_sprintf(buffer1, "%p", func_ptr);
  sprintf(buffer2, "%p", func_ptr);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 6: Указатель с дополнительным текстом
  s21_sprintf(buffer1, "Адрес: %p", ptr);
  sprintf(buffer2, "Адрес: %p", ptr);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 7: Несколько указателей в одной строке
  s21_sprintf(buffer1, "%p %p %p", null_ptr, ptr, arr);
  sprintf(buffer2, "%p %p %p", null_ptr, ptr, arr);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 8: Указатель с шириной поля
  s21_sprintf(buffer1, "%20p", ptr);
  sprintf(buffer2, "%20p", ptr);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 9: Указатель с выравниванием по левому краю
  s21_sprintf(buffer1, "%-20p", ptr);
  sprintf(buffer2, "%-20p", ptr);
  ck_assert_str_eq(buffer1, buffer2);

  // Тест 10: Указатель на указатель
  int **ptr_to_ptr = &ptr;
  s21_sprintf(buffer1, "%p", ptr_to_ptr);
  sprintf(buffer2, "%p", ptr_to_ptr);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

Suite *s21_sprintf_plus_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_string_plus");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_sprintf_fn);

  tcase_add_test(tc_core, test_s21_sprintf_g);
  tcase_add_test(tc_core, test_s21_sprintf_G);
  tcase_add_test(tc_core, test_s21_sprintf_e);
  tcase_add_test(tc_core, test_s21_sprintf_E);
  tcase_add_test(tc_core, test_s21_sprintf_x);
  tcase_add_test(tc_core, test_s21_sprintf_X);
  tcase_add_test(tc_core, test_s21_sprintf_o);
  tcase_add_test(tc_core, test_s21_sprintf_p);
  suite_add_tcase(s, tc_core);

  return s;
}

int s21_sprintf_plus_test() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_sprintf_plus_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}