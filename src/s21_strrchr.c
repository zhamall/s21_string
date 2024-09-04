#include "s21_string.h"

/**
 * Функция s21_strrchr ищет последнее вхождение символа c в строке str.
 * Она возвращает указатель на последнее вхождение символа c в строке str, или
 * S21_NULL, если символ не найден.
 * @param str указатель на строку для поиска
 * @param c целочисленное представление символа для поиска
 */
char *s21_strrchr(const char *str, int c) {
  const char *last = S21_NULL;

  while (*str != '\0') {
    if (*str == (char)c) {
      last = str;
    }
    str++;
  }

  if (c == '\0') {
    return (char *)str;
  }

  return (char *)last;
}