#include "parser.h"
#include "ft_strings.h"
#include <stdlib.h>
#include <fcntl.h>

static void	init_lut(t_state_parser_fn *lut)
{
	lut[NORMAL] = parser_normal;
	lut[AMBIENT_LIGHTNING] = parser_amb_light;
	lut[CAMERA] = parser_cam;
	lut[LIGHT] = parser_light;
	lut[SPHERE] = parser_sphere;
	lut[PLANE] = parser_plane;
	lut[CYLINDER] = parser_cylinder;
}

static void	init_parser(t_parser *p, char *str)
{
	p->str = str;
	p->index = 0;
	p->state = NORMAL;
}

static int	parser_fsm(char *fb)
{
	t_parser			p;
	t_state_parser_fn	lut[256];
	int					ret_val;

	init_lut(&lut);
	init_parser(&p, fb);
	while (fb[p->index] && !ret_val)
	{
		ret_val = lut[p->state](&p);
		p->index++;
	}
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