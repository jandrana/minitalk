/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:59:40 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/19 16:08:17 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/minitalk.h"

void	char_to_bitstring(pid_t pid, char *bit_string)
{
	int	j;
	int	send;

	j = -1;
	while (bit_string[++j])
	{
		if (bit_string[j] == '1')
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
	int		i;
	int		j;
	int		k;
	char	*result;

	i = -1;
	while (str[++i])
	{
		result = (char *)malloc(sizeof(char) * 7 + 1);
		j = 0;
		k = 6;
		while (j < 7)
		{
			result[k] = "01"[str[i] % 2];
			str[i] = str[i] / 2;
			j++;
			k--;
		}
		result[7] = '\0';
		char_to_bitstring(pid, result);
		free(result);
		usleep(200);
	}
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
	send_bits(ft_atoi(argv[1]), argv[2]);
	send_bits(ft_atoi(argv[1]), "\0");
	return (0);
}
