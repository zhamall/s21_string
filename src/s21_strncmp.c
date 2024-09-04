#include "s21_string.h"

/**
 * Функция сравнивает первые num символов строки string1 с первыми num символами
 * строки string2. Эта функция начинает сравнивать первый символ каждой строки.
 * Если они равны, strncmp продолжает сравнивать  следующие пары символов, пока
 * не будут найдены различные символы или пока не будет достигнут конец строки.
 *
 * @param string1 первая сравниваемая строка.
 * @param string2 вторая сравниваемая строка.
 * @param num максимальное количество сравниваемых символов.
 *
 * @return Возвращает неоднозначное значение, информирующее о результате
 * сравнения строк: Нулевое значение указывает на то, что содержимое обоих
 * блоков памяти равны. Значение большее нуля указывает на то, что строка
 * string1 больше строки string2, значение меньше нуля свидетельствует об
 * обратном.
 */
int s21_strncmp(const char *string1, const char *string2, s21_size_t num) {
  int result = 0;
  int char1 = 0;
  int char2 = 0;

  if (string1 && string2) {
    for (s21_size_t i = 0; i < num && result == 0; i++) {
      char1 = ((unsigned char *)string1)[i];
      char2 = ((unsigned char *)string2)[i];

      result += char1 - char2;
    }
  }

  return result;
}