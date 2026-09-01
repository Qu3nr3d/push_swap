/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:46:30 by akacpere          #+#    #+#             */
/*   Updated: 2026/07/08 20:56:15 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	nbr_len(int n)
{
	unsigned int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	is_n_special_case(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (1);
	}
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			nbr_str[11];
	unsigned int	len;

	if (is_n_special_case(n, fd))
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	if (n < 0)
		n *= -1;
	len = nbr_len(n);
	nbr_str[len] = '\0';
	while (n > 0)
	{
		nbr_str[len - 1] = (char){n % 10 + 48};
		n /= 10;
		len--;
	}
	ft_putstr_fd(nbr_str, fd);
}
