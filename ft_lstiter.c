/* fonction qui va parcourir une liste chainée de type t_list sans modifier les maillons
applique une fonction au contenu (content) de chaque maillons */ 


#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return;
	while(lst)// ou while(lst != NULL)
	{
		f(lst->content);//applique f() sur le conteny de l'element actuel.
		lst = lst->next;//passe au maillon suivant.
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Fonction qui sera appliquée à chaque élément de la liste
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

int main(void)
{
    t_list *list = NULL;
    t_list *node1 = ft_lstnew("Hello");
    t_list *node2 = ft_lstnew("World");
    t_list *node3 = ft_lstnew("42");

    // Ajout des noeuds à la liste
    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);

    // Utilisation de ft_lstiter pour afficher chaque élément
    printf("Contenu de la liste :\n");
    ft_lstiter(list, print_content);

    // Libération de la mémoire (si tu veux être sûr de ne pas avoir de leaks)
    ft_lstclear(&list, free);

    return (0);
}

