#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if(!s)
		return;
	while(s[i])
	{
		write(fd,&s[i],1);
		i++;
	}
	write(fd,"\n",1);
}


#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

int main(void)
{
    // Test d'affichage sur la sortie standard (console)
    ft_putendl_fd("Hello, World!", 1);

    // Test d'écriture dans un fichier
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return (1);

    ft_putendl_fd("This is a test.", fd);
    ft_putendl_fd("Another line.", fd);

    close(fd);

    printf("Vérifie le fichier output.txt !\n");

    return (0);
}

