#include "rtv1.h"
static float float_tail(char *str)
{
	float	tail;
	int 	digit1;
	int 	digit2;
	digit1 = 0;
	digit2 = 0;
	while(*str != '.')
		str++;
	str++;
	if (*str)
		digit1 = ft_to_digit(*str);
	str++;
	if (*str)
		digit2 = ft_to_digit(*str);
	tail = (float) digit1 * 0.1f + (float)digit2 * 0.01f;
//	printf("d1 %d, d2 %d, tail %f\n",digit1, digit2, tail);
	return (tail);
}

float	coordinate(char *str)
{
	int		left;
	float 	right;
	float	sign;
	float	res;
	sign = 1.0f;
	if(*str)
	{
		left = ft_atoi(str);
		if (left == 0 && str[0] == '-')
			sign = -1.0f;
		if (ft_strchr(str, '.'))
			right = float_tail(str);
		else
			right = 0.0f;
		res = (float )left + right;
		res = res > 0 ? res * sign : res;
		return (res);
	}
	return (DEFAULT_COORDINATE);
}

void	position(t_object *object, char *arr)
{
	char **coord;
	float x, y, z;
	coord = ft_strsplit(arr, ' ');
	printf("\n[%s, %s, %s]\n",coord[0], coord[1], coord[2]);
	x = coord[0] ? coordinate(coord[0]) : DEFAULT_COORDINATE;
	y = coord[0] ? coordinate(coord[1]) : DEFAULT_COORDINATE;
	z = coord[0] ? coordinate(coord[2]) : DEFAULT_COORDINATE;
	printf("[%.2f, %.2f, %.2f]\n",x,y,z);
	ft_safe_free_arr(coord);
}
