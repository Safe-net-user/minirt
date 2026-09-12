#include "parser.h"
#include "ft_strings.h"

int	parse_float(t_parser *p, float *value)
{
	unsigned	int	n;
	unsigned	int	dec;
	size_t			i;
	bool			minus;

	i = p->index;
	minus = p->str[i] == '-';
	i += minus;
	if (!parser_isdigit(p->str[i]))
		return (1);
	n = 0;
	dec = 0;
	while (parser_isdigit(p->str[i]))
	{
		n = n * 10 + (p->str[i] - '0');
		i++;
	}
	if (p->str[i] == '.')
	{
		i++;
		while (parser_isdigit(p->str[i]))
		{
			n = n * 10 + (p->str[i] - '0');
			dec++;
			i++;
		}
	}
	if (dec == 0)
		*value = (float)n;
	else if (dec == 1)
		*value = (float)n * 0.1f;
	else
		*value = (float)n * 0.01f;
	if (minus)
		*value = -*value;
	p->index = i;
	return (0);
}

int	parse_uchar(t_parser *p, unsigned int *value)
{
	unsigned int	n;
	unsigned int	digits;

	if (!parser_isdigit(p->str[p->index]))
		return (1);
	n = 0;
	digits = 0;
	while (digits < 3 && parser_isdigit(p->str[p->index]))
	{
		n = n * 10 + (p->str[p->index] - '0');
		digits++;
		p->index++;
	}
	if (n > 255)
		return (1);
	*value = n;
	return (0);
}
