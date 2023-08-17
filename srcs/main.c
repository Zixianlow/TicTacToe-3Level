/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:35:29 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/17 20:02:34 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tictactoe.h"

int	exit_hook(t_tic *tic)
{
	ft_perror_exit("You close the terminal!!!\n", tic);
	return (0);
}

void	ft_restart(int keycode, t_tic *tic, int level)
{
	int	i;

	i = -1;
	while (++i < 9)
		tic->grid[i] = 0;
	tic->level = level;
	if (tic->turn == 9 && tic->won == 0)
		tic->d++;
	tic->turn = 0;
	if (tic->won == 1)
	{
		if (tic->winner == 1)
			tic->w++;
		if (tic->winner == 2)
			tic->l++;
	}
	tic->won = 0;
	mlx_clear_window(tic->mlx, tic->win);
	render_next_frame(tic);
}

int	kclose(int keycode, t_tic *tic)
{
	if (keycode == 53)
	{
		mlx_destroy_window(tic->mlx, tic->win);
		ft_perror_exit("You hit ESC!!!\n", tic);
	}
	if (keycode == 18)
		ft_restart(keycode, tic, 0);
	if (keycode == 19)
		ft_restart(keycode, tic, 1);
	if (keycode == 20)
		ft_restart(keycode, tic, 2);
	return (0);
}

void	put_info(t_tic *tic)
{
	mlx_string_put(tic->mlx, tic->win, 0, 0, 0xFFFFFF, "Level select: 1 - Easy, 2 - Medium, 3 - Hard");
	if (tic->level == 0)
		mlx_string_put(tic->mlx, tic->win, 0, 475, 0xFFFFFF, "Level : Easy");
	if (tic->level == 1)
		mlx_string_put(tic->mlx, tic->win, 0, 475, 0xFFFFFF, "Level : Medium");
	if (tic->level == 2)
		mlx_string_put(tic->mlx, tic->win, 0, 475, 0xFFFFFF, "Level : Hard");
	mlx_string_put(tic->mlx, tic->win, 140, 475, 0xFFFFFF, "|Win -     |Lose -     |Draw -     |");
	mlx_string_put(tic->mlx, tic->win, 205, 475, 0xFFFFFF, itoa(tic->w, tic->buffer, 10));
	mlx_string_put(tic->mlx, tic->win, 325, 475, 0xFFFFFF, itoa(tic->l, tic->buffer, 10));
	mlx_string_put(tic->mlx, tic->win, 445, 475, 0xFFFFFF, itoa(tic->d, tic->buffer, 10));
}

int	ft_animate(t_tic *tic)
{
	tic->frame++;
	if (tic->frame % 500 == 1)
	{
		mlx_clear_window(tic->mlx, tic->win);
		put_info(tic);
		render_next_frame(tic);
	}
	if (tic->frame == 6000)
		tic->frame = 0;
	return (0);
}

void	ft_add_turn(t_tic *tic, int x, int y)
{
	if (y >= 185 && y <= 315)
	{
		if (x >= 35 && x <= 165)
		{
			if (tic->grid[3] != 0)
				return ;
			tic->grid[3] = 1;
			tic->turn++;
		}
		if (x >= 185 && x <= 315)
		{
			if (tic->grid[4] != 0)
				return ;
			tic->grid[4] = 1;
			tic->turn++;
		}
		if (x >= 335 && x <= 465)
		{
			if (tic->grid[5] != 0)
				return ;
			tic->grid[5] = 1;
			tic->turn++;
		}
	}
	if (y >= 335 && y <= 465)
	{
		if (x >= 35 && x <= 165)
		{
			if (tic->grid[6] != 0)
				return ;
			tic->grid[6] = 1;
			tic->turn++;
		}
		if (x >= 185 && x <= 315)
		{
			if (tic->grid[7] != 0)
				return ;
			tic->grid[7] = 1;
			tic->turn++;
		}
		if (x >= 335 && x <= 465)
		{
			if (tic->grid[8] != 0)
				return ;
			tic->grid[8] = 1;
			tic->turn++;
		}
	}
}

int	mouse_hook(int button, int x, int y, t_tic *tic)
{
	if (button != 1 || tic->turn % 2 == 1 || tic->won == 1)
		return (0);
	if (y >= 35 && y <= 165)
	{
		if (x >= 35 && x <= 165)
		{
			if (tic->grid[0] != 0)
				return (0);
			tic->grid[0] = 1;
			tic->turn++;
		}
		if (x >= 185 && x <= 315)
		{
			if (tic->grid[1] != 0)
				return (0);
			tic->grid[1] = 1;
			tic->turn++;
		}
		if (x >= 335 && x <= 465)
		{
			if (tic->grid[2] != 0)
				return (0);
			tic->grid[2] = 1;
			tic->turn++;
		}
	}
	ft_add_turn(tic, x, y);
	return (0);
}

int	main(void)
{
	t_tic	tic;
	int		i;

	i = -1;
	while (++i < 9)
		tic.grid[i] = 0;
	tic.turn = 0;
	tic.won = 0;
	tic.winner = 0;
	tic.w = 0;
	tic.l = 0;
	tic.d = 0;
	tic.level = 2;
	tic.mlx = mlx_init();
	tic.win = mlx_new_window(tic.mlx, 500, 500, "tic-tac-toe");
	mlx_hook(tic.win, 17, (1L << 0), exit_hook, &tic);
	mlx_hook(tic.win, 2, (1L << 0), kclose, &tic);
	mlx_hook(tic.win, 4, (1L << 2), mouse_hook, &tic);
	mlx_loop_hook(tic.mlx, ft_animate, &tic);
	mlx_loop(tic.mlx);
}
