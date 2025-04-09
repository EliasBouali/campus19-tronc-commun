#include "libft.h"

void  ft_lstadd_front(t_list **lst, t_list *new)
{
	if(lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

#include <stdio.h>
#include "libft.h"

int main(void)
{
    t_list *list;
    t_list *new_node;
    char *str1 = "Premier";
    char *str2 = "Nouveau Premier";

    list = ft_lstnew(str1);
    new_node = ft_lstnew(str2);

    ft_lstadd_front(&list, new_node);

    printf("Premier élément : %s\n", (char *)list->content);

    free(list->next);
    free(list);

    return (0);
}

