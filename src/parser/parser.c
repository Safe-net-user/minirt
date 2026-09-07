#include "parser.h"
#include "ft_strings.h"
#include <stdlib.h>
#include <fcntl.h>

int	parser_fsm(char *fb)
{
	t_parser			*p;
	t_state_parser_fn	lut;
	int					ret_val;

	init_lut(&lut);
	if (init_parser(fb))
		return (1);
	while (fb[p->index] && !ret_val)
	{
		ret_val = lut[fb[p->index]](p);
		p->index++;
	}
	free(p);
	if (ret_val)
		return (1);
	return (0);
}

int	parser(char *path)
{
	char	buff[BUFFER_SIZE + 1];
	char	*file_bytes;
	int		br;

	fd = open(path);
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
		br = read(fd, buffer, BUFFER_SIZE);
		if (br == -1)
		{
			close(fd);
			return (1);
		}
	}
	return (parser_fsm(file_bytes), free(file_bytes));
}