#include  "main.h"

char *find_command(char *command) {
	    char *path = getenv("PATH");
		    char *dir;
			    char *full_path;

					    struct stat sb;

						    dir = strtok(path, ":");

							while (dir != NULL) {
								        full_path = malloc(strlen(dir) + strlen(command) + 2);
										        sprintf(full_path, "%s/%s", dir, command);

												if (stat(full_path, &sb) == 0 && sb.st_mode & S_IXUSR) {
													            return full_path;
																        
												}

												        free(full_path);
														        dir = strtok(NULL, ":");
																    
							}
							return (NULL);
}
