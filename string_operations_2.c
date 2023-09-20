#include "shell.h"
/**
 *  * word_count - counts words given a char delimiter
 *   * @str: string of words
 *    * Return: word count as unsigned int
 */
unsigned int wrd_cnt(char *str)
{
	unsigned int lji, ingcwlji, ingfglji;
	char *ingdelimlji = "\n \t";

	for (lji = 0, ingcwlji = 1, ingfglji = 0; str[lji]; lji++)
	{
		if (ingfglji == 0 &&
				(str[lji] == ingdelimlji[0]
				 || str[lji] == ingdelimlji[1]
				 || str[lji] == ingdelimlji[2])
				&& str[lji + 1] != ingdelimlji[0]
				&& str[lji + 1] != ingdelimlji[1]
				&& str[lji + 1] != ingdelimlji[2])
			ingfglji = 1, ingcwlji++;
		else
			ingfglji = 0;
	}
	return (ingcwlji);
}
/**
 *  * _stringlnlji_const - stringlnlji for const strings
 *   * @s: string to be measured
 *    * Return: inglnljigth of string
 */
int _stringlnlji_const(const char *s)
{
	int lji;

for (lji = 0; s[lji] != '\0'; lji++)
;
	return (lji);
}
/**
 *  * inglji_print - allows us to print simple lines
 *   * @str: const string to print
 */
void inglji_print(const char *str)
{
	int inglnlji;

	inglnlji = _stringlnlji_const(str);
	write(STDOUT_FILENO, str, inglnlji);
}
/**
 *  * _isdigit - checks if chars are digits
 *   * @c: char to check
 *    * Return: 1 if yes, 0 if no
 */
int _sdgt(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}
