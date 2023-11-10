#include "_shell.h"
/**
 * _tokenize_command-tokenize command
 * @_command: pointer to a const char (input command)
 * like ls -l /tmp
 * @str: array of pointers to strings where the
 * extracted words from the input command will be stored
 * Return: void
 */
void _tokenize_command(const char *_command, char **str)
{
	int Q = 0, R;
	char *_copy_command = strdup(_command);
	char *_token = strtok(_copy_command, " \t\n\r");
	char *_command_name;

	while (_token != NULL && MAXIMUM_ARGUMENTS > Q)
	{
		str[Q++] = strdup(_token);
		_token = strtok(NULL, " \t\n\r");
	}
	str[Q] = NULL;
	if (Q > 0 && strchr(str[0], '/'))
	{
		_command_name = strrchr(str[0], '/');
		if (_command_name != NULL)
		{
			_command_name++;
			free(str[0]);
			str[0] = strdup(_command_name);
		}
	}
	printf("Debug: Contents of the str array:\n");
	for (R = 0; str[R] != NULL; R++)
	{
		printf("[%d]: %s\n", R, str[R]);
	}
	free(_copy_command);
}
