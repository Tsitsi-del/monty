#include "monty.h"

/**
 * push - function is used to push a node on top of the stack
 * @stack: pointer to head node of stack
 * @num_line: line number
 * Return: NULL
 */

void push(stack_t **stack, unsigned int num_line)
{
	stack_t *new;

	if (!stack)
	{
		fprintf(stderr, "L%d: stack not found\n", num_line);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->next = *stack;
	new->prev = NULL;
	new->n = arg.arg;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * free_stack - function that free stack
 * @stack: stack to be freed
 * Return: NULL
 */

void free_stack(stack_t **stack)
{
	stack_t *temporary = NULL;

	if (!stack || *stack == NULL)
		return;

	while (*stack)
	{
		temporary = (*stack)->next;
		free(*stack);
		*stack = temporary;
	}
}
/**
 * nop - function that does nothing
 * @stack: pointer to the head of the stack
 * @num_line: line number
 * Return: NULL
 */

void nop(stack_t **stack, unsigned int num_line)
{
	(void)stack;
	(void)num_line;
}
/**
 * _isalpha - function that checks if is it an alphabet
 * @cha: value or character
 * Return: 1 on Success, 0 on Fail
 */
int _isalpha(int cha)
{
	if (((cha >= 'a') && (cha <= 'z')) || ((cha >= 'A') && (cha <= 'Z')))
		return (1);
	else
		return (0);
}

/**
 * pall - function that prints all in stack
 * @stack: pointer to the head of the stack
 * @num_line: line number
 * Return: NULL
 */

void pall(stack_t **stack, unsigned int num_line)
{
	stack_t *temporary;
	(void)num_line;

	temporary = *stack;

	while (temporary != NULL)
	{
		printf("%d\n", temporary->n);
		temporary = temporary->next;
	}
}
