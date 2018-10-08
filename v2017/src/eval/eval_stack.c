#include "bistro_utils.h"
#include "bistro_eval.h"

void eval_stack_push(eval_stack_t **stack)
{
	eval_stack_t *nstack;

	nstack = bistro_malloc(sizeof(eval_stack_t));
	my_memset(nstack, 0, sizeof(eval_stack_t));
	nstack->parent = *stack;
	*stack = nstack;
}

void eval_stack_pop(eval_stack_t **stack)
{
	eval_stack_t *fstack;

	fstack = *stack;
	*stack = (*stack)->parent;
	free(fstack);
}
