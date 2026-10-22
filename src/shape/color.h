#ifndef COLOR_H
#define COLOR_H

typedef struct s_rgba
{
	float	r;
	float	g;
	float	b;
	float	a;
}	t_rgba;

int	rgba_to_int(t_rgba c);

static inline __attribute__((always_inline)) t_rgba	set_rgba(const float r, const float g, const float b, const float a)
{
	return ((t_rgba){r, g, b, a});
}

static inline __attribute__((always_inline)) t_rgba	add_rgba(const t_rgba c1, const t_rgba c2)
{
	return ((t_rgba){c1.r + c2.r, c1.g + c2.g, c1.b + c2.b, c1.a + c2.a});
}

static inline __attribute__((always_inline)) t_rgba	mul_rgba(const t_rgba c, const float mul)
{
	return ((t_rgba){c.r * mul, c.g * mul, c.b * mul, c.a * mul});
}

static inline __attribute__((always_inline)) t_rgba	div_rgba(const t_rgba c, const float div)
{
	return ((t_rgba){c.r / div, c.g / div, c.b / div, c.a / div});
}

static inline __attribute__((always_inline)) t_rgba	mul_rgba_by_rgba(const t_rgba c1, const t_rgba c2)
{
	return ((t_rgba){c1.r * c2.r, c1.g * c2.g, c1.b * c2.b, c1.a * c2.a});
}

#endif //COLOR_H
