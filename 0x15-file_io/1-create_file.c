#include "main.h"

/**
 * create_file - create_file
 * @filename : @filename
 * @text_content : @text_content
 * Description:description
 * Return:return
 */

int create_file(const char *filename, char *text_content)
{
int fd;
ssize_t bytes = 0, text_len = strlen(text_content);

if (!filename)
{
return (-1);
}

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

if (fd == -1)
{
return (-1);
}

if (text_len)
{
bytes = write(fd, text_content, text_len);
}

close(fd);

return (bytes == text_len ? 1 : -1);
}
