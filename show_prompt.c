#include "shell.h"

/**
 * show_prompt - Display the shell prompt
 */
void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_myprintf("simple_shell$ ");
		fflush(stdout);
	}
}

/**
 * _myprintf - to print outputs to the screen
 * @content: The content to output
 * Return: it should the return len of the content
 */
int _myprintf(const char *content)
{
	int len =  cust_strlen(content);

	write(STDOUT_FILENO, content, len);

	return (len);
}

/**
 * sigint_handler - function that is called when press SIGINT (Ctrl+C)
 * @signum: the signal number
 */
void sigint_handler(int signum)
{
	(void)signum; /*Mark the parameter as unused to avoid the warning*/

	/*Print a newline to avoid cluttering the prompt*/
	_myprintf("\n");
	show_prompt();
}
