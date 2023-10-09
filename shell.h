#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_ARGS 150

void show_prompt(void);
int _myprintf(const char *content);
void read_userinput(char **input);
void execute_input(const char *input);
char **tokenize_input(const char *input);
void error_userinput(void);
char *find_cmdpath(const char *cmd);
void exit_execute(const char *input);
void child_execution(char **arg_str);
char *build_cmdpath(const char *cmd, char *token);
char *cust_getenv(const char *nam);

extern char **environ;

char *cust_strdup(const char *s);
char *cust_strcpy(char *s1, const char *s2);
int cust_strlen(const char *s);
char *cust_strcat(char *s1, const char *s2);

int cust_strncmp(const char *s1, const char *s2, size_t n);




#endif
