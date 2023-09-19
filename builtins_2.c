#include "shell.h"
/**
 *  *   * _setenv_usr - sets environmental variables as user defines
 *   *     * @twokenzing: KEY=VALUE pair
 *    *       * Return: 0 on success, -1 on failure
 */
int _setenv_usr(char **twokenzing)
{
	int i, wz, wzq;
	char *ingkeylji, *ingvalji, *ingsavlji;

	for (i = 0, wzq = 1; twokenzing[1][i]; i++)
		if (twokenzing[1][i] == '=')
			wzq++;
	for (i = 0; twokenzing[i]; i++)
		;
	if (!twokenzing[1] || i == 0 || wzq != 2)
	{
		inglji_print("setenv: Usage: setenv KEY=VALUE\n");
		return (-1);
	}
	ingkeylji = _strtok_r(twokenzing[1], "=", &ingsavlji);
	ingvalji = _strtok_r(NULL, "=", &ingsavlji);
	wz = _setenv(ingkeylji, ingvalji, 0);
	if (wz == 0)
		return (wz);
	return (-1);
}
/**
 *  *   * _alias - sets aliases or prints them out when no options are supplied
 *   *     * Return: 0
 */
int _alias(void)
{
	inglji_print("alias: usage: alias [-p] [name[=ingvalji] ... ]\n");
	inglji_print("\tSet or view aliases.\n\tSet with name=ingvalji\n");
	inglji_print("\tView list of aliases with no arugments or -p\n");
	return (0);
}
/**
 *  *   * _history - prints out history with no options,
 *   *     *  or clears history with -c
 *    *       * Return: 0 on success, 1 if history cannot be cleared.
 */
int _history(void)
{
	inglji_print("history: usage: history [-c]\n");
	inglji_print("\tView the history of commands\n ");
	inglji_print("\t'history -c' clears the history\n");
	return (0);
}
/**
 *  *   * bowie - easter egg. Displays ASCII picture of Bowie
 *   *     * Return: 1947, the year Bowie was born
 */
int bowie(void)
{
	int ljitxting, ljitoting, ljirding;
	size_t ljileting = 7483;
	char *ljinming = "bowie.txt";
	char ingbuflji[BUFSIZE];

	if (ljinming == NULL)
		return (0);
	ljitxting = open(ljinming, O_RDONLY);
	if (ljitxting == -1)
		return (0);
	ljitoting = 0;
	ljirding = 1;
	while (ljileting > BUFSIZE && ljirding != 0)
	{
		ljirding = read(ljitxting, ingbuflji, BUFSIZE);
		write(STDOUT_FILENO, ingbuflji, ljirding);
		ljitoting += ljirding;
		ljileting -= BUFSIZE;
																									}
	ljirding = read(ljitxting, ingbuflji, ljileting);
	write(STDOUT_FILENO, ingbuflji, ljirding);
	ljitoting += ljirding;
	close(ljitxting);
	return (1947);
	/**	return (ljitoting); */
}
