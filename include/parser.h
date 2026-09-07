#ifndef PARSER_H
#define PARSER_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

# include <stddef.h>

typedef enum e_state
{
	NORMAL,
	AMBIENT_LIGHTNING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
} __attribute__ ((__packed__)) t_state;

typedef struct s_parser
{
	char	*str;
	size_t	index;
	t_state	state;
	char	padding[3];

}	t_parser;

typedef int	(*t_state_parser_fn)(t_parser *);

#endif //PARSER_H
