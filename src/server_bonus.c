/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:48:08 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/19 15:38:51 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

t_mtdata	g_mtdata;

void	signal_handler(int num, siginfo_t *info, void *context)
{
	(void)context;
	if (num == SIGUSR1)
	{
		g_mtdata.character = (g_mtdata.character << 1) | 1;
		kill(info->si_pid, SIGUSR1);
	}
	else if (num == SIGUSR2)
	{
		g_mtdata.character = (g_mtdata.character << 1) | 0;
		kill(info->si_pid, SIGUSR2);
	}
	g_mtdata.num_bits++;
	if (g_mtdata.num_bits == 8)
	{
		ft_printf("%c", g_mtdata.character);
		g_mtdata.num_bits = 0;
		g_mtdata.character = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &signal_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	g_mtdata.num_bits = 0;
	g_mtdata.character = 0;
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sigact, 0);
		sigaction(SIGUSR2, &sigact, 0);
		pause();
	}
	return (0);
}
