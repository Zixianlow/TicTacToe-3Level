/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:54:30 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/17 19:47:55 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tictactoe.h"

void	draw_border(t_tic *tic)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 500)
	{
		j = -1;
		while (++j <= 500)
		{
			if (i < 25 || i > 475)
			{
				if (tic->level == 0)
					mlx_pixel_put(tic->mlx, tic->win, i, j, 0x00FF00);
				if (tic->level == 1)
					mlx_pixel_put(tic->mlx, tic->win, i, j, 0xFFFF00);
				if (tic->level == 2)
					mlx_pixel_put(tic->mlx, tic->win, i, j, 0xFF0000);
			}
			if (i >= 25 && i <= 475 && (j < 25 || j > 475))
			{
				if (tic->level == 0)
					mlx_pixel_put(tic->mlx, tic->win, i, j, 0x00FF00);
				if (tic->level == 1)
					mlx_pixel_put(tic->mlx, tic->win, i, j, 0xFFFF00);
				if (tic->level == 2)
					mlx_pixel_put(tic->mlx, tic->win, i, j, 0xFF0000);
			}
		}
	}
}

void	draw_board(t_tic *tic)
{
	int	i;
	int	j;

	i = 29;
	while (++i <= 470)
	{
		j = 171;
		while (++j <= 178)
			mlx_pixel_put(tic->mlx, tic->win, i, j, 0xFFFFFF);
		j = 321;
		while (++j <= 328)
			mlx_pixel_put(tic->mlx, tic->win, i, j, 0xFFFFFF);
	}
	i = 29;
	while (++i <= 470)
	{
		j = 171;
		while (++j <= 178)
			mlx_pixel_put(tic->mlx, tic->win, j, i, 0xFFFFFF);
		j = 321;
		while (++j <= 328)
			mlx_pixel_put(tic->mlx, tic->win, j, i, 0xFFFFFF);
	}
}

int	draw_win_line(t_tic *tic, int type, int pos, int winner)
{
	int	x;
	int	y;
	int	z;
	int	d;

	x = 35;
	y = 35;
	if (type == 1)
	{
		while (x <= 465)
		{
			d = 0;
			y = 95 + pos % 3 * 150;
			while (d <= 10)
			{
				mlx_pixel_put(tic->mlx, tic->win, x, y + d, 0xFF0000);
				d++;
			}
			x++;
		}
	}
	if (type == 2)
	{
		while (y <= 465)
		{
			d = 0;
			x = 95 + pos % 3 * 150;
			while (d <= 10)
			{
				mlx_pixel_put(tic->mlx, tic->win, x + d, y, 0xFF0000);
				d++;
			}
			y++;
		}
	}
	if (type == 3)
	{
		while (x <= 465)
		{
			y = 35;
			while (y <= 465)
			{
				z = 465 - x;
				if (y <= x + 10 && y > x - 10)
				{
					if (pos == 1)
						mlx_pixel_put(tic->mlx, tic->win, x, y, 0xFF0000);
					if (pos == 2)
						mlx_pixel_put(tic->mlx, tic->win, 500 - x, y, 0xFF0000);
				}
				y++;
			}
			x++;
		}
	}
	tic->winner = winner;
	return (1);
}

int	check_win(t_tic *tic)
{
	if (tic->grid[0] == 1 && tic->grid[1] == 1 && tic->grid[2] == 1)
		tic->won = draw_win_line(tic, 1, 0, 1);
	if (tic->grid[3] == 1 && tic->grid[4] == 1 && tic->grid[5] == 1)
		tic->won = draw_win_line(tic, 1, 1, 1);
	if (tic->grid[6] == 1 && tic->grid[7] == 1 && tic->grid[8] == 1)
		tic->won = draw_win_line(tic, 1, 2, 1);
	if (tic->grid[0] == 1 && tic->grid[3] == 1 && tic->grid[6] == 1)
		tic->won = draw_win_line(tic, 2, 0, 1);
	if (tic->grid[1] == 1 && tic->grid[4] == 1 && tic->grid[7] == 1)
		tic->won = draw_win_line(tic, 2, 1, 1);
	if (tic->grid[2] == 1 && tic->grid[5] == 1 && tic->grid[8] == 1)
		tic->won = draw_win_line(tic, 2, 2, 1);
	if (tic->grid[0] == 1 && tic->grid[4] == 1 && tic->grid[8] == 1)
		tic->won = draw_win_line(tic, 3, 1, 1);
	if (tic->grid[2] == 1 && tic->grid[4] == 1 && tic->grid[6] == 1)
		tic->won = draw_win_line(tic, 3, 2, 1);
	if (tic->grid[0] == 2 && tic->grid[1] == 2 && tic->grid[2] == 2)
		tic->won = draw_win_line(tic, 1, 0, 2);
	if (tic->grid[3] == 2 && tic->grid[4] == 2 && tic->grid[5] == 2)
		tic->won = draw_win_line(tic, 1, 1, 2);
	if (tic->grid[6] == 2 && tic->grid[7] == 2 && tic->grid[8] == 2)
		tic->won = draw_win_line(tic, 1, 2, 2);
	if (tic->grid[0] == 2 && tic->grid[3] == 2 && tic->grid[6] == 2)
		tic->won = draw_win_line(tic, 2, 0, 2);
	if (tic->grid[1] == 2 && tic->grid[4] == 2 && tic->grid[7] == 2)
		tic->won = draw_win_line(tic, 2, 1, 2);
	if (tic->grid[2] == 2 && tic->grid[5] == 2 && tic->grid[8] == 2)
		tic->won = draw_win_line(tic, 2, 2, 2);
	if (tic->grid[0] == 2 && tic->grid[4] == 2 && tic->grid[8] == 2)
		tic->won = draw_win_line(tic, 3, 1, 2);
	if (tic->grid[2] == 2 && tic->grid[4] == 2 && tic->grid[6] == 2)
		tic->won = draw_win_line(tic, 3, 2, 2);
	return (tic->won);
}

int	block_first(t_tic *tic, int a, int b, int c)
{
	int	i;

	i = tic->grid[a] % 2 + tic->grid[b] % 2 + tic->grid[c] % 2;
	if (i == 2 && tic->grid[a] != 2 && tic->grid[b] != 2 && tic->grid[c] != 2)
	{
		if (tic->grid[a] == 0)
			tic->grid[a] = 2;
		if (tic->grid[b] == 0)
			tic->grid[b] = 2;
		if (tic->grid[c] == 0)
			tic->grid[c] = 2;
		tic->turn++;
		return (1);
	}
	return (0);
}

int	fill_first(t_tic *tic, int a, int b, int c)
{
	int	i;
	int	copy[9];

	i = -1;
	while (++i < 9)
	{
		if (tic->grid[i] == 2)
			copy[i] = 1;
		else
			copy[i] = 0;
	}
	i = copy[a] % 2 + copy[b] % 2 + copy[c] % 2;
	if (i == 2 && tic->grid[a] != 1 && tic->grid[b] != 1 && tic->grid[c] != 1)
	{
		if (copy[a] == 0)
			tic->grid[a] = 2;
		if (copy[b] == 0)
			tic->grid[b] = 2;
		if (copy[c] == 0)
			tic->grid[c] = 2;
		tic->turn++;
		return (1);
	}
	return (0);
}

int	ft_fill_odd_side(t_tic *tic, int a, int b)
{
	int	r;

	r = rand() % 2 + 0;
	if (r == 0)
		tic->grid[a] = 2;
	if (r == 1)
		tic->grid[b] = 2;
	tic->turn++;
	return (1);
}

int	ft_check_odd(t_tic *tic)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (tic->grid[i] == 1)
			break ;
	}
	if (i == 1)
		return (ft_fill_odd_side(tic, 0, 2));
	if (i == 3)
		return (ft_fill_odd_side(tic, 0, 6));
	if (i == 5)
		return (ft_fill_odd_side(tic, 2, 8));
	if (i == 7)
		return (ft_fill_odd_side(tic, 6, 8));
	return (0);
}

int	ft_fill_center(t_tic *tic)
{
	if (tic->grid[4] == 0)
	{
		tic->grid[4] = 2;
		tic->turn++;
		return (1);
	}
	return (0);
}

int	ft_check_even(t_tic *tic)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (i == 4)
			i++;
		if (tic->grid[i] == 1)
			break ;
	}
	return (ft_fill_center(tic));
}

int	ft_fill_diagonal(t_tic *tic)
{
	if (tic->grid[0] != 0 && tic->grid[4] != 0 && tic->grid[8] != 0)
		return (ft_fill_odd_side(tic, 2, 6));
	if (tic->grid[2] != 0 && tic->grid[4] != 0 && tic->grid[6] != 0)
		return (ft_fill_odd_side(tic, 0, 8));
	return (0);
}

int	ft_fill_odd(t_tic *tic)
{
	int	i;
	int	r;

	i = -1;
	while (++i < 9)
	{
		if (i % 2 == 1)
			if (tic->grid[i] != 0)
				return (0);
	}
	if (tic->grid[4] == 1)
		return (ft_fill_diagonal(tic));
	r = rand() % 4 + 0;
	if (r == 0)
		tic->grid[1] = 2;
	if (r == 1)
		tic->grid[3] = 2;
	if (r == 2)
		tic->grid[5] = 2;
	if (r == 3)
		tic->grid[7] = 2;
	tic->turn++;
	return (1);
}

int	ft_fill_even(t_tic *tic)
{
	int	r;

	r = rand() % 4 + 0;
	if (r == 0)
		tic->grid[0] = 2;
	if (r == 1)
		tic->grid[2] = 2;
	if (r == 2)
		tic->grid[6] = 2;
	if (r == 3)
		tic->grid[8] = 2;
	tic->turn++;
	return (1);
}

void	ai_loop_medium(t_tic *tic)
{
	int	pos;
	int	c;

	if (tic->turn % 2 == 0 || tic->turn == 9)
		return ;
	usleep(100000);
	if (fill_first(tic, 0, 1, 2))
		return ;
	if (fill_first(tic, 3, 4, 5))
		return ;
	if (fill_first(tic, 6, 7, 8))
		return ;
	if (fill_first(tic, 0, 3, 6))
		return ;
	if (fill_first(tic, 1, 4, 7))
		return ;
	if (fill_first(tic, 2, 5, 8))
		return ;
	if (fill_first(tic, 0, 4, 8))
		return ;
	if (fill_first(tic, 2, 4, 6))
		return ;
	if (block_first(tic, 0, 1, 2))
		return ;
	if (block_first(tic, 3, 4, 5))
		return ;
	if (block_first(tic, 6, 7, 8))
		return ;
	if (block_first(tic, 0, 3, 6))
		return ;
	if (block_first(tic, 1, 4, 7))
		return ;
	if (block_first(tic, 2, 5, 8))
		return ;
	if (block_first(tic, 0, 4, 8))
		return ;
	if (block_first(tic, 2, 4, 6))
		return ;
	while (tic->grid[pos] != 0)
		pos = rand() % 9 + 0;
	tic->grid[pos] = 2;
	tic->turn++;
	check_win(tic);
}

void	ai_loop_hard(t_tic *tic)
{
	int	pos;
	int	c;

	if (tic->turn % 2 == 0 || tic->turn == 9)
		return ;
	usleep(100000);
	if (tic->turn == 1 && ft_check_odd(tic))
		return ;
	if (tic->turn == 1 && ft_check_even(tic))
		return ;
	if (tic->turn == 1 && tic->grid[4] == 1 && ft_fill_even(tic))
		return ;
	if (fill_first(tic, 0, 1, 2))
		return ;
	if (fill_first(tic, 3, 4, 5))
		return ;
	if (fill_first(tic, 6, 7, 8))
		return ;
	if (fill_first(tic, 0, 3, 6))
		return ;
	if (fill_first(tic, 1, 4, 7))
		return ;
	if (fill_first(tic, 2, 5, 8))
		return ;
	if (fill_first(tic, 0, 4, 8))
		return ;
	if (fill_first(tic, 2, 4, 6))
		return ;
	if (block_first(tic, 0, 1, 2))
		return ;
	if (block_first(tic, 3, 4, 5))
		return ;
	if (block_first(tic, 6, 7, 8))
		return ;
	if (block_first(tic, 0, 3, 6))
		return ;
	if (block_first(tic, 1, 4, 7))
		return ;
	if (block_first(tic, 2, 5, 8))
		return ;
	if (block_first(tic, 0, 4, 8))
		return ;
	if (block_first(tic, 2, 4, 6))
		return ;
	if (tic->turn == 3 && ft_fill_odd(tic))
		return ;
	if (tic->turn == 3 && ft_fill_center(tic))
		return ;
	while (tic->grid[pos] != 0)
		pos = rand() % 9 + 0;
	tic->grid[pos] = 2;
	tic->turn++;
	check_win(tic);
}

void	ai_loop_easy(t_tic *tic)
{
	int	pos;

	if (tic->turn % 2 == 0 || tic->turn == 9)
		return ;
	usleep(100000);
	while (tic->grid[pos] != 0)
		pos = rand() % 9 + 0;
	tic->grid[pos] = 2;
	tic->turn++;
	check_win(tic);
}

void	render_next_frame(t_tic *tic)
{
	// draw_border(tic);
	draw_board(tic);
	draw_fill(tic);
	if (check_win(tic) == 0)
	{
		if (tic->level == 0)
			ai_loop_easy(tic);
		if (tic->level == 1)
			ai_loop_medium(tic);
		if (tic->level == 2)
			ai_loop_hard(tic);
	}
	return ;
}
