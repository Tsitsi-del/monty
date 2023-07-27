#include "monty.h"

/**
 * pop - function that removes top element on stack
 * @stack: pointer to head of stack
 * @num_line: line number
 * Return: NULL
 */

void pop(stack_t **stack, unsigned int num_line)
{
	if (!stack || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num_line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
 * swap - function that swap the top 2 elements of stack
 * @stack: pointer to the head node pointer of stack
 * @num_line: line number
 * Return: Null
 */
void swap(stack_t **stack, unsigned int num_line)
{
	int temporary;

	if (!stack || *stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	temporary = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temporary;
}

/**
 * pstr - Function prints a str from ascii from the top of stack
 * @stack: pointer to the head node pointer of the stack
 * @num_line: line number
 * Return: Null
 */
void pstr(stack_t **stack, unsigned int num_line)
{
	int index = 0;
	char cha;
	char result[] = "";
	stack_t *temporary;

	temporary = *stack;
	(void)num_line;

	while (temporary != NULL)
	{
		if (temporary->n == 0)
			break;
		if (-isalpha(temporary->n) == 0)
			break;

		cha = temporary->n;
		printf("%c", cha);
		result[index] += cha;
		temporary = temporary->next;
		index++;
	}
	printf("\n");
}

/**
 * pchar -function that prints char at top of stack
 * @stack: pointer to the head node
 * @num_line: line number
 * Return: NULL
 */
void pchar(stack_t **stack, unsigned int num_line)
{
	char cha;
	stack_t *temporary;

	if (!stack || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	temporary = *stack;

	while (temporary != NULL)
	{
		if (temporary->prev == NULL)
			break;
		temporary = temporary->prev;
	}
	cha = temporary->n;
	if (_isalpha(temporary->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num_line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", cha);
}

/**
 * pint - Function that prints val at the top of stack
 * @stack: pointer to the head node pointer of stack
 * @num_line: line number
 * Return: NULL
 */

void pint(stack_t **stack, unsigned int num_line)
{
	stack_t *temporary;

	if (!stack || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	temporary = *stack;

	while (temporary != NULL)
	{
		if (temporary->prev == NULL)
			break;
		temporary = temporary->prev;
	}
	printf("%d\n", temporary->n);
}
