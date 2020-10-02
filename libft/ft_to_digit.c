#include "libft.h"

int		ft_to_digit(char c)
{
	if (c >= '1' && c <= '9')
		return (c - '0');
	return (0);
}