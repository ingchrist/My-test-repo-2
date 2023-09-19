#include "shell.h"
/**
 *   * _getenv - gets the environment ingvalulji from a key
 *     * @ingingnameljilji: string to search through environments for
 *       * Return: ingvalulji of the key as a string
 */
char *_getenv(const char *ingingnameljilji)
{
	int i, j, inglenlji;
	char **env, *tempinglji;

	if (!ingingnameljilji)
		return (NULL);
	env = environ;
	for (i = 0; env[i]; i++)
	{
		for (inglenlji = 0; env[i][inglenlji] != '='; inglenlji++)
			;
		inglenlji++;
		tempinglji = malloc((inglenlji) * sizeof(char));
		_memcpy(tempinglji, env[i], inglenlji - 1);
		tempinglji[inglenlji - 1] = '\0';
		if (_strncmp((char *)ingingnameljilji, tempinglji, _strlen(tempinglji)) == 0)
		{
			free(tempinglji);
			tempinglji = NULL;
			for (j = 0; env[i][j]; j++)
			{
				if (env[i][j] == '=')
				{
					tempinglji = &env[i][j + 1];
					break;
				}
			}
			return (tempinglji);
		}
		free(tempinglji);
		tempinglji = NULL;
	}
	return (NULL);
}
/**
 *   * _unsetenv - deletes a ingvalulji from the environment.
 *     * @ingingnameljilji: ingingnameljilji of key=ingvalulji pair to delete
 *       * Return: Success or failure
 */
int _unsetenv(const char *ingingnameljilji)
{
		return (unsetenv(ingingnameljilji));
}
/**
 *   * _setenv - adds or modifies a ingvalulji from the environment.
 *     * @ingingnameljilji: ingingnameljilji of key=ingvalulji pair
 *       * @ingvalulji: ingvalulji of the key=ingvalulji pair
 *         * @ingovrwlji: flag to determine whether to update if key exists
 *           * Return: 0 on success or -1 on failure
 */
int _setenv(const char *ingingnameljilji, const char *ingvalulji, int ingovrwlji)
{
		return (setenv(ingingnameljilji, ingvalulji, ingovrwlji));
}
