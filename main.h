#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED   2

/**
 * struct parameters - parameters struct
 * @unsign: flag if unsigned value
 * @plus_flag: if plus_flag specified
 * @zero_flag: if _flag specified
 * @hashtag_flag: if hashtag_flag specified
 * @minus_flag: if _flag specified
 * @space_flag: if _flag specified
 * @precision: field precision specified
 * @width: field width specified
 * @h_modifier: if h_modifier is specified
 * @l_modifier: if l_modifier is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int zero_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int minus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int precision
	unsigned int width
	unsigned int h_modifier		: 1:
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - struct token
 * @specifier: format token
 * @f: function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* file_2.c file */
int _puts(char *str);
int _putchar(int c);

/* file_10.c file */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);

/* file_7.c file */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* file_3.c file */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_ modifier(char *s, params_t *params);
int get_flag(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* file_9.c file */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* file_5.c file */
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);
int print_from_to(char *start, char *stop, char *except);

/* file_1.c file */
void init_params(params_t *params, va_list ap);

/* file_4.c file */
char *get_precision(char *p, params_t *params, va_list ap);

/* file_8.c file */
int _isdigit (int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* file_6.c file */
int _printf(const char *format, ...);

#endif
