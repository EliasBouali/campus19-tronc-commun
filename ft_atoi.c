int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while(str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\t' || str[i] == '\r')
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ( result * sign);
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    printf("%d\n", ft_atoi("42"));              // 42
    printf("%d\n", ft_atoi("-42"));             // -42
    printf("%d\n", ft_atoi("   1234"));         // 1234
    printf("%d\n", ft_atoi("  \t\n42"));        // 42
    printf("%d\n", ft_atoi("1234abc"));         // 1234
    printf("%d\n", ft_atoi("abc1234"));         // 0
    printf("%d\n", ft_atoi("0"));               // 0
    printf("%d\n", ft_atoi("-0"));              // 0
    printf("%d\n", ft_atoi("2147483647"));      // 2147483647 (INT_MAX)
    printf("%d\n", ft_atoi("-2147483648"));     // -2147483648 (INT_MIN)
    return (0);
}

