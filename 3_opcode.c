#include "monty.h"

/**
 * qpush - Function pushes queue
 * @stack: pointer to the head
 * @num_line: line number
 * Return: NULL
 */

void qpush(stack_t **stack, unsigned int num_line)
{
	stack_t *end, *new;

	if (!stack)
	{
		fprintf(stderr, "L%d: stack not found\n", num_line);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(satck);
		exit(EXIT_FAILURE);
	}

	end = NULL;
	if (*stack != NULL)
	{
		end = *stack;
		while (end->next)
			end = end->next;
		end->next = new;
	}
	else
	{
		*stack = new;
	}
	new->prev = end;
	new->next = NULL;
	new->n = arg.arg;
}
/**
 * rotrop - Function rotates stack to right
 * @stack: pointer to the head node pointer of stack
 * @num_line: line number
 * Return: NULL
 */
void rotrop(stack_t **stack, unsigned int num_line)
{
	stack_t *temp, *end;
	(void)num_line;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	end = temp;

	while (end->next)
	{
		end = end->next;
	}
	end->prev->next = NULL;
	end->prev = NULL;
	temp->prev = end;
	end->next = temp;
	*stack = end;
}

/**
 * rotlop - Function rotates stack to the left
 * @stack: pointer to the head
 * @num_line: line number
 * Return: NULL
 */

void rotlop(stack_t **stack, unsigned int num_line)
{
	stack_t *end, *temp;
	(void)num_line;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = *stack;
	end = temp;

	while (end->next)
	{
		end = end->next; }

	end->next = temp;
	temp->prev = end;
	temp->next->prev = NULL;
	*stack = temp->next;
	temp->next = NULL;
}
/**
 * rot1 - Function that rotates stack to the top
 * @stack: pointer to the head node pointer of stack
 * @num_line: line number
 * Return: Null
 */

void rot1(stack_t **stack, unsigned int num_line)
{
	stack_t *temporary;
	int temp1, temp2;
	(void)num_line;

	if (!stack || *stack == NULL)
		nop(stack, num_line);

	temp1 = (*stack)->n;
	temporary = *stack;

	while (temporary != NULL)
	{
		if (temporary->next == NULL)
			break;
		temporary = temporary->next;
	}
	temp2 = temporary->n;
	(*stack)->n = temp2;
	temporary->n = temp1;
}
