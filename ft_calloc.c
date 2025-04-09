#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	unsigned char *tab = (unsigned char *)b;

	i = 0;
	while(i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return b;
}

void *ft_calloc(size_t count, size_t size)
{
	size_t	len_total;
	void  *copy;
	if (count == 0 || size == 0)
		return (malloc(0));
	len_total = count * size;
	// count * size car on alloue count (objets) de size octets chacun.
	copy = malloc(len_total);
	// on utilise pas de sizeof() car size en argument dans calloc est deja la taille 'dun element 
	if(!copy)
		return (NULL);
	ft_memset(copy, 0, len_total);

	return (copy);
}

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    // Test de ft_memset()
    char str[20] = "Hello World!";
    ft_memset(str + 6, '*', 5);
    printf("%s\n", str); // Attendu : "Hello *****!"

    // Test de ft_calloc() classique
    int *arr = ft_calloc(5, sizeof(int));
    int i = 0;
    if (arr)
    {
        while (i < 5)
        {
            printf("%d ", arr[i]); // Attendu : "0 0 0 0 0"
            i++;
        }
        printf("\n");
        free(arr);
    }

    // Test de ft_calloc(0, 0)
    void *ptr = ft_calloc(0, 0);
    if (ptr)
        printf("ft_calloc(0, 0) returned a valid pointer.\n");
    else
        printf("ft_calloc(0, 0) returned NULL.\n");
    free(ptr);

    return (0);
}

 
