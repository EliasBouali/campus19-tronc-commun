#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src,size_t dstsize)
{
	size_t	i;
	size_t dst_len = ft_strlen(dst);
	size_t src_len = ft_strlen(src);

	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return ( dst_len + src_len);
}

size_t	ft_strlcpy(char	*dst, const	char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len = ft_strlen(src);

	i = 0;
	if (dstsize == 0)
		return (src_len);
	while(src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}



char  *ft_strjoin(char const *s1, char const *s2)
{
    char    *join;
    size_t  len_s1;
    size_t  len_s2;

		if(!s1 || !s2)
			return (NULL);
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		join = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if(!join)
			return (NULL);
		ft_strlcpy(join, s1, len_s1 + 1);
		ft_strlcat(join, s2, len_s1 + len_s2 + 1);
		return (join);
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    // Test de ft_strlen()
    printf("Longueur de 'Hello' : %zu\n", ft_strlen("Hello")); // 5

    // Test de ft_strlcpy()
    char dst1[20];
    ft_strlcpy(dst1, "Hello, World!", 6);
    printf("ft_strlcpy : %s\n", dst1); // "Hello"

    // Test de ft_strlcat()
    char dst2[20] = "Hello";
    ft_strlcat(dst2, ", World!", 20);
    printf("ft_strlcat : %s\n", dst2); // "Hello, World!"

    // Test de ft_strjoin()
    char *joined = ft_strjoin("Hello", " World!");
    if (joined)
    {
        printf("ft_strjoin : %s\n", joined); // "Hello World!"
        free(joined);
    }

    return (0);
}

