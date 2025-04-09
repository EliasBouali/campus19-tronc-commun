#include <unistd.h>

void  ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return;
	while(s[i])
	{
		write(fd,&s[i],1);
		i++;
	}
}

/* df ou dile description est un entier utilisé par le systeme pour identifier un fichier ouvert ou un flux d'entrée/sortie.
 * il y  a descripteurs standards :
 * 0 standard input, lire au clavier 
 * 1 standard Output, afficher avec printf, write
 * 2 standar error , afficher une erreur 
 * ft_putstr_fd permet de choisir ou tu veux ecrire une chaine de caracteres.
 */ 


int main(void)
{
    // 1. Écriture sur la sortie standard (stdout : 1)
    ft_putstr_fd("Test sur stdout (écran)\n", 1);

    // 2. Écriture sur la sortie d'erreur (stderr : 2)
    ft_putstr_fd("Test sur stderr (erreur)\n", 2);

    // 3. Test avec un pointeur NULL (ne doit rien afficher ni planter)
    ft_putstr_fd(NULL, 1);

    return 0;
}
