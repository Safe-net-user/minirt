#include "parser.h"
#include "ft_strings.h"

int	parse_float(t_parser *p, float *value)
{
	float	result;
	float	div;
	bool	minus;

	minus = p->str[p->index] == '-';
	p->index += minus;
	if (!ft_isdigit(p->str[p->index]))
		return (1);
	result = 0.0f;
	while (ft_isdigit(p->str[p->index]))
	{
		result = result * 10.0f + (p->str[p->index] - '0');
		p->index++;
	}
	if (p->str[p->index] == '.')
	{
		p->index++;
		div = 10.0f;
		while (ft_isdigit(p->str[p->index]))
		{
			result += (p->str[p->index] - '0') / div;
			div *= 10.0f;
			p->index++;
		}
	}
	if (minus)
		*value = -result;
	else
		*value = result;
	return (0);
}

int	parse_uchar(t_parser *p, unsigned int *value)
{
	unsigned int	n;

	if (!ft_isdigit(p->str[p->index]))
		return (1);
	n = 0;
	while (ft_isdigit(p->str[p->index]))
	{
		n = n * 10 + (p->str[p->index] - '0');
		if (n > 255)
			return (1);
		p->index++;
	}
	*value = n;
	return (0);
}
