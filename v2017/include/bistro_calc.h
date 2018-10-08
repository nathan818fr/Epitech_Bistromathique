#ifndef BISTRO_CALC_H_
#define BISTRO_CALC_H_

#include "bistro.h"
#include "bistro_number.h"

typedef struct calc_s {
	bistro_t *bistro;
	number_t *nbr1;
	number_t *nbr2;
	number_t *result;
} calc_t;

/*
** calc/calc.c
*/
number_t *calc(number_t *, number_t *, int, bistro_t *);

/*
** calc/calc_utils.c
*/
void calc_swap_numbers(calc_t *);
int calc_cmp_numbers(calc_t *);

/*
** calc/calc_add.c
*/
void calc_add(calc_t *);
void calc_add_numbers(calc_t *);

/*
** calc/calc_sub.c
*/
void calc_sub(calc_t *);
void calc_sub_numbers(calc_t *);

/*
** calc/calc_mult.c
*/
void calc_mult(calc_t *);

/*
** calc/calc_div.c
*/
void calc_div(calc_t *);

/*
** calc/calc_mod.c
*/
void calc_mod(calc_t *);

#endif