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

float complex	fract_iter(int arg, double  complex z, t_env *e)
{
	double			a;
	double			b;
	double	complex c;
	double	complex x;
	if (e->i < e->xj)
		a = ((e->i + e->x) / (SIZE * e->zoom_param) + e->x_offset) ;
	else
		a = ((e->i + e->x) / (SIZE * e->zoom_param) + e->x_offset) ;
	if (e->i < e->xj)
		b = ((e->j + e->y) / (SIZE * e->zoom_param) + e->y_offset) ;
	else
	b = ((e->j + e->y) / (SIZE * e->zoom_param) + e->y_offset) ;

	c = a + b * I;
	if (arg == 1)
		x = z * z + c;
	if (arg == 3)
		x = (creal(z) - cimag(z) * I) * (creal(z) - cimag(z) * I) + c;
	if (arg == 4)
		x = (fabs(creal(z)) + cimag(z) * I) *
		(fabs(creal(z)) + cimag(z) * I) + c;
	if (arg == 5)
		x = (creal(z) + fabs(cimag(z)) * I) *
		(creal(z) + fabs(cimag(z)) * I) + c;
	if (arg == 6)
		x = (fabs(creal(z)) + fabs(cimag(z)) * I) * (fabs(creal(z)) +
		fabs(cimag(z)) * I) + c;
	if (arg == 7)
		x = (fabs(creal(z)) - cimag(z) * I) *
		(fabs(creal(z)) - cimag(z) * I) + c;
	return (x);
}

void			mobl_fract(t_env *e)
{
	int				i;
	float complex	c;

	i = 0;
	e->a = (e->i + e->x) / (SIZE * e->zoom_param) + e->x_offset;
	e->b = (e->j + e->y) / (SIZE * e->zoom_param) + e->y_offset;
	e->z = e->a + e->b * I;
	c = e->xj + e->yj * I;
	while (i++ < e->max_it)
		e->z = e->z * e->z + c;
	e->z1 = e->z * e->z + c;
	e->z2 = e->z1 * e->z1 + c;
	e->data[((int)e->j * SIZE + (int)e->i)] =
		attribute_color(cabs(((e->z2 - e->z1) / e->z1) -
		((e->z1 - e->z) / e->z)), e->clr_set);
}

void			stat_fract(t_env *e)
{
	int				i;
	float complex	z;
	float complex	z1;
	float complex	z2;

	i = 0;
	z = 0;
	while (i++ < e->max_it)
		z = fract_iter(e->argument, z, e);
	z1 = fract_iter(e->argument, z, e);
	z2 = fract_iter(e->argument, z1, e);
	e->data[((int)e->j * SIZE + (int)e->i)] =
		attribute_color(cabs(((z2 - z1) / z1) - ((z1 - z) / z)), e->clr_set);
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
