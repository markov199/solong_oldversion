/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:48:27 by mkovoor           #+#    #+#             */
/*   Updated: 2022/09/14 14:51:37 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include<stdlib.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
} t_data;

int get_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 |blue);
}

// int render(t_data *data)
// {

// }

int key_hook(int keycode, t_data *data)
{
	static int	x;
	static int	y;
	x =+500;
	y = 500;
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 200, "key pressed");
	
	if(keycode == 53)
	{
		
	}
	return (0);
}

int	main(void)
{
	t_data	data;
	int		width;
	int		height;
	char	*name;
	int		colour;

	height = 50;
	colour = 0;
	width = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1080, 1920, "mywindow");
	while(height++ < 100)
	{	width = 0;
		while (width++ < 500)
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, width, height, colour);
		colour += 160;
	}
	mlx_key_hook(data.win_ptr,&key_hook, &data);
	mlx_loop(data.mlx_ptr);	
	// mlx_loop_hook(data.mlx_ptr, &render, &data);
}
