#include "main.h"
/**
 * verify_status - Function that verify the file status
 * @filename: pointer to string
 * Return: 1 or 0
 */
int verify_status(char *filename)
{
	struct stat filestat;

	if (stat(filename, &filestat) == 0)
		return (1);

	printf("No such file or directory\n");
	return (0);
}

/**
 * verify_dir - Function that check if string contains a directory path
 * @str: string to check
 * Return: 1 or 0
 */
int verify_dir(char *str)
{
	int m = 0;

	for (m = 0; str[m]; m++)
	{
		if (str[m] == '/')
			return (1);
	}
	return (0);
}

/**
 * func_getenv - Function that get the value of an environment varible
 * @name: name of the variable
 * Return: pointer to a sting
 */
char *func_getenv(const char *name)
{
	int m, l, env_var_len = 0;
	char *env_var;

	while (name[env_var_len] != '\0')
		env_var_len++;
	for (m = 0; environ[m] != NULL; m++)
	{
		for (l = 0; l < env_var_len; l++)
		{
			if (name[l] != environ[m][l])
				break;
		}
		if (l == env_var_len && environ[m][l] == '=')
		{
			env_var = environ[m] + l + 1;
			return (env_var);
		}
	}
	return (NULL);
}

/**
 * aux_subprocess - function that creates another process
 * @argv: Line command content
 * @path: Path
 * Return: 0 or -1
 */
int aux_subprocess(char **argv, char *path, char **environ)
{
	pid_t id;
	int cond = 0;

		id = fork();
		if (id == -1)
			return (-1);
		if (id == 0)
			execve(path, argv, environ);
		else
			wait(&cond);

		return (0);
}

/**
* find_command - function that create the full path
* @command: Pointer to char.
* Return: NULL
*/

char *find_command(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir;
	char *full_path;

	struct stat sb;

	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		if (dir != NULL)
			full_path = malloc(strlen(dir) + strlen(command) + 2);

		sprintf(full_path, "%s/%s", dir, command);

		if (stat(full_path, &sb) == 0 && sb.st_mode & S_IXUSR)
		{
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
		}
		return (NULL);
}
