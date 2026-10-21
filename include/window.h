#ifndef WINDOW_H
#define WINDOW_H

# define ESC_KEY 65307

# include "minirt.h"

typedef struct s_canva
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*data;
	int		w;
	int		h;
}	t_canva;

int	free_mlx_mrt(t_mrt *mrt);
int	key_hook(int keycode, void *param);

#endif //WINDOW_H
