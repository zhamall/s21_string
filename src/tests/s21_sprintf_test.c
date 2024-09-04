#include "s21_string_tests.h"

// Тест на форматирование отрицательного числа с флагом '+'
START_TEST(test_s21_sprintf_hh) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%hhd", 10);
  sprintf(expected, "%hhd", 10);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование отрицательного числа с флагом '+'
START_TEST(test_s21_sprintf_width_star) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%*d", 6, 10);
  sprintf(expected, "%*d", 6, 10);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование отрицательного числа с флагом '+'
START_TEST(test_s21_sprintf) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "hello");
  sprintf(expected, "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование отрицательного числа с флагом '+'
START_TEST(test_s21_sprintf_d_flag_plus_minus) {
  int num = -423;
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%+d", num);
  sprintf(expected, "%+d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование отрицательного числа с флагом '+'
START_TEST(test_s21_sprintf_f_flag_plus_minus) {
  float num = -42.10;
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%+f", num);
  sprintf(expected, "%+f", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на процент
START_TEST(test_s21_sprintf_percent) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%%");
  sprintf(expected, "%%");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование целого числа с флагом '+'
START_TEST(test_s21_sprintf_d_flag_plus) {
  int num = 42;
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%+d", num);
  sprintf(expected, "%+d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование целого числа с флагом ' ' (пробел)
START_TEST(test_s21_sprintf_d_flag_space) {
  int num = 42;
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "% d", num);
  sprintf(expected, "% d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование целого числа с шириной
START_TEST(test_s21_sprintf_d_width) {
  int num = 42;
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%5d", num);
  sprintf(expected, "%5d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование целого числа с точностью
START_TEST(test_s21_sprintf_d_precision) {
  int num = 42;
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%.3d", num);
  sprintf(expected, "%.3d", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование целого числа с длиной 'h'
START_TEST(test_s21_sprintf_d_length_h) {
  char num = 42;
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%hd", num);
  sprintf(expected, "%hd", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование целого числа с длиной 'l'
START_TEST(test_s21_sprintf_d_length_l) {
  long num = 42;
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%ld", num);
  sprintf(expected, "%ld", num);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование символа
START_TEST(test_s21_sprintf_c) {
  char symbol = 'a';
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%c", symbol);
  sprintf(expected, "%c", symbol);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование строки
START_TEST(test_s21_sprintf_s) {
  char str[] = "Hello, world!";
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%s", str);
  sprintf(expected, "%s", str);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест на форматирование без аргументов
START_TEST(test_s21_sprintf_no_args) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "Hello, world!");
  sprintf(expected, "Hello, world!");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования числа с плавающей точкой в виде десятичной
// дроби
START_TEST(test_s21_sprintf_f_1) {
  char buffer[100] = {0};
  char expected[100] = {0};

  double arg = 3.14159265;
  s21_sprintf(buffer, "%f", arg);
  sprintf(expected, "%f", arg);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования числа с плавающей точкой в виде десятичной
// дроби с точностью
START_TEST(test_s21_sprintf_f_2) {
  char buffer[100] = {0};
  char expected[100] = {0};

  double arg = 3.14159265;
  s21_sprintf(buffer, "%.4f", arg);
  sprintf(expected, "%.4f", arg);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования числа с плавающей точкой с флагом '+'
START_TEST(test_s21_sprintf_f_3) {
  char buffer[100] = {0};
  char expected[100] = {0};

  double arg = 3.14159265;
  s21_sprintf(buffer, "%+f", arg);
  sprintf(expected, "%+f", arg);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования числа с плавающей точкой с флагом ' '
START_TEST(test_s21_sprintf_f_4) {
  char buffer[100] = {0};
  char expected[100] = {0};

  double arg = 3.14159265;
  s21_sprintf(buffer, "% f", arg);
  sprintf(expected, "% f", arg);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования числа с плавающей точкой с шириной поля
START_TEST(test_s21_sprintf_f_5) {
  char buffer[100] = {0};
  char expected[100] = {0};

  double arg = 3.14159265;
  s21_sprintf(buffer, "%10f", arg);
  sprintf(expected, "%10f", arg);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования числа с плавающей точкой с шириной поля и
// точностью
START_TEST(test_s21_sprintf_f_6) {
  char buffer[100] = {0};
  char expected[100] = {0};

  double arg = 3.14159265;
  s21_sprintf(buffer, "%10.4f", arg);
  sprintf(expected, "%10.4f", arg);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования числа с плавающей точкой с шириной поля,
// точностью и флагом '-'
START_TEST(test_s21_sprintf_f_7) {
  char buffer[100] = {0};
  char expected[100] = {0};

  double arg = 3.14159265;
  s21_sprintf(buffer, "%-10.4f", arg);
  sprintf(expected, "%-10.4f", arg);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования символа без флага и ширины
START_TEST(test_s21_sprintf_c_1) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%c", 'a');
  sprintf(expected, "%c", 'a');

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования символа с шириной
START_TEST(test_s21_sprintf_c_4) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%5c", 'a');
  sprintf(expected, "%5c", 'a');

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования символа с флагом '-' и шириной
START_TEST(test_s21_sprintf_c_5) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%-5c", 'a');
  sprintf(expected, "%-5c", 'a');

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования строки без флага и ширины
START_TEST(test_s21_sprintf_s_1) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%s", "hello");
  sprintf(expected, "%s", "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования строки с шириной
START_TEST(test_s21_sprintf_s_2) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%10s", "hello");
  sprintf(expected, "%10s", "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования строки с шириной и флагом '-'
START_TEST(test_s21_sprintf_s_3) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%-10s", "hello");
  sprintf(expected, "%-10s", "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования строки с шириной и флагом ' '
START_TEST(test_s21_sprintf_s_5) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%10s", "hello");
  sprintf(expected, "%10s", "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования строки с шириной и флагом '+'
START_TEST(test_s21_sprintf_s_6) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%10s", "hello");
  sprintf(expected, "%10s", "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования строки с шириной и точностью
START_TEST(test_s21_sprintf_s_7) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%.3s", "hello");
  sprintf(expected, "%.3s", "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования строки с шириной, точностью и флагом '-'
START_TEST(test_s21_sprintf_s_8) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%-10.3s", "hello");
  sprintf(expected, "%-10.3s", "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования строки с шириной, точностью и флагом ' '
START_TEST(test_s21_sprintf_s_10) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%10.3s", "hello");
  sprintf(expected, "%10.3s", "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования строки с шириной, точностью и флагом '+'
START_TEST(test_s21_sprintf_s_11) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%10.3s", "hello");
  sprintf(expected, "%10.3s", "hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования NULL-строки
START_TEST(test_s21_sprintf_s_12) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%s", S21_NULL);
  sprintf(expected, "%s", "(null)");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования беззнакового целого числа без флагов и
// ширины
START_TEST(test_s21_sprintf_u_1) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%u", 123);
  sprintf(expected, "%u", 123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования беззнакового целого числа с флагом '-'
START_TEST(test_s21_sprintf_u_4) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%-10u", 123);
  sprintf(expected, "%-10u", 123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования беззнакового целого числа с шириной
START_TEST(test_s21_sprintf_u_6) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%10u", 123);
  sprintf(expected, "%10u", 123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования беззнакового целого числа с точностью
START_TEST(test_s21_sprintf_u_7) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%.3u", 123);
  sprintf(expected, "%.3u", 123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования беззнакового целого числа с шириной и
// точностью
START_TEST(test_s21_sprintf_u_8) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%10.3u", 123);
  sprintf(expected, "%10.3u", 123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования беззнакового целого числа с длиной 'h'
START_TEST(test_s21_sprintf_u_9) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%hu", (unsigned short)123);
  sprintf(expected, "%hu", (unsigned short)123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

// Тест для проверки форматирования беззнакового целого числа с длиной 'l'
START_TEST(test_s21_sprintf_u_10) {
  char buffer[100] = {0};
  char expected[100] = {0};

  s21_sprintf(buffer, "%lu", (unsigned long)123);
  sprintf(expected, "%lu", (unsigned long)123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *s = suite_create("s21_sprintf");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_s21_sprintf_d_flag_plus);
  tcase_add_test(tc_core, test_s21_sprintf_d_flag_space);
  tcase_add_test(tc_core, test_s21_sprintf_d_width);
  tcase_add_test(tc_core, test_s21_sprintf_d_precision);
  tcase_add_test(tc_core, test_s21_sprintf_d_length_h);
  tcase_add_test(tc_core, test_s21_sprintf_d_length_l);
  tcase_add_test(tc_core, test_s21_sprintf_c);
  tcase_add_test(tc_core, test_s21_sprintf_s);
  tcase_add_test(tc_core, test_s21_sprintf_no_args);

  tcase_add_test(tc_core, test_s21_sprintf_f_1);
  tcase_add_test(tc_core, test_s21_sprintf_f_2);
  tcase_add_test(tc_core, test_s21_sprintf_f_3);
  tcase_add_test(tc_core, test_s21_sprintf_f_4);
  tcase_add_test(tc_core, test_s21_sprintf_f_5);
  tcase_add_test(tc_core, test_s21_sprintf_f_6);
  tcase_add_test(tc_core, test_s21_sprintf_f_7);

  tcase_add_test(tc_core, test_s21_sprintf_c_1);
  tcase_add_test(tc_core, test_s21_sprintf_c_4);
  tcase_add_test(tc_core, test_s21_sprintf_c_5);

  tcase_add_test(tc_core, test_s21_sprintf_s_1);
  tcase_add_test(tc_core, test_s21_sprintf_s_2);
  tcase_add_test(tc_core, test_s21_sprintf_s_3);
  tcase_add_test(tc_core, test_s21_sprintf_s_5);
  tcase_add_test(tc_core, test_s21_sprintf_s_6);
  tcase_add_test(tc_core, test_s21_sprintf_s_7);
  tcase_add_test(tc_core, test_s21_sprintf_s_8);
  tcase_add_test(tc_core, test_s21_sprintf_s_10);
  tcase_add_test(tc_core, test_s21_sprintf_s_11);
  tcase_add_test(tc_core, test_s21_sprintf_s_12);

  tcase_add_test(tc_core, test_s21_sprintf_u_1);
  tcase_add_test(tc_core, test_s21_sprintf_u_4);
  tcase_add_test(tc_core, test_s21_sprintf_u_6);
  tcase_add_test(tc_core, test_s21_sprintf_u_7);
  tcase_add_test(tc_core, test_s21_sprintf_u_8);
  tcase_add_test(tc_core, test_s21_sprintf_u_9);
  tcase_add_test(tc_core, test_s21_sprintf_u_10);

  tcase_add_test(tc_core, test_s21_sprintf_percent);
  tcase_add_test(tc_core, test_s21_sprintf_f_flag_plus_minus);
  tcase_add_test(tc_core, test_s21_sprintf_d_flag_plus_minus);
  tcase_add_test(tc_core, test_s21_sprintf);
  tcase_add_test(tc_core, test_s21_sprintf_width_star);
  tcase_add_test(tc_core, test_s21_sprintf_hh);

  suite_add_tcase(s, tc_core);

  return s;
}

int s21_sprintf_test(void) {
  int number_failed;
  Suite *s = s21_sprintf_suite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}