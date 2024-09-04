#include "s21_string.h"

/**
 * Функция memset заполняет первые n байт области памяти, на которую указывает
 * аргумент destination, символом, код которого указывается аргументом c.
 *
 * @param destination указатель на заполняемый массив
 * @param c код символа для заполнения
 * @param n размер заполняемой части массива в байтах
 *
 * @return Функция возвращает указатель на заполняемый массив.
 */
void *s21_memset(void *destination, int c, s21_size_t n) {
  if (destination) {
    unsigned char *start = destination;
    unsigned char _c = c;

    for (s21_size_t i = 0; i < n; i++) {
      *start++ = _c;
    }
  }

  return destination;
}