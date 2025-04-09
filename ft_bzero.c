#include <stddef.h>
void	ft_bzero(void *s, size_t n)
{
	unsigned char *a;// on le cast en unsigned char * pour avoir accés aux octets 
	size_t i;

	if (!s)
		return ;
	i = 0;
	a = (unsigned char *) s;
	while(i < n)
	{
		a[i] = 0;
		i++;
	}
}

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
    char str[20] = "Hello World!";

    ft_bzero(str + 6, 6);
    printf("%s\n", str);  // Affiche : "Hello "

    return (0);
}
 
