#include "main.h"

/**
 * main - Function that creates a command line interpreter
 * Return: Always 0
 */

int main(void)
{
	char *line_buf = NULL;
	char *array[1024], *array_dir[1024];
	size_t s = 0;
	ssize_t nchars = 0;
	int m;

	/* Infinite loop for shell prompt*/
	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Check if input is from interactive terminal*/
			printf("~# ");

		nchars = getline(&line_buf, &s, stdin); /* Number of characteres typed*/

		if (nchars == -1) /* check if getline fail, EOF or user use CTRL + D */
		{
			free(line_buf);
			putchar('\n');
			exit(EXIT_SUCCESS);
		}
		if (line_buf[0] == '\n')
			continue;

		array[0] = strtok(line_buf, " \t\n");

		if (!array[0])
			continue;

		for (m = 1; m < 1024; m++)
		{
			array[m] = strtok(NULL, " \t\n");
			if (!array[m])
				break;
		}

		if (check_space(line_buf))
		{
			get_token(line_buf, array, "\t\n ");
			if (verify_dir(array[0]))
			{
				if (verify_status(array[0]))
					subprocess(array);
			}
			else
			{
				if (!verify_dir(array[0]))
				{
					char *full_path = find_command(array[0]);
					if (full_path != NULL)
					{
						aux_subprocess(array, full_path);
						free(full_path);
						free_array_dir(array_dir);
					}
					else
					{
						printf("%s: Command not found\n", array[0]);
					}
				}
		}
	}
	}
return (0);
}
