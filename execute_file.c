#include "monty.h"
/**
* execution_fun - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execution_fun(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_func}, {"pall", pall_func}, {"pint", pint_func},
				{"pop", pop_func},
				{"swap", swap_func},
				{"add", add_func},
				{"nop", nope_func},
				{"sub", subract_func},
				{"div", div_func},
				{"mul", mul_func},
				{"mod", mod_func},
				{"pchar", print_char_func},
				{"pstr", print_string_func},
				{"rotl", rotate_func},
				{"rotr", rotate_bottom_func},
				{"queue", queue_func},
				{"stack", stack_func},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack_func(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
