/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:33:00 by smolines          #+#    #+#             */
/*   Updated: 2024/06/04 20:16:42 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//checking -/+ position, authorized digits
int	ft_forbiddenchar(char *str)
{
	int	i;
	int	len;

	ft_parsingerror(str);
	len = ft_strlen (str);
	i = 1;
	while (i < len - 2)
	{
		if (ft_is_sign (str[i]) == 1)
		{
			if ((ft_is_digit (str[i + 1]) == 1)
				&& (ft_is_space (str[i - 1]) == 1))
				i++;
			else
				ft_error();
		}
		if ((ft_is_space (str[i]) == 1) || (ft_is_digit (str[i]) == 1))
			i++;
		if ((ft_is_space (str[i]) == 0) && (ft_is_digit (str[i]) == 0)
			&& (ft_is_sign (str[i]) == 0))
			ft_error();
	}		
	return (0);
}
