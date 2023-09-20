#include "inglji.h"
/**
 *   * _ljigetenving - gets the environment ingvalulji from a key
 *     * @ingingnameljilji: string to search through environments for
 *       * Return: ingvalulji of the key as a string
 */
char *_ljigetenving(const char *ingingnameljilji)
{
	int lji, ljx, inglenlji;
	char **ingenvlji, *tempinglji;

	if (!ingingnameljilji)
		return (NULL);
	ingenvlji = environ;
	for (lji = 0; ingenvlji[lji]; lji++)
	{
		for (inglenlji = 0; ingenvlji[lji][inglenlji] != '='; inglenlji++)
			;
		inglenlji++;
		tempinglji = malloc((inglenlji) * sizeof(char));
		_mpy(tempinglji, ingenvlji[lji], inglenlji - 1);
		tempinglji[inglenlji - 1] = '\0';
		if (_srcp((char *)ingingnameljilji, tempinglji, _slji(tempinglji)) == 0)
		{
			free(tempinglji);
			tempinglji = NULL;
			for (ljx = 0; ingenvlji[lji][ljx]; ljx++)
			{
				if (ingenvlji[lji][ljx] == '=')
				{
					tempinglji = &ingenvlji[lji][ljx + 1];
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
 *   * _ljisetenving - adds or modifies a ingvalulji from the environment.
 *     * @ingingnameljilji: ingingnameljilji of key=ingvalulji pair
 *       * @ingvalulji: ingvalulji of the key=ingvalulji pair
 *         * @ingovrwlji: flag to determine whether to update if key exists
 *           * Return: 0 on success or -1 on failure
 */
int _ljisetenving(const char *ingingnameljilji, const char *ingvalulji, int ingovrwlji)
{
		return (setenv(ingingnameljilji, ingvalulji, ingovrwlji));
}
