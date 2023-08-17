/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tictactoe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:40:44 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/17 20:03:55 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TICTACTOE_H
# define TICTACTOE_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_tic
{
	void		*mlx;
	void		*win;
	int			frame;
	int			turn;
	int			won;
	int			winner;
	int			level;
	char		buffer[20];
	int			w;
	int			l;
	int			d;
	int			grid[9];
}	t_tic;

void	ft_perror_exit(char *s, t_tic *tic);
int		ft_strlen(char *s);
void	render_next_frame(t_tic *tic);
void	draw_fill(t_tic *tic);
char* itoa(int num, char* str, int base);

#endif