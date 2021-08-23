/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 03:47:26 by klever            #+#    #+#             */
/*   Updated: 2021/08/23 01:34:26 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;
	size_t			j;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	while ((ss1[i] == ss2[i] && ss1[i] != '\0') && i < n)
		i++;
	if (i == n)
		i--;
	j = ss1[i] - ss2[i];
	return (j);
}
