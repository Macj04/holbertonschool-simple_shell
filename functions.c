#include "main.h"
/**
 * check_space - Checks for a space in the argument
 * @line_buf: command typed
 * Return: 0 failure, 1 on succes
 */
int check_space(char *line_buf)
{
	int m = 0;

	for (m = 0; line_buf[m]; m++)
	{
		if (line_buf[m] != ' ' && line_buf[m] != '\n' && line_buf[m] != '\t')
			return (1);
	}
	return (0);
}

/**
 * get_token - Function that generate an array
 * @line_buf: Command line
 * @array: Pointer to pointer
 * @delimit: Delimiter argument
 * Return: Always 0.
 */
void get_token(char *line_buf, char **array, char *delimit)
{
	int m = 0;

	array[m] = strtok(line_buf, delimit);
	while (array[m])
	{
		m++;
		array[m] = strtok(NULL, delimit);
	}
}

/**
 * verify_path - Verify the current path
 * @line_buf: Buffer
 * @array_path: Pointer to a pointer to a string
 * Return: Direction exist or no
 */
char *verify_path(char *line_buf, char **array_path)
{
	struct stat sta;
	char *path = NULL;
	int m;

	for (m = 0; array_path[m] != NULL; m++)
	{
		path = malloc(strlen(array_path[m]) + strlen(line_buf) + 2);
		if (path == NULL)
			return (NULL);
		sprintf(path, "%s/%s", array_path[m], line_buf);
		if (stat(path, &sta) == 0)
			return (path);
	}
	free(path);
	return (NULL);
}

/**
 * subprocess - function that creates another process
 * @argv: Line command content
 * @path: Path
 * Return: 0 or -1
 */
int subprocess(char **argv)
{
	pid_t id;
	int cond = 0;

	id = fork();
	if (id == -1)
		return (-1);
	if (id == 0)
		execve(argv[0], argv, NULL);
	else
		wait(&cond);
	return (0);
}

/**
 * free_array_dir - Fuction that free the array direction
 * @array_dir: Direction of array
 * Return: Always 0
 */
void free_array_dir(char **array_dir)
{
	int m = 0;

	if (array_dir)
	{
		for (m = 0; array_dir[m]; m++)
			free(array_dir[m]);
	}
}
