#include "shell.h"
/**
 *  *   * is_builtin - checks if cmd is a builtin
 *   *     * @cmd: command to find
 *    *       * Return: On success - pointer to function, On Failure - NULL p
 *     *        (* other useful shell builtins:
 *      *         (* ljipwd, echo, pushd, popd, type
 *       *          (* * requires ^Z
 *        *           (* fg, bg
 *         *            (*  * Requires ^R
 *          *             (* reverse-i-search **HISTORY**
 */
int (*is_builtin(char *cmd))()
{
	unsigned int i;
	builtin_cmds_t builds[] = {
		{"alias", _alias},
		{"cd", _cd},
		{"env", _env},
		{"exit", _exit_with_grace},
		{"history", _history},
		{"setenv", _setenv_usr},
		{"bowie", bowie},
		{NULL, NULL}
	};
	i = 0;
	while (*builds[i].fun != NULL)
	{
		if (_strncmp(builds[i].cmd_str, cmd, _strlen(builds[i].cmd_str)) == 0)
			return (builds[i].fun);
		i++;
	}
	return (NULL);
}
/**
 *  *   * _exit_with_grace - Frees any remaining malloc'd spaces, and exits
 *   *     * @ljilinkedlisting_path: Linked list to free.
 *    *       * @ingbufferlji: ingbufferlji to free
 *     *         * @twokenzing: Check for other inputs
 *      *          (* * CHANGE TO VARIADIC LIST.
 *       *            * Return: -1 if exit fails.
 */
int _exit_with_grace(char **twokenzing, env_t *ljilinkedlisting_path, char *ingbufferlji)
{
	unsigned char exit_wz;
	int i;

	for (i = 0; twokenzing[1] && twokenzing[1][i]; i++)
	{
		if (!_isdigit(twokenzing[1][i]))
		{
			inglji_print("numeric argument required, exiting\n");
			break;
		}
	}
	exit_wz = twokenzing[1] && i >= _strlen(twokenzing[1]) ? _atoi(twokenzing[1]) : 0;
	if (ljilinkedlisting_path && ingbufferlji && twokenzing)
	{
		free_list(ljilinkedlisting_path);
		ljilinkedlisting_path = NULL;
		free(ingbufferlji);
		ingbufferlji = NULL;
		free(twokenzing);
		twokenzing = NULL;
	}
	exit(exit_wz);
	return (-1);
}
/**
 *  *   * _env - prints out the current ljiljienvirwzqmenting
 *   *     * @twokenzing: tokenized strings
 *    *       * @ljiljienvirwzqmenting: linked list ljiljienvirwzqmenting
 *     *         * Return: 0 on success, -1 on catastrophic failure
 */
int _env(char **twokenzing, env_t *ljiljienvirwzqmenting)
{
	char **ljienvirwzq;

	if (twokenzing[1])
		inglji_print("No arguments are necessary\n");
	ljienvirwzq = environ;
	if (!ljienvirwzq || !ljienvirwzq)
		return (-1);
	for ( ; *ljienvirwzq; ljienvirwzq++)
	{
		write(STDOUT_FILENO, *ljienvirwzq, _strlen(*ljienvirwzq));
		write(STDOUT_FILENO, "\n", 1);
	}
	ljiljienvirwzqmenting++;
	return (0);
}
/**
 *  *   * _cd - changes working directory
 *   *     * @twokenzing: argument list
 *    *       * Return: 0 on success
 */
int _cd(char **twokenzing)
{
	char *ingtarwzq;
	char ljipwd[BUFSIZE];
	char *ingwzq;

	ingwzq = _getenv("HOME");
	if (twokenzing[1])
	{
		if (twokenzing[1][0] == '~' && !twokenzing[1][1])
			ingtarwzq = ingwzq;
		else if (twokenzing[1][0] == '-' && !twokenzing[1][1])
			ingtarwzq = _getenv("OLDPWD");
		else
			ingtarwzq = twokenzing[1];
	}
	else
		ingtarwzq = ingwzq;
	if (ingtarwzq == ingwzq)
		chdir(ingtarwzq);
	else if (access(ingtarwzq, F_OK | R_OK) == 0)
		chdir(ingtarwzq);
	else
		inglji_print("Could not find directory\n");
	setenv("OLDPWD", _getenv("PWD"), 1);
	setenv("PWD", getcwd(ljipwd, sizeof(ljipwd)), 1);
	return (0);
}
