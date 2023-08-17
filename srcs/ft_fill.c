/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:35:43 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/17 19:35:15 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tictactoe.h"


void	draw_circle(t_tic *tic, int x, int y)
{
	int		i;
	int		j;
	double	d;

	i = -1;
	while (++i <= 130)
	{
		j = -1;
		while (++j <= 130)
		{
			d = (65 - i) * (65 - i) + (65 - j) * (65 - j);
			if (d <= 65 * 65 && d >= 50 * 50)
				mlx_pixel_put(tic->mlx, tic->win, x + i, y + j, 0xFFFFFF);
		}
	}
}

void	draw_cross(t_tic *tic, int x, int y)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i <= 130)
	{
		j = -1;
		while (++j <= 130)
		{
			k = 130 - i;
			if (j <= i + 10 && j > i - 10)
			{
				mlx_pixel_put(tic->mlx, tic->win, x + i, y + j, 0xFFFFFF);
				mlx_pixel_put(tic->mlx, tic->win, x + k, y + j, 0xFFFFFF);
			}
		}
	}
}

void	draw_fill(t_tic *tic)
{
	int	i;
	int	x;	
	int	y;

	i = -1;
	while (++i < 9)
	{
		x = 35 + (i % 3) * 150;
		y = 35 + (i / 3) * 150;
		if (tic->grid[i] == 1)
			draw_circle(tic, x, y);
		if (tic->grid[i] == 2)
			draw_cross(tic, x, y);
	}
}
