/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:25:40 by jostraye          #+#    #+#             */
/*   Updated: 2018/01/14 14:13:52 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	int		i;
	t_env	copy[TH_NB];

	i = 0;
	mlx_destroy_image(e->mlx, e->img);
	mlx_clear_window(e->mlx, e->win);
	e = initialize_image(e);
	while (i < TH_NB)
	{
		copy[i] = *e;
		copy[i].thread_int = i;
		pthread_create(&e->pth[i], NULL, create_image, &copy[i]);
		i++;
	}
	while (i--)
		pthread_join(e->pth[i], NULL);
	send_image_to_window(e);
	return (0);
}

int		mouse_click_hook(int k, int x, int y, t_env *e)
{
	if (k == 1)
	{
		e->x_offset -= ((double)(SIZE / 2 - x) / SIZE) / e->zoom_param;
		e->y_offset -= ((double)(SIZE / 2 - y) / SIZE) / e->zoom_param;
	}
	if (k == 2)
	{
		e->x_offset += ((double)(SIZE / 2 - x) / SIZE) / e->zoom_param;
		e->y_offset += ((double)(SIZE / 2 - y) / SIZE) / e->zoom_param;
	}
	if (k == 4)
	{
		e->zoom_param *= 1.2;
		e->x_offset -= (double)(SIZE / 2 - x) / ((4 * e->zoom_param)
			* SIZE + SIZE * e->zoom_param);
		e->y_offset -= (double)(SIZE / 2 - y) / ((4 * e->zoom_param)
			* SIZE + SIZE * e->zoom_param);
	}
	if (k == 5)
	{
		e->zoom_param /= 1.2;
		e->x_offset += (double)(SIZE / 2 - x) / ((4 * e->zoom_param)
			* SIZE + SIZE * e->zoom_param);
		e->y_offset += (double)(SIZE / 2 - y) / ((4 * e->zoom_param)
			* SIZE + SIZE * e->zoom_param);
	}
	expose_hook(e);
	return (0);
}

int		mouse_pos(int x, int y, t_env *e)
{
	e->xj = 2 * ((double)SIZE / 2 - x) / SIZE;
	e->yj = 2 * ((double)SIZE / 2 - y) / SIZE;
	expose_hook(e);
	return (0);
}

void	keyboard_hooks2(int key_code, t_env *e)
{
	if (key_code == 8 && e->clr_set == 3)
		e->clr_set = 1;
	else if (key_code == 8 && e->clr_set < 3)
		e->clr_set++;
	if (key_code == 83 || key_code == 18)
		e->argument = 1;
	if (key_code == 84 || key_code == 19)
		e->argument = 2;
	if (key_code == 85 || key_code == 20)
		e->argument = 3;
	if (key_code == 86 || key_code == 21)
		e->argument = 4;
	if (key_code == 87 || key_code == 23)
		e->argument = 5;
	if (key_code == 88 || key_code == 22)
		e->argument = 6;
	if (key_code == 89 || key_code == 26)
		e->argument = 7;
	if (key_code == 15)
		e = reset_environment(e);
	expose_hook(e);
}

int		keyboard_hooks(int key_code, t_env *e)
{
	if (key_code == 53)
		exit(0);
	if (key_code != 53)
	{
		if (key_code == 123)
			e->x_offset -= 0.1 / e->zoom_param;
		if (key_code == 126)
			e->y_offset -= 0.1 / e->zoom_param;
		if (key_code == 124)
			e->x_offset += 0.1 / e->zoom_param;
		if (key_code == 125)
			e->y_offset += 0.1 / e->zoom_param;
		if (key_code == 69 || key_code == 24)
			e->zoom_param *= 1.05;
		if (key_code == 78 || key_code == 27)
			e->zoom_param /= 1.05;
		if (key_code == 67 || key_code == 35)
			e->max_it++;
		if (key_code == 75 || key_code == 31)
			e->max_it--;
		keyboard_hooks2(key_code, e);
	}
	return (0);
}
