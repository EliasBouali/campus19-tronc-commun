#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd,&c,1);
}

#include <unistd.h>

int main()
{
    ft_putchar_fd('A', 1); 
    ft_putchar_fd('B', 2);

    return 0;
}

