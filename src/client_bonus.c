/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:59:40 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/19 16:59:31 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	free_array(int ***array, int i)
{
	while (i-- > 0)
	{
		free((*array)[i]);
	}
	free(*array);
}

void	char_to_bitstring(pid_t pid, int *bit_string)
{
	int	j;
	int	send;

	j = -1;
	while (++j <= 7)
	{
		if (bit_string[j] == 1)
			send = SIGUSR1;
		else
			send = SIGUSR2;
		if (kill(pid, send) < 0)
		{
			ft_printf("Unexpected error");
			exit(EXIT_FAILURE);
		}
		usleep(200);
	}
}

void	send_bits(pid_t pid, char *str)
{
	int		**result;
	int		bytes;
	int		bites;
	int		i;

	bytes = -1;
	while (str[++bytes])
		;
	result = (int **)malloc(sizeof(int *) * bytes + 1);
	bytes = 0;
	while (str[bytes])
	{
		result[bytes] = (int *)malloc(sizeof(int) * 8);
		bites = 8;
		i = 0;
		while (--bites >= 0)
			result[bytes][i++] = (str[bytes] >> bites) & 1;
		char_to_bitstring(pid, result[bytes]);
		usleep(200);
		bytes++;
	}
	free_array(&result, bytes);
}

void	client_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Server confirmation for 1\n");
	if (signum == SIGUSR2)
		ft_printf("Server confirmation for 0\n");
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_str_is_numeric(argv[1]))
	{
		ft_printf("\033[0;31mInvalid arguments\n\033[0mSintax:\033[0;32m");
		ft_printf(" ./client \033[36m[server PID] \033[35m[string]\n");
		ft_printf("\033[0mExample:");
		ft_printf("\033[0;32m ./client \033[36m\"123456\" \033[35m\"hola!\"\n");
		ft_printf("\033[0m");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, client_handler);
	signal(SIGUSR2, client_handler);
	send_bits(ft_atoi(argv[1]), argv[2]);
	send_bits(ft_atoi(argv[1]), "\0");
	return (0);
}
