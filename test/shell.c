#include "main.h"
/**
 * main - Function that creates a command line interpreter
 * Return: Always 0
 */
int main(void)
{
	char *line_buf = NULL, *path_com = NULL;
	char *array[1020], *array_dir[1024];
	size_t s = 0;
	ssize_t nchars;

	while (1)
	{
		if (isatty(0))
			printf("#cisfun$");

		nchars = getline(&line_buf, &s, stdin);

		if (nchars == -1)
		{
			free(line_buf);
			exit(0);
		}

		line_buf = malloc(sizeof(char) * nchars);

		if (check_space(line_buf))
		{
			get_token(line_buf, array, "\t\n ");
			if (path_com == verify_path(array[0], array_dir))
			{
				subprocess(array, path_com);
				free(path_com);
				free_array_dir(array_dir);
			}
			else
				printf("command not found\n");
		}
	}
}
