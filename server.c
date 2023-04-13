/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:13:14 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/13 18:32:44 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfproget/libftprintf.h"

void	ft_brain(int sign)
{
	static int	x;
	static int	y;

	if (sign == SIGUSR1)
	{
		y *= 2;
		y += 1;
		x++;
	}
	else
	{
		x++;
		y *= 2;
	}
	if (x == 8)
	{
		ft_printf("%c", y);
		x = 0;
		y = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;
	pid_t				pid;

	signal.sa_handler = &ft_brain;
	signal.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	pid = getpid();
	ft_printf(" %d\n", pid);
	while (1)
		pause();
}
