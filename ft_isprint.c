int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
  return (0);
}


#include <stdio.h>
#include "libft.h"

int main(void)
{
    char test_chars[] = {'A', ' ', '~', '\n', 127, '0', 31};
    int i = 0;

    while (i < 7)
    {
        if (ft_isprint(test_chars[i]))
            printf("'%c' (ASCII %d) est imprimable.\n", test_chars[i], test_chars[i]);
        else
            printf("(ASCII %d) n'est pas imprimable.\n", test_chars[i]);
        i++;
    }
    return (0);
}

