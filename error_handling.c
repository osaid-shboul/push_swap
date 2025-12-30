/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalshbou <oalshbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:09:48 by oalshbou          #+#    #+#             */
/*   Updated: 2025/12/30 16:55:27 by oalshbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


long	ft_atoi_check(const char *str, int *e)
{
	long	r;
	int		sign;
	int		i;

	r = 0;
	signe = 1;
	i = 0;
	if(str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
	{
		*e == 1;
		return (0);
	}
	while(str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*e = 1;
			return (0);
		}
		r = (r * 10) + (str[i] - '0');
		if ((r * sign) > 2147483647 || (r * sign) < -2147483648)
		{
			*e = 1;
			return (0);
		}
		i++;
	}
	return ( r * sign);
}


int	check_dublicates(int *num, int count)
{
	int	i;
	int	j;

	i = 0;
	while(i < count)
	{
		j = i +1;
		while (j < count)
		{
			if(num[i] == num[j])
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}
