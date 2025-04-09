#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*new_node;
	new_node = (t_list *)malloc(sizeof(t_list));
	if(!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*current;

	current = *lst;
	if(!lst || !del)
		return;
	while(current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

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

t_list *ft_lstmap(t_list *lst, void *(*f)(void*),void (*del)(void *))
{
	t_list	*new_list;// nouvelle liste creer.
	t_list *new_node;

	new_list = NULL;
	if (!lst || !f || !del)
		return NULL;
	while(lst)
	{
		void *new_content = f(lst->content);// appliquer la fonction f() sur le nouveau contenu.
		new_node = ft_lstnew(new_content);// creation du nouveau noeud avec le contenu.
		if(!new_node)//si l'allocation echoue, liberation de toute la nouvelle liste.
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);// on ajoute le nouveau noeud a la fin de la nouvelle liste 
		lst = lst->next;
	}
	return (new_list);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// Fonction qui sera appliquée à chaque élément de la liste
void *duplicate_content(void *content)
{
    return (strdup((char *)content));
}

// Fonction de suppression
void delete_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *list = ft_lstnew(strdup("Hello"));
    ft_lstadd_back(&list, ft_lstnew(strdup("World")));
    ft_lstadd_back(&list, ft_lstnew(strdup("42")));

    t_list *new_list = ft_lstmap(list, duplicate_content, delete_content);

    // Affichage de la nouvelle liste
    for (t_list *temp = new_list; temp; temp = temp->next)
        printf("%s\n", (char *)temp->content);

    ft_lstclear(&list, delete_content);
    ft_lstclear(&new_list, delete_content);

    return (0);
}

