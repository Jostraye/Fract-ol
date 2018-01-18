/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 10:17:55 by jostraye          #+#    #+#             */
/*   Updated: 2018/01/14 20:25:00 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	text_to_image(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 40, 40, CLR, "Controls Keys");
	mlx_string_put(e->mlx, e->win, 35, 100, CLR, "Zoom in&out '+' & '-'");
	mlx_string_put(e->mlx, e->win, 35, 120, CLR, "Zoom in&out: mouse wheel");
	mlx_string_put(e->mlx, e->win, 35, 60, CLR, "Move around: arrow keys");
	mlx_string_put(e->mlx, e->win, 35, 80, CLR, "Sharpness '*' & '/'");
	mlx_string_put(e->mlx, e->win, 35, 140, CLR, "Change color palette 'C'");
	mlx_string_put(e->mlx, e->win, 35, 165, CLR, "Exit window 'esc'");
	mlx_string_put(e->mlx, e->win, 35, 185, CLR, "Reset image 'R'");
	mlx_string_put(e->mlx, e->win, 40, (WIN_H - 180), CLR, "Change Fractal");
	mlx_string_put(e->mlx, e->win, 35, (WIN_H - 160), CLR, "'1': Mandelbrot");
	mlx_string_put(e->mlx, e->win, 35, (WIN_H - 140), CLR, "'2': Julia");
	mlx_string_put(e->mlx, e->win, 35, (WIN_H - 120), CLR, "'3': Tricorn");
	mlx_string_put(e->mlx, e->win, 35, (WIN_H - 100), CLR, "'4': Dentelle");
	mlx_string_put(e->mlx, e->win, 35, (WIN_H - 80), CLR, "'5': Chicken");
	mlx_string_put(e->mlx, e->win, 35, (WIN_H - 60), CLR, "'6': Burning Ship");
	mlx_string_put(e->mlx, e->win, 35, (WIN_H - 40), CLR, "'7': Bear on Lake");
}

t_env	*initialize_image(t_env *e)
{
	e->img = mlx_new_image(e->mlx, SIZE, SIZE);
	e->data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->ls, &e->endian);
	e->ls /= 4;
	return (e);
}

void	send_image_to_window(t_env *e)
{
	int i;

	i = 0;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	while (e->data[i])
	{
		e->data[i] = 0;
	}
	e->data = NULL;
	text_to_image(e);
}

void	*create_image(void *arg)
{
	t_env *e;

	e = (t_env *)arg;
	point_iteration(e);
	return (NULL);
}
