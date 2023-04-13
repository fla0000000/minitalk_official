/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:43 by fbiondo           #+#    #+#             */
/*   Updated: 2023/04/13 18:32:32 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfproget/libftprintf.h"

void	ft_mtalk(char *str, gid_t pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((1 << bit) & *str)
		{
			kill(pid, SIGUSR1);
			usleep(300);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(300);
		}
		bit--;
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;
	int		i;

	i = -1;
	if (ac != 3)
	{
		ft_printf("wrong the <pid> <text>");
		return (0);
	}
	else
	{
		pid = ft_atoi(av[1]);
		while (av[2][++i])
			ft_mtalk(&av[2][i], pid);
		ft_printf("Messaggio ricevuto: %s", av[2]);
	}
}
