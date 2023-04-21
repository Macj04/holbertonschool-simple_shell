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

	/* Infinite loop for shell prompt*/
	while (1)
	{
		if (isatty(0)) /* Check if input is from interactive terminal*/
			printf("#cisfun$");

		nchars = getline(&line_buf, &s, stdin); /* Number of characteres typed*/

		if (nchars == -1) /* check if getline fail, EOF or user use CTRL + D */
		{
			free(line_buf);
			exit(0);
		}

		line_buf = malloc(sizeof(char) * nchars); /* Memory allocation */

		if (check_space(line_buf)) /* Check if the string exist */
		{
			/*divides the string into tokens using delimiters*/
			get_token(line_buf, array, "\t\n ");
			/*Return the executable rout*/
			if (path_com == verify_path(array[0], array_dir))
			{
				subprocess(array, path_com); /*Execute the file*/
				free(path_com);
				free_array_dir(array_dir);
			}
			else
				/*If it doesn't exist print this*/
				printf("command not found\n");
		}
	}
}
