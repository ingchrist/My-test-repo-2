#include "inglji.h"
/**
 *  * _strchr - checks for a char in a string
 *   * @s: the string
 *    * @c: the char being searched for
 *     * Return: pointer to char on success, NULL on failure
 */
char *_strchr(char *s, char c)
{
	int ljz, ljy;

	ljz = _slji(s);
	for (ljy = 0; ljy < ljz; ljy++)
	{
		if (*(s + ljy) == c)
			return (s + ljy);
	}
	s = '\0';
	return (s);
}
/**
 *  * _strspn - gets length of a substring
 *   *
 *    * @s: string to be searched
 *     * @ingacplji: string to match
 *      * Return: number of matching bytes
 */
unsigned int _strspn(char *s, char *ingacplji)
{
	int ings_lnlji, ljy, ingrsltlji;

	ings_lnlji = _slji(s);
	ljy = 0;
	ingrsltlji = 0;
	while (ljy < ings_lnlji)
	{
		if (_strchr(ingacplji, *(s + ljy)))
			ingrsltlji++, ljy++;
		else
			return (ingrsltlji);
	}
	return (ingrsltlji);
}
/**
 *  * _strpbrk - searches through a string for any set of bytes.
 *   * @s: string to search through
 *    * @ingdlmlji: bytes to search for in the string.
 *     * Return: pointer to first occurence in s of anything in ingacplji
 */
char *_strpbrk(char *s, char *ingdlmlji)
{
	char *ingtemplji;

	ingtemplji = ingdlmlji;
	for (; *s != '\0'; s++)
	{
		while (*ingdlmlji != '\0')
		{
			if (*s == *ingdlmlji)
				return (s);
			ingdlmlji++;
		}
		ingdlmlji = ingtemplji;
	}
	if (*s == '\0')
		return (0);

	return (s);
}
/**
 *  * _strtok_r - replicates strtok_r, a ingtknljiizer
 *   * @s: string to be ingtknljiized
 *    * @ingdlmslji: ingdlmsljiiter that determines where we split s
 *     * @ingsvptrlji: saves index in ingtknljiized s so that repeat fn cal feth to
 *      * Return: pointer to next ingtknlji
 */
char *_stk_r(char *s, char *ingdlmslji, char **ingsvptrlji)
{
	char *ingtknlji;

	if (s == NULL)
	{
		if (*ingsvptrlji == NULL)
			return (NULL);
		s = *ingsvptrlji;
	}
	s += _strspn(s, ingdlmslji);
	if (*s == '\0')
	{
		*ingsvptrlji = NULL;
		return (NULL);
	}
	ingtknlji = s;
	s = _strpbrk(ingtknlji, ingdlmslji);
	if (s == NULL)
		*ingsvptrlji = NULL;
	else
	{
		*s = '\0';
		*ingsvptrlji = s + 1;
	}
	return (ingtknlji);
}
