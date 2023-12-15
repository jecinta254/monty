#include "monty.h"
/**
 * pint_fns -  prints the value at the top of the stack, followed by a new line.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pint_fns(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack_fns(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
