#include "parser.h"
#include "setter/set_amb_light.h"

t_p_ret	parse_amb_light(t_parser *p)
{
	float				ratio;
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;

	if (p->is_amb_light)
		return (D_AMB_LIGHT);
	p->index++;
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_ratio(p, &ratio))
		return (RATIO);
	set_amb_light_ratio(p->mrt, ratio);
	while (p->str[p->index] == ' ')
		p->index++;
	if (parse_color(p, &r, &g, &b))
		return (COLOR);
	set_amb_light_color(p->mrt, r, g, b);
	p->is_amb_light = 1;
	return (SUCCESS);
}