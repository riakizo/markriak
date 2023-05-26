#include "main.h"

/**
 * main - main
 * @ac: argc
 * @av: argv
 * @envp: env var
 * Return: 0
 */
int main(int ac, char **av, char **envp)
{
	char **argv = NULL, *input = NULL, *out;
	size_t n;
	ssize_t i;
	int w;
	pid_t child;

	(void)ac;
	(void)envp;
	while (1)
	{
		_puts("# ");
		i = getline(&input, &n, stdin);
		if (i == -1)
			break;
		argv = tokeniseParse(input);
		if (argv == NULL || argv[0] == NULL)
			continue;
		if (handleBuiltIn(argv))
		{
			continue;
		}
		out = pathSearch(argv[0]);
		child = fork();
		if (child == 0)
		{
			if (execve(out, argv, environ) == -1)
			{
				perror(av[0]);
				exit(1);
			}
		}
		else
		{
			wait(&w);
		}

	}
	free(input);
	return (0);
}

/**
 * pathSearch - search path
 * @av: argv
 * Return: char *
 */
char *pathSearch(char *av)
{
	char *out;

	if (check(av))
	{
		out = malloc(_strlen(av) + 7);
		_strcpy(out, "/bin/");
		_strcpy(out + 5, av);
		out[_strlen(av) + 5] = '\0';
	}
	else
	{
		out = malloc(_strlen(av) + 1);
		_strcpy(out, av);
	}
	return (out);
}

/**
 * check - check
 * @execut: execute
 * Return: int
 */
int check(char *execut)
{
	struct dirent *dir;
	DIR *directory;

	directory = opendir("/usr/bin/");
	if (directory)
	{
		while ((dir = readdir(directory)))
		{
			if (_strcmp(dir->d_name, execut))
			{
				closedir(directory);
				return (1);
			}
		}
	}
	closedir(directory);
	return (0);
}

/**
 * handleBuiltIn - handle built in commands
 * @args: args
 * Return: int
 */
int handleBuiltIn(char **args)
{
	if (_strcmp(args[0], "env"))
	{
		handle_env();
		return (1);
	}
	else if (_strcmp(args[0], "exit"))
		exit(0);
	else
		return (0);
}
/**
 * handle_env - prints envp
 */
void handle_env(void)
{
	int i;

	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}
