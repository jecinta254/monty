#include "monty.h"
/**
 * pop_func -  removes the top element of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pop_func(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack_func(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
