/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:48:08 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/19 16:10:03 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minitalk.h"

t_mtdata	g_mtdata;

void	signal_handler(int num)
{
	if (num == SIGUSR1)
		g_mtdata.character = (g_mtdata.character << 1) | 1;
	else if (num == SIGUSR2)
		g_mtdata.character = (g_mtdata.character << 1) | 0;
	g_mtdata.num_bits++;
	if (g_mtdata.num_bits == 7)
	{
		ft_printf("%c", g_mtdata.character);
		g_mtdata.num_bits = 0;
		g_mtdata.character = 0;
	}
}

int	main(void)
{
	g_mtdata.num_bits = 0;
	g_mtdata.character = 0;
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
