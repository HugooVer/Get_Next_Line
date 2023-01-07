/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvercell <hvercell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:39:13 by hvercell          #+#    #+#             */
/*   Updated: 2023/01/07 21:38:29 by hvercell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		++len;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	ret = malloc((len1 + len2 + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			ret[i] = s1[i];
			++i;
		}
		i = 0;
	}
	if (s2 != NULL)
	{
		while (s2[i] != '\0')
		{
			ret[i + 3] = s2[i];
			++i;
		}
	}
	return (ret[len1 + len2 + 1] = '\0', ret);
}

int	main()
{
	char	*s1;
	char	*s2;

}
