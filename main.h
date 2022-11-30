#ifndef _main_h_
#define _main_h_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct print
{
	char *arg;
	int (*f)(va_list, char *, unsigned int);
} printt;

unsigned int hand_buffer(char *, char, unsigned int);
int print_buffer(char *, unsigned int);
int _printf(const char *, ...);
int (*get_print_function(char))(va_list, char *, unsigned int);
int ct_print_function(va_list, char *, unsigned int);
int print_str(va_list, char *, unsigned int);
int print_char(va_list, char *, unsigned int);
int print_int(va_list, char *, unsigned int);
int print_prc(va_list,  __attribute__((unused)), char *, unsigned int);
int print_bnr(va_list, char *, unsigned int);
int print_unt(va_list, char *, unsigned int);
int print_oct(va_list, char *, unsigned int);
int print_add(va_list, char *, unsigned int);
int print_hex(va_list, char *, unsigned int);
int print_upx(va_list, char *, unsigned int);
int print_usr(va_list, char *, unsigned int);
int print_rev(va_list, char *, unsigned int);
int print_rot(va_list, char *, unsigned int);
int printloct(va_list, char *, unsigned int);
int printlint(va_list, char *, unsigned int);
int printlunt(va_list, char *, unsigned int);
int printlupx(va_list, char *, unsigned int);
int printlhex(va_list, char *, unsigned int);
int printsunt(va_list, char *, unsigned int);
int printsint(va_list, char *, unsigned int);
int printspint(va_list, char *, unsigned int);
int printpint(va_list, char *, unsigned int);
int printshex(va_list, char *, unsigned int);
int printsupx(va_list, char *, unsigned int);
int printsoct(va_list, char *, unsigned int);
int printnoct(va_list, char *, unsigned int);
int printnhex(va_list, char *, unsigned int);
int printnupx(va_list, char *, unsigned int);
char *fill_binary_array(char *, long int, int, int);
char *fill_hex_array(char *, char *, int, int);
char *fill_oct_array(char *, char *);
char *fill_long_oct_array(char *, char *);
char *fill_short_oct_array(char *, char *);

#endif
