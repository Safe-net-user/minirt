#include "parser.h"
#include "minirt.h"
#include "ft_strings.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

t_p_ret	handle_parser_error(t_parser *p)
{
	char	*lut_msg[13];

	set_lut_msg(lut_msg);
	printf("Error: %s\n", lut_msg[p->code_status]);
	return (ERROR);
}

static int	parser_fsm(t_mrt *mrt, unsigned char *fb)
{
	t_parser	p;
	t_parser_fn	lut[256];
	int			code_status;

	code_status = 0;
	set_lut(lut);
	set_parser(&p, mrt, fb);
	while (p.str[p.index] && !code_status)
	{
		code_status = lut[p.str[p.index]](&p);
	}
	if (code_status)
	{
		p.code_status = code_status;
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