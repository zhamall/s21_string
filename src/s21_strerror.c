#include "s21_string.h"

char *s21_strerror(int errnum) {
  static char *err[] = S21_ERROR;
  static char resnum[70] = {0};
  int max = sizeof(err) / sizeof(err[0]) - 1;

  if (errnum >= 0 && errnum <= max) {
    s21_strncpy(resnum, err[errnum], sizeof(resnum) - 1);
    resnum[sizeof(resnum) - 1] = '\0';
  } else {
    snprintf(resnum, sizeof(resnum), "Unknown error %d", errnum);
  }
  return resnum;
}