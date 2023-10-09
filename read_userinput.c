#include "shell.h"

/**
 * read_userinput - to read the input command from standard input
 * @input: buffer to store input
 */
void read_userinput(char **input)
{
	size_t len = 0;
	char *str_ptr;

	if (getline(input, &len, stdin) == -1)
	{
		free(*input);
		*input = NULL;
		error_userinput();
	}
	for (str_ptr = *input; *str_ptr; str_ptr++)
		if (*str_ptr == '\n')
		{
			*str_ptr = '\0';
			break;
		}
}

/**
 * error_userinput - Handles input errors from the user.
 *
 * This function is called when getline fails to read user input.
 * It checks if the error was due to an end-of-file conditon (like Ctrl-D)
 * If EOF, it prints a newline and exits successfully.
 * Otherwise, it prints an error message using perror and exits with a fail
 */
void error_userinput(void)
{
	if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror("cust_getline");
		exit(EXIT_FAILURE);
	}
}

/**
 * child_execution - Creates a child process and executes the given command.
 *
 * @arg_str: Null-terminated array of arguments for the command to be execu
 *
 * This function first attempts to create a child process using fork().
 * If fork fails, an error message is printed and the shell exits with a fail
 * If the fork is successful and we are in the child process, execve()
 * In the parent process, it waits for the child to complet exec using wait()
 */
void child_execution(char **arg_str)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execve(arg_str[0], arg_str, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

