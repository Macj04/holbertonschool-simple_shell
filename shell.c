#include "main.h"
int
main(void)
{
	char *line_buf = NULL, *array[1000], *full_path = NULL;
	size_t s = 0;
	ssize_t nchars = 0;
	int m;

	while (1) /*Infinite loop for shell prompt*/
	{
		if (isatty(STDIN_FILENO)) /* Check if input is from interactive terminal*/
			printf("~# ");
		nchars = getline(&line_buf, &s, stdin); /* Number of characteres typed*/
		if (nchars == -1) /* check if getline fail, EOF or user use CTRL + D */
		{
			free(line_buf);
			exit(0);
		}
		if (strcmp(line_buf, "exit\n") == 0)
		{
			free(line_buf);
			exit(2);
		}
		array[0] = strtok(line_buf, " \t\n"); /*Obtain the first command argument*/
		if (!array[0])
			continue; /*If no arguments, continue iterating*/
		for (m = 1; m < 1024; m++)
		{
			array[m] = strtok(NULL, " \t\n");
			if (!array[m])
				break;
		}
		if (check_space(line_buf))
		{
			if (!verify_dir(array[0])) /*Verify if first argument is a directory*/
			{
				full_path = find_command(array[0]); /*Find the full path*/
				if (full_path != NULL) /*If command is found, execute it as subprocess*/
				{
					aux_subprocess(array, full_path);
					free(full_path);
				}
				else /*If not found, print error message*/
				{
					printf("%s: Command not found\n", array[0]);
				}
			}
			else if (verify_dir(array[0]))
			{
				if (verify_status(array[0]))
					subprocess(array);
			}
	}
	}
		return (0);
}
