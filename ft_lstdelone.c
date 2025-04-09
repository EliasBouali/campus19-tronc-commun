#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if(lst == NULL || del == NULL)
		return;
	del(lst->content);//la fonction del libere le contenu 
	free(lst);//libere l'elemet lui-meme
}

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Fonction del qui libère une chaîne de caractères
void my_del(void *content)
{
    free(content);
}

int main(void)
{
    // Création d'un élément de liste avec une chaîne de caractères dynamiquement allouée
    t_list *node = ft_lstnew(malloc(6));  // On alloue de la mémoire pour stocker "Hello"
    if (!node || !node->content)
        return (1);

    // Copie de "Hello" dans la mémoire allouée
    char *str = (char *)node->content;
    str[0] = 'H'; str[1] = 'e'; str[2] = 'l'; str[3] = 'l'; str[4] = 'o'; str[5] = '\0';

    // Affichage du contenu avant suppression
    printf("Avant suppression : %s\n", (char *)node->content);

    // Suppression de l'élément avec ft_lstdelone
    ft_lstdelone(node, my_del);

    // Tentative d'accès au contenu après suppression (juste pour vérifier)
    if (node)
        printf("Après suppression : %p\n", (void *)node); // Normalement l'accès est impossible

    return (0);
}

