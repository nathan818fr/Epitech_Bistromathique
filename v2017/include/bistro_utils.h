#ifndef BISTRO_UTILS_H_
#define BISTRO_UTILS_H_

#include <stdlib.h>

#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))
#define MY_MIN(a, b) ((a) > (b) ? (b) : (a))

#ifdef BISTRO_DEBUG
	#define BISTRO_ERROR(CODE, MSG, DESC) \
		bistro_error_debug_fct((CODE), (MSG), (DESC), \
			(debug_ctx_t){__FILE__, __LINE__})
#else
	#define BISTRO_ERROR(CODE, MSG, DESC) \
		bistro_error_fct((CODE), (MSG))
#endif

/*
** utils/number_utils.c
*/
void *bistro_malloc(size_t);
void bistro_error_fct(int, char *);
int bistro_char_is_repeating(const char *str);
int bistro_char_matching(const char *str1, const char *str2);
#ifdef BISTRO_DEBUG
typedef struct debug_ctx_s {
	const char *file;
	int line;
} debug_ctx_t;

void bistro_error_debug_fct(int, char *, char *, debug_ctx_t debug_ctx);
#endif

/*
** utils/bistro_get_nbr.c
*/
size_t bistro_get_nbr(char *);

/*
** utils/my_putstr.c
*/
void my_putstr_to(int fd, char const *str);
void my_putstr(char const *);
void my_puterr(char const *str);

/*
** utils/my_strlen.c
*/
size_t my_strlen(char const *);

/*
** utils/my_memset.c
*/
void *my_memset(void *, int, size_t);

/*
** utils/my_putnbr.c
*/
void my_putnbr(int fd, long nb);

#endif
