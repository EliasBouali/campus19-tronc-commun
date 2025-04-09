#include <stdlib.h>

int ft_isnegative(int n, int *len, char *str)
{
    if (n < 0)
    {
        (*len)++;
        if(str)
            str[0] = '-';
        return (-1);
    }
    return (1);
}

char    *ft_itoa(int n)
{
    char *str;
    int len;
    int sign;
    int temp;

    len = 1;
    temp = n;
    while(temp/=10)
        len++;
    sign = ft_isnegative(n,&len,NULL);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (sign == -1)
        ft_isnegative(n,&len,str);
    while(len-- > 0 && n != 0)
    {
        str[len] = (n % 10) * sign + '0';
        n /= 10;
    }
    if (n == 0 && sign == 1)
        str[0] = '0';
    return (str);
}


#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *result;

    result = ft_itoa(42);
    printf("%s\n", result); // Devrait afficher : 42
    free(result);

    result = ft_itoa(-42);
    printf("%s\n", result); // Devrait afficher : -42
    free(result);

    result = ft_itoa(0);
    printf("%s\n", result); // Devrait afficher : 0
    free(result);

    result = ft_itoa(2147483647);
    printf("%s\n", result); // Devrait afficher : 2147483647
    free(result);

    result = ft_itoa(-2147483648);
    printf("%s\n", result); // Devrait afficher : -2147483648
    free(result);

    return (0);
}


