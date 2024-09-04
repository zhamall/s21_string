#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t len = 0;
  s21_size_t len2 = 0;
  char *temp = S21_NULL;

  if (trim_chars) {
    len2 = s21_strlen(trim_chars);
  }

  if (src) {
    len = s21_strlen(src);
    temp = calloc(len + 1, sizeof(char));
  }

  if (temp) {
    s21_strncpy(temp, src, len);

    if (len2 == 0 && temp[len - 1] == ' ') temp[len - 1] = '\0';
    if (len2 == 0 && temp[0] == ' ') temp[0] = '\0';

    for (s21_size_t i = 0; trim_chars[i]; i++) {
      if (temp[len - 1] == trim_chars[i]) temp[len - 1] = '\0';
      if (temp[0] == trim_chars[i]) temp[0] = '\0';
    }

    if (temp[0] == '\0' && len > 0) {
      for (s21_size_t i = 1; temp[i]; i++) {
        temp[i - 1] = temp[i];
        len = i;
      }

      temp[len] = '\0';
    }
  }

  return temp;
}