#include "parser.h"
#include "minirt.h"
#include "ft_strings.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	handle_parser_error(t_parser *p)
{
	(void)p;
	printf("Error\n");
	return (0);
}

static int	parser_fsm(t_mrt *mrt, unsigned char *fb)
{
	t_parser	p;
	t_parser_fn	lut[256];
	int			ret_val;

	ret_val = 0;
	set_lut(lut);
	set_parser(&p, mrt, fb);
	while (p.str[p.index] && !ret_val)
	{
		ret_val = lut[p.str[p.index]](&p);
	}
	if (ret_val)
	{
		handle_parser_error(&p);
		return (1);
	}
	return (0);
}

int parser(t_mrt *mrt, char *path)
{
	char    *file_bytes;
	size_t  capacity;
	size_t  len;
	ssize_t br;
	int     fd;
	int     ret;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	capacity = 65536;
	len = 0;
	file_bytes = malloc(capacity + 1);
	if (!file_bytes)
	{
		close(fd);
		return (1);
	}
	while (1)
	{
		if (len == capacity)
		{
			capacity *= 2;
			file_bytes = realloc(file_bytes, capacity + 1);
			if (!file_bytes)
			{
				close(fd);
				return (1);
			}
		}
		br = read(fd, file_bytes + len, capacity - len);
		if (br < 0)
		{
			free(file_bytes);
			close(fd);
			return (1);
		}
		if (br == 0)
			break;
		len += br;
	}
	file_bytes[len] = '\0';
	ret = parser_fsm(mrt, (unsigned char *)file_bytes);
	free(file_bytes);
	close(fd);
	return (ret);
}