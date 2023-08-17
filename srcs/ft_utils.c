/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 19:48:35 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/15 19:53:16 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tictactoe.h"

void	ft_perror_exit(char *s, t_tic *tic)
{
	write(2, s, ft_strlen(s));
	exit(0);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
