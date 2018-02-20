/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fracting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:53:40 by jostraye          #+#    #+#             */
/*   Updated: 2018/01/14 16:07:47 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				attribute_color(double distance, int clr_set)
{
	unsigned int result;

	if (clr_set == 1)
		result = plastic_palette(distance);
	if (clr_set == 2)
		result = space_palette(distance);
	if (clr_set == 3)
		result = herbal_palette(distance);
	return (result);
}

t_complex	fract_iter(int arg,	t_complex z, t_env *e)
{
	t_complex c;
	t_complex x;
	if (e->i < e->xj)
		c.re = ((e->i + e->x) / (SIZE * e->zoom_param) + e->x_offset) ;
	else
		c.re = ((e->i + e->x) / (SIZE * e->zoom_param) + e->x_offset) ;
	if (e->i < e->xj)
		c.im = ((e->j + e->y) / (SIZE * e->zoom_param) + e->y_offset) ;
	else
	 	c.im= ((e->j + e->y) / (SIZE * e->zoom_param) + e->y_offset) ;
	if (arg == 3 || arg == 7)
		z.im = - z.im;
	if (arg == 4 || arg == 7 || arg == 6)
		z.re = fabs(z.re);
	if (arg == 5 || arg == 6)
		z.im = fabs(z.im);
	x = c_add(c_mult(z, z), c);
	return (x);
}

void			mobl_fract(t_env *e)
{
	int				i;
	t_complex	c;

	i = 0;
	e->z.re = (e->i + e->x) / (SIZE * e->zoom_param) + e->x_offset;
	e->z.im = (e->j + e->y) / (SIZE * e->zoom_param) + e->y_offset;
	c.re = e->xj;
	c.im = e->yj;
	while (i++ < e->max_it)
		e->z = c_add(c_mult(e->z, e->z), c);
	e->z1 = c_add(c_mult(e->z, e->z), c);
	e->z2 = c_add(c_mult(e->z1, e->z1), c);
	e->data[((int)e->j * SIZE + (int)e->i)] =
		attribute_color(c_abs(c_sub(point_delta(e->z1, e->z2), point_delta(e->z, e->z1))), e->clr_set);
}

void			stat_fract(t_env *e)
{
	int				i;
	t_complex	z;
	t_complex	z1;
	t_complex	z2;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i++ < e->max_it)
		z = fract_iter(e->argument, z, e);
	z1 = fract_iter(e->argument, z, e);
	z2 = fract_iter(e->argument, z1, e);
	e->data[((int)e->j * SIZE + (int)e->i)] =
		attribute_color(c_abs(c_sub(point_delta(z1, z2), point_delta(z, z1))), e->clr_set);
}

void			point_iteration(t_env *e)
{
	e->i = 0;
	e->j = (e->thread_int) * SIZE / TH_NB;
	while (e->j < (((e->thread_int + 1) * SIZE) / TH_NB))
	{
		while (e->i++ < SIZE)
		{
			if (e->argument == 2)
				mobl_fract(e);
			else
				stat_fract(e);
		}
		e->i = 0;
		e->j++;
	}
}
