#include "monty.h"
/**
 * pint_func -  prints the value at the top of the stack, followed by a new line.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pint_func(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack_func(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
