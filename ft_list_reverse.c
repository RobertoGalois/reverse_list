#include    <stdlib.h>
#include    "ft_list.h"

void    ft_swap(t_list **begin_list, t_list **temp_prev, t_list **temp_next, t_list *new_next)
{
    *temp_next = (*begin_list)->next;
    (*begin_list)->next = new_next;
    *temp_prev = (*begin_list);
    (*begin_list) = *temp_next;
}

void    ft_list_reverse(t_list **begin_list)
{
    t_list  *temp_next;
    t_list  *temp_prev;

    if ((begin_list != NULL) && ((*begin_list) != NULL) && ((*begin_list)->next) != NULL)
    {
        /* treat the first element of the list */
        ft_swap(begin_list, &temp_prev, &temp_next, NULL);
       
        /* treat the middle elements (after the first, before the last = [2, (n-1)]) */
        while ((*begin_list)->next != NULL)
            ft_swap(begin_list, &temp_prev, &temp_next, temp_prev);

        /* treat the last element */
        (*begin_list)->next = temp_prev;
    }   
}
