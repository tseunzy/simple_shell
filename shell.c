#include "shell.h"


/**
 * main - to display the prompt simple_shell$
 *
 * Return: nothing.
 */
int main(void)
{
	char *input = NULL;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		read_userinput(&input);
		execute_input(input);
		show_prompt();

		free(input); /*Release buffer memory after executing command*/
		input = NULL; /*Reset for the subsequent iteration*/
	}

	return (0);
}

