#include "monty.h"

/**
 * modop - Function computes the rest of the division
 * of the second top element of the stack by the top element of the stack
 * @stack: pointer to the head node pointer of stack
 * @num_line: line number
 * Return: NULL
 */
void modop(stack_t **stack, unsigned int num_line)
{
	stack_t *tmp;

	if (!(stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
/**
 * mulop - Function mul the top two elements and store it in the second el
 * @stack: pointer to the head node
 * @num_line: line number
 * Return: NULL
 */
void mulop(stack_t **stack, unsigned int num_line)
{
	stack_t *tem;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	tem = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tem);
}

/**
 * addop - Function add the top two elements
 * @stack: pointer to the head node pointer
 * @num_line: line number
 * Return: NULL
 */

void addop(stack_t **stack, unsigned int num_line)
{
	stack_t *tem;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	tem = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tem);
}
/**
 * subop - Function subtracts the top two elements
 * @stack: pointer to the head node pointer
 * @num_line: line number
 * Return: NULL
 */

void subop(stack_t **stack, unsigned int num_line)
{
	stack_t *tem;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	tem = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tem);
}
/**
 * divop - Function divides the top two
 * elements and stores it in the second element
 * @stack: pointer to the head node pointer
 * @num_line: line number
 * Return: NULL
 */
void divop(stack_t **stack, unsigned int num_line)
{
	stack_t *tem;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		exit(EXIT_FAILURE);
	}

	tem = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tem);
}
