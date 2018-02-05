/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:27:36 by jostraye          #+#    #+#             */
/*   Updated: 2018/01/14 16:15:20 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		error_condition(char *a)
{
	if (ft_strcmp(a, "1") && ft_strcmp(a, "2") && ft_strcmp(a, "3")
	&& ft_strcmp(a, "4") && ft_strcmp(a, "5") && ft_strcmp(a, "6")
	&& ft_strcmp(a, "7"))
		return (1);
	else
		return (0);
}

void	print_error(int err)
{
	if (err == 1)
		ft_putstr("Error, you must pass one argument to the function");
	if (err == 2)
	{
		ft_putstr("\nError, do not pass any argument, or choose from \n\n");
		ft_putstr("\t1 for Mandlebrot\n\t2 for Julia\n\t");
		ft_putstr("3 for Tricorn\n\t4 for Dentelle\n\t5 for Chicken\n\t");
		ft_putstr("6 for Burning Ship\n\t7 for Bear Reflection\n");
	}
}
