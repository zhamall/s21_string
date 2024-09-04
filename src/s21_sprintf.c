#include "s21_string.h"

/**
 * Функция memset заполняет первые n байт области памяти, на которую указывает
 * аргумент destination, символом, код которого указывается аргументом c.
 *
 * @param str указатель на буфер, в который идет запись
 * @param format строка форматирования
 * @param ... дополнительные значения для спецификаторов из строки
 * форматирования
 *
 * @return  длина количества записанных символов плюс нулевой символ.
 */
int s21_sprintf(char *str, const char *format, ...) {
  int res = 0;
  char *_str = str;
  va_list args;

  va_start(args, format);

  while (*format) {
    if (*format == '%') {
      ++format;

      s21_format_spec_t format_spec = s21_get_format_spec(&format, args);

      _str = s21_set_specs(_str, format, args, format_spec);

      res++;
      format++;
    } else {
      *_str++ = *format;

      res++;
      format++;

      if (!*format) *_str = '\0';
    }
  }

  va_end(args);

  return res;
}

char *s21_sprintf_c(char *str, va_list args, s21_format_spec_t format_spec) {
  int arg = va_arg(args, int);
  int width = format_spec.width;
  int flag = format_spec.flag;

  if (width > 1 && flag != S21_MINUS) {
    s21_add_symbols_to_start(str, width, width - 1, ' ');
    str += width - 1;
  }

  *str++ = (char)arg;

  if (width > 1 && flag == S21_MINUS) {
    str = s21_memset(str, ' ', width - 1);
    str += width - 1;
  }

  *str = '\0';
  return str;
}

char *s21_sprintf_d(char *str, va_list args, s21_format_spec_t format_spec) {
  int arg = va_arg(args, int);

  // Делаем число положительным
  int sign = (arg < 0) ? -1 : 1;
  arg *= sign;

  s21_set_length(&arg, format_spec.length);

  char buffer[S21_MAX_DIGITS] = {0};
  char *buf_ptr = buffer + sizeof(buffer) - 1;
  *buf_ptr = '\0';

  do {
    *(--buf_ptr) = '0' + (arg % 10);
    arg /= 10;
  } while (arg != 0);

  if (sign < 0) {
    *str = '-';
    str++;
  } else {
    str = s21_set_flag(str, format_spec.flag);
  }

  str = s21_set_precision(str, buf_ptr, format_spec.prec);
  str = s21_set_width(str, buf_ptr, format_spec.width);

  while (*buf_ptr != '\0') {
    *str++ = *buf_ptr++;
  }

  return str;
}

char *s21_sprintf_f(char *str, double *arg_ptr, s21_format_spec_t format_spec,
                    int remove_trailing_zeros, int is_g_specifier) {
  double arg = *arg_ptr;
  char *_str = str;
  int sign = (arg < 0) ? -1 : 1;
  arg = fabs(arg);

  int precision = (format_spec.prec == -1) ? 6 : format_spec.prec;

  // Round the number
  double rounding = 0.5;
  for (int i = 0; i < precision; i++) {
    rounding /= 10.0;
  }
  arg += rounding;

  long long int_part = (long long)arg;
  double frac_part = arg - int_part;

  // Handle integer part
  char int_buf[32] = {0};
  int i = 0;
  if (int_part == 0) {
    int_buf[i++] = '0';
  } else {
    do {
      int_buf[i++] = int_part % 10 + '0';
      int_part /= 10;
    } while (int_part > 0);
  }

  if (sign < 0) {
    *_str++ = '-';
  } else {
    _str = s21_set_flag(_str, format_spec.flag);
  }

  for (int k = i - 1; k >= 0; k--) {
    *_str++ = int_buf[k];
  }

  // Handle fractional part
  if (precision > 0 || (format_spec.flag & S21_HASH)) {
    *_str++ = '.';
  }

  for (int j = 0; j < precision; j++) {
    frac_part *= 10.0;
    int digit = (int)frac_part;
    *_str++ = digit + '0';
    frac_part -= digit;
  }

  if (remove_trailing_zeros && !(format_spec.flag & S21_HASH) &&
      !is_g_specifier) {
    while (*(_str - 1) == '0' && _str > str + 1) {
      _str--;
    }
    if (*(_str - 1) == '.') {
      _str--;
    }
  }

  *_str = '\0';

  // Handle width
  int diff = format_spec.width - (_str - str);
  if (diff > 0) {
    if (format_spec.flag & S21_MINUS) {
      for (int i = 0; i < diff; i++) {
        *_str++ = ' ';
      }
      *_str = '\0';
    } else {
      char fill = (format_spec.flag & S21_ZERO) ? '0' : ' ';
      s21_add_symbols_to_start(str, format_spec.width, diff, fill);
      _str += diff;
    }
  }

  return _str;
}

char *s21_sprintf_s(char *str, va_list args, s21_format_spec_t format_spec) {
  char *arg = va_arg(args, char *);
  int width = format_spec.width;
  int flag = format_spec.flag;
  int precision = format_spec.prec;

  if (arg == S21_NULL) {
    arg = "(null)";
  }

  int arg_len = s21_strlen(arg);
  if (precision != -1 && precision < arg_len) {
    arg_len = precision;
  }

  if (width > arg_len && flag != S21_MINUS) {
    s21_add_symbols_to_start(str, width, width - arg_len, ' ');
    str += width - arg_len;
  }

  s21_strncpy(str, arg, arg_len);
  str += arg_len;

  if (width > arg_len && flag == S21_MINUS) {
    str = s21_memset(str, ' ', width - arg_len);
    str += width - arg_len;
  }

  *str = '\0';
  return str;
}

char *s21_sprintf_u(char *str, va_list args, s21_format_spec_t format_spec) {
  unsigned int arg = va_arg(args, unsigned int);
  char buffer[32] = {0};
  char *buf_ptr = buffer + sizeof(buffer) - 1;
  *buf_ptr = '\0';

  do {
    *(--buf_ptr) = '0' + (arg % 10);
    arg /= 10;
  } while (arg != 0);

  int len = buffer + sizeof(buffer) - buf_ptr - 1;
  int width = format_spec.width;
  int flag = format_spec.flag;

  if (width > len && flag != S21_MINUS) {
    s21_add_symbols_to_start(str, width, width - len, ' ');
    str += width - len;
  }

  while (*buf_ptr) {
    *str++ = *buf_ptr++;
  }

  if (width > len && flag == S21_MINUS) {
    str = s21_memset(str, ' ', width - len);
    str += width - len;
  }

  *str = '\0';
  return str;
}

char *s21_sprintf_percent(char *str) {
  *str++ = '%';
  return str;
}

char *s21_sprintf_gG(char *str, va_list args, char spec,
                     s21_format_spec_t format_spec) {
  double arg = va_arg(args, double);
  int precision = (format_spec.prec == -1) ? 6 : format_spec.prec;

  if (fabs(arg) < 1e-6) {  // Handle very small numbers
    *str++ = '0';
    *str = '\0';
  } else if (arg == 0.0) {
    *str++ = '0';
    if (precision > 0 && (format_spec.flag & S21_HASH)) {
      *str++ = '.';
      for (int i = 0; i < precision; i++) {
        *str++ = '0';
      }
    }
    *str = '\0';
  } else {
    double abs_arg = fabs(arg);
    int exponent = 0;

    while (abs_arg >= 10.0) {
      abs_arg /= 10.0;
      exponent++;
    }
    while (abs_arg < 1.0 && abs_arg != 0.0) {
      abs_arg *= 10.0;
      exponent--;
    }

    if (exponent < -4 || exponent >= precision) {
      // Use exponential notation
      format_spec.prec = precision - 1;
      va_list args_copy;
      va_copy(args_copy, args);
      va_arg(args_copy, double);  // Skip the argument we've already read
      str =
          s21_sprintf_eE(str, args_copy, spec == 'g' ? 'e' : 'E', format_spec);
      va_end(args_copy);
    } else {
      // Use fixed-point notation
      format_spec.prec = precision - (exponent + 1);
      if (format_spec.prec < 0) format_spec.prec = 0;
      int remove_trailing_zeros = (format_spec.flag & S21_HASH) ? 0 : 1;
      str = s21_sprintf_f(str, &arg, format_spec, remove_trailing_zeros, 1);
    }

    // Remove trailing zeros and decimal point if necessary
    if (!(format_spec.flag & S21_HASH)) {
      char *end = str - 1;
      while (*end == '0' && end > str && *(end - 1) != '.') {
        end--;
      }
      if (*end == '.' && end > str) {
        end--;
      }
      *(end + 1) = '\0';
      str = end + 1;
    }
  }

  return str;
}

char *s21_sprintf_eE(char *str, va_list args, char spec,
                     s21_format_spec_t format_spec) {
  double arg = va_arg(args, double);
  int precision =
      (format_spec.prec == -1) ? 6 : format_spec.prec;  // Точность по умолчанию
  int sign = (arg < 0) ? -1 : 1;
  int exponent = 0;

  arg = fabs(arg);

  if (arg != 0.0) {
    while (arg < 1.0) {
      arg *= 10.0;
      exponent--;
    }
    while (arg >= 10.0) {
      arg /= 10.0;
      exponent++;
    }
  }

  if (sign < 0) {
    *str++ = '-';
  }

  double rounding = 0.5;
  for (int i = 0; i < precision; i++) {
    rounding /= 10.0;
  }
  arg += rounding;

  int int_part = (int)arg;
  *str++ = int_part + '0';
  *str++ = '.';
  arg -= int_part;
  for (int i = 0; i < precision; i++) {
    arg *= 10.0;
    int digit = (int)arg;
    *str++ = digit + '0';
    arg -= digit;
  }
  *str++ = spec;
  *str++ = exponent < 0 ? '-' : '+';
  exponent = abs(exponent);

  if (exponent < 10) {
    *str++ = '0';
  }
  char exp_str[4] = {0};
  s21_sprintf(exp_str, "%d", exponent);
  char *exp_ptr = exp_str;
  while (*exp_ptr) {
    *str++ = *exp_ptr++;
  }

  *str = '\0';
  return str;
}

char *s21_sprintf_xX(char *str, va_list args, char spec,
                     s21_format_spec_t format_spec) {
  unsigned int arg = va_arg(args, unsigned int);
  char buffer[32] = {0};
  char *buf_ptr = buffer + sizeof(buffer);
  int len = 0;

  do {
    int digit = arg % 16;
    *(--buf_ptr) =
        (digit < 10) ? ('0' + digit) : ((spec == 'x' ? 'a' : 'A') + digit - 10);
    arg /= 16;
  } while (arg != 0);

  len = buffer + sizeof(buffer) - buf_ptr;

  char padding_char = (format_spec.flag & S21_ZERO) ? '0' : ' ';

  if (format_spec.flag & S21_MINUS) {
    while (buf_ptr < buffer + sizeof(buffer)) {
      *str++ = *buf_ptr++;
    }
    while (format_spec.width > len) {
      *str++ = ' ';
      format_spec.width--;
    }
  } else {
    while (format_spec.width > len) {
      *str++ = padding_char;
      format_spec.width--;
    }
    while (buf_ptr < buffer + sizeof(buffer)) {
      *str++ = *buf_ptr++;
    }
  }

  *str = '\0';

  return str;
}

char *s21_sprintf_o(char *str, va_list args, s21_format_spec_t format_spec) {
  unsigned int arg = va_arg(args, unsigned int);
  char buffer[32] = {0};
  char *buf_ptr = buffer + sizeof(buffer) - 1;
  *buf_ptr = '\0';
  int len = 0;

  if (arg == 0) {
    *(--buf_ptr) = '0';
    len = 1;
  } else {
    while (arg > 0) {
      *(--buf_ptr) = '0' + (arg & 7);
      arg >>= 3;
      len++;
    }
  }

  char padding_char = (format_spec.flag & S21_ZERO) ? '0' : ' ';

  if (format_spec.flag & S21_MINUS) {
    while (*buf_ptr) {
      *str++ = *buf_ptr++;
    }
    while (format_spec.width > len) {
      *str++ = ' ';
      format_spec.width--;
    }
  } else {
    while (format_spec.width > len) {
      *str++ = padding_char;
      format_spec.width--;
    }
    while (*buf_ptr) {
      *str++ = *buf_ptr++;
    }
  }

  *str = '\0';
  return str;
}

char *s21_sprintf_p(char *str, va_list args, s21_format_spec_t format_spec) {
  void *arg = va_arg(args, void *);
  uintptr_t ptr_value = (uintptr_t)arg;
  char buffer[32] = {0};
  char *buf_ptr = buffer + sizeof(buffer) - 1;
  *buf_ptr = '\0';

  if (ptr_value == 0) {
    *str++ = '(';
    *str++ = 'n';
    *str++ = 'i';
    *str++ = 'l';
    *str++ = ')';
  } else {
    do {
      *(--buf_ptr) = "0123456789abcdef"[ptr_value % 16];
      ptr_value /= 16;
    } while (ptr_value != 0);

    *(--buf_ptr) = 'x';
    *(--buf_ptr) = '0';
  }

  int len = buffer + sizeof(buffer) - buf_ptr - 1;
  int width = format_spec.width;
  int flag = format_spec.flag;

  if (width > len && flag != S21_MINUS) {
    s21_add_symbols_to_start(str, width, width - len, ' ');
    str += width - len;
  }

  while (*buf_ptr) {
    *str++ = *buf_ptr++;
  }

  if (width > len && flag == S21_MINUS) {
    str = s21_memset(str, ' ', width - len);
    str += width - len;
  }

  *str = '\0';
  return str;
}

int s21_get_flags(const char **format) {
  int flags = 0;
  const char *_format = *format;

  while (*_format == '-' || *_format == '+' || *_format == ' ' ||
         *_format == '0' || *_format == '#') {
    if (*_format == '-') flags |= S21_MINUS;
    if (*_format == '+') flags |= S21_PLUS;
    if (*_format == ' ') flags |= S21_SPACE;
    if (*_format == '0') flags |= S21_ZERO;
    if (*_format == '#') flags |= S21_HASH;
    ++_format;
  }

  *format = _format;

  return flags;
}

int s21_get_width(const char **format, va_list args) {
  int width = -1;
  const char *_format = *format;

  width = s21_get_digit_value(&_format, args);

  *format = _format;

  return width;
}

int s21_get_precision(const char **format, va_list args) {
  int precision = -1;
  const char *_format = *format;

  if (*_format == '.') {
    ++_format;
    precision = s21_get_digit_value(&_format, args);
  }

  *format = _format;

  return precision;
}

int s21_get_digit_value(const char **format, va_list args) {
  int res = -1;
  const char *_format = *format;

  if (isdigit((unsigned char)*_format)) {
    res = 0;
    while (isdigit((unsigned char)*_format)) {
      res = res * 10 + (*_format++ - '0');
    }
  } else if (*_format == '*') {
    res = va_arg(args, int);
    ++_format;
  }

  *format = _format;

  return res;
}

int s21_get_length(const char **format) {
  int length = S21_INT;
  const char *_format = *format;

  if (*_format == 'h') {
    if (*(_format + 1) == 'h') {
      length = S21_CHAR;
      _format += 2;
    } else {
      length = S21_SHORT;
      ++_format;
    }
  } else if (*_format == 'l') {
    if (*(_format + 1) == 'l') {
      length = S21_LONG_LONG;
      _format += 2;
    } else {
      length = S21_LONG;
      ++_format;
    }
  }

  *format = _format;

  return length;
}

void s21_set_length(void *arg, int length) {
  if (length == S21_CHAR) {
    arg = (signed char *)arg;
  } else if (length == S21_SHORT) {
    arg = (short *)arg;
  } else if (length == S21_LONG) {
    arg = (long *)arg;
  } else if (length == S21_LONG_LONG) {
    arg = (long long *)arg;
  }
}

char *s21_set_flag(char *str, int flag) {
  if (flag == S21_PLUS) {
    *str++ = '+';
  } else if (flag == S21_SPACE) {
    *str++ = ' ';
  }

  return str;
}

char *s21_set_width(char *str, char *buffer, int width) {
  int len = s21_strlen(buffer);

  int diff = width - len;

  return s21_wrap_memset(str, ' ', diff);
}

char *s21_set_precision(char *str, char *buffer, int precision) {
  int len = s21_strlen(buffer);
  int diff = precision - len;

  return s21_wrap_memset(str, '0', diff);
}

char *s21_wrap_memset(char *str, int value, int diff) {
  if (diff > 0) {
    s21_memset(str, value, diff);
    str += diff;
  }

  return str;
}

s21_format_spec_t s21_get_format_spec(const char **format, va_list args) {
  s21_format_spec_t format_spec = {-1, -1, -1, -1};
  const char *_format = *format;
  format_spec.flag = s21_get_flags(&_format);
  format_spec.width = s21_get_width(&_format, args);
  format_spec.prec = s21_get_precision(&_format, args);
  format_spec.length = s21_get_length(&_format);

  *format = _format;

  return format_spec;
}

char *s21_set_specs(char *str, const char *format, va_list args,
                    s21_format_spec_t format_spec) {
  char *_str = str;

  switch (*format) {
    case 'c':
      _str = s21_sprintf_c(str, args, format_spec);
      break;
    case 'd':
      _str = s21_sprintf_d(str, args, format_spec);
      break;
    case 'f': {
      double arg = va_arg(args, double);
      _str = s21_sprintf_f(str, &arg, format_spec, 0, 0);
    } break;
    case 's':
      _str = s21_sprintf_s(str, args, format_spec);
      break;
    case 'u':
      _str = s21_sprintf_u(str, args, format_spec);
      break;
    case '%':
      _str = s21_sprintf_percent(str);
      break;
    case 'g':
      _str = s21_sprintf_gG(_str, args, 'g', format_spec);
      break;
    case 'G':
      _str = s21_sprintf_gG(_str, args, 'G', format_spec);
      break;
    case 'e':
      _str = s21_sprintf_eE(_str, args, 'e', format_spec);
      break;
    case 'E':
      _str = s21_sprintf_eE(_str, args, 'E', format_spec);
      break;
    case 'x':
      _str = s21_sprintf_xX(_str, args, 'x', format_spec);
      break;
    case 'X':
      _str = s21_sprintf_xX(_str, args, 'X', format_spec);
      break;
    case 'o':
      _str = s21_sprintf_o(_str, args, format_spec);
      break;
    case 'p':
      _str = s21_sprintf_p(_str, args, format_spec);
      break;
    default:
      break;
  }

  return _str;
}

void s21_add_symbols_to_start(char *start, int str_len, int count, char c) {
  char buf[str_len + 1];
  char *_start = start;

  for (int i = 0; i < str_len; i++) {
    if (count > 0) {
      buf[i] = c;
    } else {
      buf[i] = *_start++;
    }

    count--;
  }

  buf[str_len] = '\0';

  for (int i = 0; i < str_len; i++) {
    start[i] = buf[i];
  }

  start[str_len] = '\0';
}