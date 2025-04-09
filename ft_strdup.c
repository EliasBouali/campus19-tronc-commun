#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int	i;
	int	len;
	char	*copy;

	i = 0;
	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while(s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    const char *str = "Hello, World!";
    char *copy;

    // Test de ft_strlen()
    // printf("Longueur de '%s' : %d\n", str, ft_strlen(str)); // Devrait afficher 13

    // Test de ft_strdup()
    copy = ft_strdup(str);
    if (copy)
    {
        printf("Copie : %s\n", copy); // Devrait afficher : "Hello, World!"
        free(copy);
    }
    else
        printf("Allocation échouée.\n");

    return (0);
}

