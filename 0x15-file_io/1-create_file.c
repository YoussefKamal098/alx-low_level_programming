#include "main.h"

/**
 * _strlen - length of string
 * @str: string
 * Return: length of string
 */

size_t _strlen(char *str)
{
	size_t i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	while (str[i])
		i++;

	return (i);
}

/**
 * create_file - create_file
 * @filename:  filename
 * @text_content: text_content
 * Return:return
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes = 0, text_len;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	text_len = _strlen(text_content);
	if (text_len)
		bytes = write(fd, text_content, text_len);

	close(fd);

	return (bytes == text_len ? 1 : -1);
}
