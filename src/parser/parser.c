#include "parser.h"
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

static int	parser_fsm(unsigned char *fb)
{
	t_parser	p;
	t_parser_fn	lut[256];
	int			ret_val;

	ret_val = 0;
	set_lut(lut);
	set_parser(&p, fb);
	while (p.str[p.index] && !ret_val)
	{
		ret_val = lut[p.str[p.index]](&p);
		p.index++;
	}
	if (ret_val)
	{
		handle_parser_error(&p);
		return (1);
	}
	return (0);
}

int	parser(char *path)
{
	char	buff[BUFFER_SIZE + 1];
	char	*file_bytes;
	int		br;
	int		fd;
	int		ret_val;

	fd = open(path, 0);
	file_bytes = NULL;
	if (fd < 0)
		return (1);
	br = read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	if (br == -1)
	{
		close(fd);
		return (1);
	}
	while (br > 0)
	{
		file_bytes = ft_strjoin_free(file_bytes, buff, 1);
		br = read(fd, buff, BUFFER_SIZE);
		if (br == -1)
		{
			close(fd);
			return (1);
		}
	}
	ret_val = parser_fsm((unsigned char *)file_bytes);
	free(file_bytes);
	return (ret_val);
}