/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:37:03 by jostraye          #+#    #+#             */
/*   Updated: 2018/01/14 14:29:25 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	plastic_palette(double r)
{
	if (r < 0.1)
		return (0xC11717);
	else if (r >= 0.1 && r < 0.5)
		return (0x060403);
	else if (r >= 0.5 && r < 2)
		return (0x16CCB9);
	else if (r >= 2 && r < 5)
		return (0x3D63FF);
	else if (r >= 5 && r < 10)
		return (0x9E5E25);
	else if (r >= 10 && r < 20)
		return (0xCCCCCC);
	else if (r >= 20 && r < 100)
		return (0x34D38C);
	else if (r >= 100 && r < 1000)
		return (0xFFFFFF);
	else if (r >= 1000 && r < 10000)
		return (0xFFC83D);
	return (0xFFEB3D);
}

int	space_palette(double r)
{
	if (r < 0.1)
		return (0x630C99);
	else if (r >= 0.1 && r < 0.5)
		return (0x490970);
	else if (r >= 0.5 && r < 2)
		return (0x360754);
	else if (r >= 2 && r < 5)
		return (0x244AE2);
	else if (r >= 5 && r < 10)
		return (0xF2FF66);
	else if (r >= 10 && r < 20)
		return (0x6B00E5);
	else if (r >= 20 && r < 100)
		return (0x4B6AE7);
	else if (r >= 100 && r < 1000)
		return (0x14297C);
	else if (r >= 1000 && r < 10000)
		return (0xFAFFC7);
	return (0x000000);
}

int	herbal_palette(double r)
{
	if (r < 0.1)
		return (0xADDADB);
	else if (r >= 0.1 && r < 0.5)
		return (0x9772ad);
	else if (r >= 0.5 && r < 2)
		return (0x789A6B);
	else if (r >= 2 && r < 5)
		return (0x3A5430);
	else if (r >= 5 && r < 10)
		return (0x1E150C);
	else if (r >= 10 && r < 20)
		return (0x3B2A18);
	else if (r >= 20 && r < 100)
		return (0x664929);
	else if (r >= 100 && r < 1000)
		return (0xA07240);
	else if (r >= 1000 && r < 10000)
		return (0xBA8177);
	return (0xE5E5E5);
}
