#include "push_swap.h"

void pa(t_list **taba, t_list **tabb) {
    t_list *p;
    if (*tabb == NULL)
        return ;
    p = *tabb;
    *tabb = (*tabb)->next;
    p->next = *taba;
    *taba = p;
}

void pb(t_list **taba, t_list **tabb) {
    t_list *p;
    if (*taba == NULL)
        return ;
    p = *taba;
    *taba = (*taba)->next;
    p->next = *tabb;
    *tabb = p;
}