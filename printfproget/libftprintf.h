/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:30:17 by fbiondo           #+#    #+#             */
/*   Updated: 2023/04/13 17:56:41 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <signal.h>
# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(char const *str);
void	ft_puutnbr(int n, int *written);
int		ft_u_puutnbr(unsigned int n);
int		ft_puutchar(int c);
int		ft_puutstr(char *s);
int		ft_x_puutnbr(char c, unsigned int nb);
int		ft_p_puutnbr(char c, unsigned long long nb);
int		ft_printf(const char *format, ...);
int		ft_atoi(const char *str);

#endif
