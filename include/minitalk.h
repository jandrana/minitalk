/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:49:45 by ana-cast          #+#    #+#             */
/*   Updated: 2024/04/22 16:12:24 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file minitalk.h
 * @brief Function prototypes for the minitalk project
 * 
 * The minitalk project consists on creating a communication
 * program between the client and the server
 * 
 * @author Ana Alejandra Castillejo Muñoz (github: jandrana)
*/

#ifndef MINITALK_H
# define MINITALK_H

# include <libft.h>
# include <signal.h>

typedef struct s_mtdata
{
	int	num_bits;
	int	character;
}	t_mtdata;

#endif /* MINITALK_H */