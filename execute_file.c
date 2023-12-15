#include "monty.h"
/**
* execution_fns - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execution_fns(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_fns}, {"pall", pall_fns}, {"pint", pint_fns},
				{"pop", pop_fns},
				{"swap", swap_fns},
				{"add", add_fns},
				{"nop", nope_fns},
				{"sub", subract_fns},
				{"div", div_fns},
				{"mul", mul_fns},
				{"mod", mod_fns},
				{"pchar", print_char_fns},
				{"pstr", print_string_fns},
				{"rotl", rotate_fns},
				{"rotr", rotate_bottom_fns},
				{"queue", queue_fns},
				{"stack", stack_fns},
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
		free_stack_fns(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
