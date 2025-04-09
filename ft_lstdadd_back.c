#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
  if(!lst)
    return (NULL);
  while(lst->next)
  {
    lst = lst->next;
  }
  return (lst);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
  t_list *last;
  
  if(!lst || !new)// si lst et new n'existe pas.
    return;
  if(*lst == NULL)// si la liste est vide, on place neew comme premier element.
  {
    *lst = new;
    return;
  }
  last = ft_lstlast(*lst);// trouve le dernier element de la liste.
  last->next = new;// on lie le dernier element a new.
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    t_list *list = NULL;
    t_list *node1 = ft_lstnew("Premier");
    t_list *node2 = ft_lstnew("Dernier");

    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);

    // Affichage des éléments de la liste
    t_list *tmp = list;  // On utilise un pointeur temporaire pour parcourir sans modifier la liste originale
    while (tmp)
    {
        printf("Contenu : %s\n", (char *)tmp->content);
        tmp = tmp->next;
    }

    // Libération de la mémoire
    tmp = list;
    while (tmp)
    {
        t_list *next = tmp->next; // On sauvegarde l'adresse du prochain élément avant de libérer
        free(tmp);
        tmp = next;
    }

    return (0);
}

