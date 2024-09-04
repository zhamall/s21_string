#include "s21_string.h"

/**
 * Функция s21_strtok предназначена для разбиения строки на токены
 * Функция разбивает строку str на ряд токенов, разделенных символами из delim.
 * При первом вызове str указывает на строку для разбиения, а при последующих
 * вызовах для той же строки str должен быть S21_NULL. Функция модифицирует
 * исходную строку, заменяя разделители на '\0'. Состояние разбора сохраняется
 * между вызовами в статической переменной. Если delim - пустая строка, функция
 * возвращает указатель на начало str
 * @param str указатель на строку для разбиения. При первом вызове содержит
 * исходную строку, при последующих вызовах должен быть S21_NULL
 * @param delim указатель на строку, содержащую набор символов-разделителей.
 * const означает, что эта строка не будет изменена функцией
 * @return указатель на начало очередного выделенного токена, или S21_NULL,
 * если больше токенов не найдено
 */
char *s21_strtok(char *str, const char *delim) {
  static char *last_token = S21_NULL;

  if (str == S21_NULL) {
    str = last_token;
  }

  if (str == S21_NULL) {
    return S21_NULL;
  }

  // Пропускаем начальные разделители
  while (*str && s21_strchr(delim, *str)) {
    str++;
  }

  if (*str == '\0') {
    last_token = S21_NULL;
    return S21_NULL;
  }

  char *token_start = str;

  // Ищем конец токена
  while (*str) {
    if (s21_strchr(delim, *str)) {
      *str = '\0';
      last_token = str + 1;
      return token_start;
    }
    str++;
  }

  last_token = S21_NULL;
  return token_start;
}