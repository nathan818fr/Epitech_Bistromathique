#include <unistd.h>
#include "bistro.h"
#include "bistro_utils.h"

void *bistro_malloc(size_t size)
{
	void *ptr = NULL;

	ptr = malloc(size);
	if (ptr == NULL)
		BISTRO_ERROR(EXIT_MALLOC, ERROR_MSG, "out of memory");
	return (ptr);
}

#ifdef BISTRO_DEBUG
void bistro_error_debug_fct(int error_code, char *error_msg, char *error_desc,
	debug_ctx_t debug_ctx)
{
	my_puterr("[error debug] ");
	my_puterr(debug_ctx.file);
	my_puterr(":");
	my_putnbr(STDERR_FILENO, debug_ctx.line);
	my_puterr(": ");
	my_puterr(error_desc);
	my_puterr("\n");
	bistro_error_fct(error_code, error_msg);
}
#endif

void bistro_error_fct(int error_code, char *error_msg)
{
	my_putstr(error_msg);
	exit(error_code);
}

int bistro_char_is_repeating(const char *str)
{
	int i = 0;
	int j = 1;

	while (str[i] != '\0') {
		if (str[i] == str[j])
			return (1);
		if (str[j + 1] != '\0')
			j = j + 1;
		else {
			i = i + 1;
			j = i + 1;
		}
	}
	return (0);
}

int bistro_char_matching(const char *str1, const char *str2)
{
	int i = 0;
	int j;

	while (str1[i] != '\0') {
		j = 0;
		while (str2[j] != '\0') {
			if (str1[i] == str2[j])
				return (1);
			j = j + 1;
		}
		i = i + 1;
	}
	return (0);
}
