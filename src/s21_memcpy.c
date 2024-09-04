#include "s21_string.h"

/**
 * Функция s21_memcpy предназначена для копирования блока памяти из одного места
 * в другое
 *
 * @param des указатель на область памяти, куда будут скопированы данные
 * @param src указатель на область памяти, откуда будут скопированы данные.
 * const означает, что эта область не будет изменена функцией
 * @param s21_size_t количество байтов для копирования
 * копирует n байтов из области памяти, на которую указывает src, в область
 * памяти, на которую указывает dest
 */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *start_dest = (char *)dest;
  char *d = (char *)dest;
  const char *s = (const char *)src;

  if (d == S21_NULL || s == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < n; i++) {
    *d = *s;  // Копируем данные
    d++;      // Перемещаем рабочий указатель
    s++;
  }

  return start_dest;
}