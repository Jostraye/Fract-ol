/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:03:28 by jostraye          #+#    #+#             */
/*   Updated: 2018/01/14 14:00:44 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*reset_environment(t_env *e)
{
	e->zoom_param = 0.5;
	e->x = -(SIZE) / 2;
	e->y = -(SIZE) / 2;
	e->yj = SIZE;
	e->xj = SIZE;
	e->x_offset = 0;
	e->y_offset = 0;
	e->max_it = 17;
	e->clr_set = 1;
	return (e);
}

t_env	*initialize_win(t_env *e)
{
	e = reset_environment(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, SIZE, SIZE, "MY GRAPH");
	e->img = mlx_new_image(e->mlx, SIZE, SIZE);
	return (e);
}

void	run_win(t_env *e)
{
	e = initialize_win(e);
	mlx_key_hook(e->win, keyboard_hooks, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse_click_hook, e);
	mlx_hook(e->win, 6, 0, mouse_pos, e);
	mlx_loop(e->mlx);
}

int		main(int ac, char **av)
{
	t_env *e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (ac == 1)
	{
		e->argument = 1;
		run_win(e);
	}
	if (ac > 2)
		print_error(1);
	else if (error_condition(av[1]))
		print_error(2);
	else
	{
		e->argument = atoi(av[1]);
		run_win(e);
	}
	return (0);
}
