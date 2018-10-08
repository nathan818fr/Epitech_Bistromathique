#ifndef BISTRO_NUMBER_H_
#define BISTRO_NUMBER_H_

#include <stddef.h>
#include "bistro.h"

typedef unsigned char nbchar_t;

typedef struct number_s {
	char is_neg;
	size_t len;
	nbchar_t *str;
} number_t;

/*
** number/number.c
*/
number_t *number_create(size_t len);
number_t *number_dup(number_t *nb);
number_t *number_dup_with_len(number_t *nb, size_t len);
void number_free(number_t *nb);
number_t *number_fix(number_t *nb);

/*
** number/number_utils.c
*/
int number_char_val(bistro_t *bistro, char c);
char *number_to_string(bistro_t *bistro, number_t *nb);
void number_base_inc(number_t *nb);
void number_base_dec(number_t *nb);

#endif
