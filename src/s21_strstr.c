#include "s21_string.h"

/**
 * Функция s21_strstr ищет первое вхождение всей строки needle (исключая
 * завершающий нулевой символ) в строке haystack. Символы регистрозависимы. Если
 * needle является пустой строкой, функция возвращает haystack
 *
 * @param haystack указатель на строку, в которой производится поиск.
 * @param needle указатель на подстроку, которую нужно найти.
 * @return указатель на первое вхождение подстроки needle в строке haystack,
 * или S21_NULL, если подстрока не найдена
 */
char *s21_strstr(const char *haystack, const char *needle) {
  if (!haystack || !needle) {
    return S21_NULL;
  }

  if (*needle == '\0') {
    return (char *)haystack;
  }

  s21_size_t needle_len = 0;
  while (needle[needle_len] != '\0') {
    needle_len++;
  }

  while (*haystack != '\0') {
    if (*haystack == *needle) {
      s21_size_t i = 0;
      while (haystack[i] == needle[i] && i < needle_len) {
        i++;
      }
      if (i == needle_len) {
        return (char *)haystack;
      }
    }
    haystack++;
  }

  return S21_NULL;
}