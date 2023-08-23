#include "shell.h"

/**
 * mirror - checks a char matches another.
 *
 * @c: character.
 * @s: string.
 *
 * Return: 1 -> success,
 *		0 -> on fail.
 */
unsigned int mirror(char c, const char *s)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (c == s[i])
			return (1);
	}
	return (0);
}

/**
 * str_tok - Separates a string by delimiter.
 *
 * @s: String to a separate.
 * @delim: The separator.
 *
 * Return: Tokens of a string.
 */
char *str_tok(char *s, const char *delim)
{
	static char *first_token, *second_tok;
	unsigned int i;

	if (s != NULL)
		second_tok = s;
	first_token = second_tok;
	if (first_token == NULL)
		return (NULL);
	for (i = 0; first_token[i] != '\0'; i++)
	{
		if (mirror(first_token[i], delim) == 0)
			break;
	}
	if (second_tok[i] == '\0' || second_tok[i] == '#')
	{
		second_tok = NULL;
		return (NULL);
	}
	first_token = second_tok + i;
	second_tok = first_token;
	for (i = 0; second_tok[i] != '\0'; i++)
	{
		if (mirror(second_tok[i], delim) == 1)
			break;
	}
	if (second_tok[i] == '\0')
		second_tok = NULL;
	else
	{
		second_tok[i] = '\0';
		second_tok = second_tok + i + 1;
		if (*second_tok == '\0')
			second_tok = NULL;
	}
	return (first_token);
}

/**
 * tokenizer - tokenizes the read input line.
 *
 * @line: Read input line.
 *
 * Return: Array of pointers to the tokens,
 *	NULL -> on fail.
 */
char **tokenizer(char *line)
{
	char **tokens, *token;
	int i, buff_siz = BUFSIZE;

	if (line == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buff_siz);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}
	token = str_tok(line, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = str_tok(NULL, "\n ");
	}
	tokens[i] = NULL;
	return (tokens);
}
