#include "main.h"
/**
 * main - Function that creates a command line interpreter
 * Return: Always 0
 */
int main(void)
{
	char *line_buf = NULL, *path_com = NULL;
	char *array[1024], *array_dir[1024];
	size_t s = 0;

	while (1)
	{
		if (isatty(0))
			printf("#cisfun$");
		if (getline(&line_buf, &s, stdin) == -1)
		{
			free(line_buf);
			exit(0);
		}
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
		return (0)
	}
}
