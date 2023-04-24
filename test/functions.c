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
	int m = 0, l = 0;
	char *vdir;
	struct stat sta;
	char *take = NULL;
	char *rut = NULL;
	char *whe = NULL;

	take = strdup(func_getenv("PATH="));
	whe = take;
	strtok(take, ":=");

	if (rut)
	{
		for (l = 0; rut[l]; l++)
		{
			rut = strtok(NULL, ":=");
			array_path[l] = strdup(rut);
		}
		array_path[l] = NULL;
		free(whe);
		take = NULL;
	}
	for (m = 0; array_path[m]; m++)
	{
		vdir = malloc(strlen(line_buf) + strlen(array_path[m]) + 1000);
		if (vdir == NULL)
			return (NULL);
		strcpy(vdir, array_path[m]);
		strcat(vdir, "/");
		strcat(vdir, line_buf);
		if (stat(vdir, &sta) == 0)
			return (vdir);
		free(vdir);
	}
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
