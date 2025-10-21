/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:50:12 by smolines          #+#    #+#             */
/*   Updated: 2024/06/04 20:16:39 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_is_space(char c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	ft_is_digit(char c)
{
	if ((c > 47) && (c < 58))
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if ((c == 43) || (c == 45))
		return (1);
	return (0);
}

int	ft_is_authorized(char c)
{
	if ((ft_is_space (c) == 1) || (ft_is_digit (c) == 1)
		|| (ft_is_sign (c) == 1))
		return (1);
	return (0);
}

// parsing first digit, last digit
int	ft_parsingerror(char *str)
{
	int	len;

	len = ft_strlen (str);
	if (ft_is_authorized (str[0]) == 0)
		ft_error();
	if ((ft_is_sign (str[0]) == 1) && (ft_is_digit (str[1]) == 0))
		ft_error();
	if ((ft_is_sign (str[len - 1]) == 1)
		|| (ft_is_authorized (str[len - 1]) == 0))
		ft_error();
	return (0);
}
