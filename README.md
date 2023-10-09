
Group Project:
0x16. C - Simple Shell



task 1.  
Write a UNIX command line interpreter.
Usage: simple_shell

the shell display a prompt and wait for the user to type a command, and also ends with a new line, prompt is displayed again each time a command has been executed, this is made only for words no argument can pass through it.. I created a custom strlen to calculate the length in my write function, which is in my custom Functions like _myprintf, show_prompt, and read_userinput are responsible for the user interface of my shell. They handle the printing of the prompt and reading of the user's input



Task2.
Simple shell 0.1 +
Handle command lines with arguments

I Tokenize the input line into separate arguments using strtok. Pass the arguments array to execve.  Function given from the list.
I create a function to tokenized the input, I firstly duplicate the input, which I allocate a memory for and later freed it.So now if I try to input a command with and arg, it should go through.



Task3
Simple shell 0.2 +
•	Handle the PATH
•	fork must not be called if the command doesn’t exist

I expand the PATH variable and I retrieve the PATH from the environ variable and I tokenized it to get individual directories.  Before forking, I iterate through the PATH directories and search for command using ‘access’ function, if the command  is found in the directories, fork and execute it. Otherwise print ‘command not found’ the shell checks if commands are in the system's PATH using the find_cmdpath and build_cmdpath functions. This allows the user to run commands without specifying the full path



Task4.
Simple shell 0.3 +
Implement the exit built-in, that exits the shell
Usage: exit

child_execution, execute_input, and exit_execute are central to how the shell executes commands. child_execution is responsible for forking a new process and using execve to run the desired command. execute_input is the main coordinator, interpreting user input, checking for built-in commands, and launching external commands



task5
Simple shell 0.4 +
Implement the env built-in, that prints the current environment

The cust_getenv function is a custom implementation to retrieve the value of a given environment variable. This is especially useful for fetching the PATH variable to search for commands. have a set of custom string manipulation functions (cust_strlen, cust_strdup, cust_strcpy, cust_strcat, and cust_strncmp). These provide essential string operations that the program works on


