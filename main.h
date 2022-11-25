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
int (*get_print_function(const char *, int))(va_list, char *, unsigned int);
int print_str(va_list, char *, unsigned int);
int print_char(va_list, char *, unsigned int);
int print_int(va_list, char *, unsigned int);
int print_prc(va_list, char *, unsigned int);
int print_bnr(va_list, char *, unsigned int);
char *fill_binary_array(char *, long int, int, int);


#endif
