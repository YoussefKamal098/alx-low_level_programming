#include "main.h"

/**
 * skip_spaces - skip_spaces
 * @str :str
 * Return: return
 */

char *skip_spaces(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * skip_characters - skip_characters
 * @str :str
 * Return: return
 */

char *skip_characters(char *str)
{
	while (*str != ' ' && *str != '\0')
		str++;
	return (str);
}

/**
 * get_words_number - get_words_number
 * @str :str
 * Return: return
 */

int get_words_number(char *str)
{
	char *curr_ch;
	int words = 0, found_word = 1;

	for (curr_ch = str; *curr_ch != '\0'; curr_ch++)
	{
		if (*curr_ch != ' ' && found_word)
		{
			words += 1;
			found_word = 0;
		}
		else if (*curr_ch == ' ')
		{
			curr_ch = skip_spaces(curr_ch) - 1;
			found_word = 1;
		}
	}
	return (words);
}

/**
 * get_word - get_word
 * @str :str
 * Return: return
 */

char *get_word(char *str)
{
	int i, word_len = 0;
	char *word;

	for (i = 0; str[i] != ' ' && str[i] != '\0'; i++)
		word_len++;
	word = (char *)malloc(word_len + 1);

	if (word == NULL)
		return (NULL);
	for (i = 0; str[i] != ' ' && str[i] != '\0'; i++)
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

/**
 * strtow - strtow
 * @str :str
 * Return: return
 */

char **strtow(char *str)
{
	char **words;
	char *curr_ch;
	int i = 0, words_number = 0;

	if (str == NULL || *str == '\0')
		return (NULL);
	words_number = get_words_number(str) + 1;
	if (words_number == 1)
		return (NULL);

	words = (char **)malloc(sizeof(char *) * words_number);

	if (words == NULL)
		return (NULL);
	for (curr_ch = str; *curr_ch != '\0'; curr_ch++)
	{
		if (*curr_ch != ' ')
		{
			words[i] = get_word(curr_ch);
			curr_ch = skip_characters(curr_ch);
			curr_ch--;
			i++;
		}
	}
	words[i] = NULL;
	return (words);
}
