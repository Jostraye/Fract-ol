/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 10:17:55 by jostraye          #+#    #+#             */
/*   Updated: 2018/01/14 20:25:00 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double c_abs(t_complex z)
{
  double x;
  x = z.re * z.re + z.im * z.im;
  x = sqrt(x);
  return (x);
}

t_complex point_delta(t_complex z1, t_complex z2)
{
  t_complex x;

  x.re = (z1.re * z2.re + z1.im * z2.im) / (z1.re * z1.re - z1.im * z1.im) - 1;
  x.im = (z1.re * z2.im - z1.im * z2.re) / (z1.re * z1.re - z1.im * z1.im);
  return (x);
}

t_complex c_add(t_complex a, t_complex b)
{
  t_complex c;

  c.re = a.re + b.re;
  c.im = a.im + b.im;
  return (c);
}

t_complex c_mult(t_complex a, t_complex b)
{
  t_complex c;

  c.re = a.re * b.re - a.im * b.im;
  c.im = a.re * b.im + a.im * b.re;
  return (c);
}

t_complex c_sub(t_complex a, t_complex b)
{
  t_complex c;

  c.re = a.re - b.re;
  c.im = a.im - b.im;
  return (c);
}
