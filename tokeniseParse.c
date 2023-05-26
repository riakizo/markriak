#include "main.h"
/**
 * tokeniseParse - tokenise and parse
 * @input: input
 * Return: char **
 */
char **tokeniseParse(char *input)
{
	char **args, *input_copy, *token;
	int i = 0, j = 0;

	input_copy = malloc(_strlen(input) + 1);
	if (!input_copy)
		return (NULL);
	_strcpy(input_copy, input);
	token = strtok(input_copy, " ");
	while (token)
	{
		if (!_strcmp(token, ""))
			i++;
		token = strtok(NULL, " ");
	}
	args = malloc((i + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	i = 0;
	token = strtok(input, " ");
	while (token)
	{
		j = 0;
		while (token[j] != '\0')
		{
			if (token[j] == '\n')
				token[j] = '\0';
			j++;
		}
		if (_strcmp(token, ""))
		{
			token = strtok(NULL, " ");
			continue;
		}
		args[i] = malloc(j + 1);
		args[i] = _strcpy(args[i], token);
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
