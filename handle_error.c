#include "so_long.h"

void	perror_and_exit(char *error_message)
{
	perror(error_message);
	exit(EXIT_FAILURE);
}