#include "shell.h"

/**
 * concat_path - builds the final command.
 * @tok: command to concat.
 * @path: path env var.
 * Return: tokenized full path,
 *		NULL -> fail.
 */
char *concat_path(char *tok, char *path)
{
	char *final;
	size_t len;

	len = strlen(path) + strlen(tok) + 2;
	final = malloc(sizeof(char) * len);
	if (final == NULL)
		return (NULL);

	memset(final, 0, len);
	final = str_cat(final, path);
	final = str_cat(final, "/");
	final = str_cat(final, tok);
	return (final);
}

/**
 * get_path - gets and tokenizes the path env var.
 *
 * @line: tokenized read command line.
 *
 * Return: 0 -> success.
 *		1 -> fail.
 */
int get_path(char **line)
{
	char *path, *tokens, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	tokens = str_tok(path, ":");
	while (tokens != NULL)
	{
		cmd_path = concat_path(*line, tokens);
		if (stat(cmd_path, &buf) == 0)
		{
			*line = str_dup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		tokens = str_tok(NULL, ":");
	}
	free(path);
	return (1);
}
