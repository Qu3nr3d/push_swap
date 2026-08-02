#include "push_swap.h"

void pa(t_list **taba, t_list **tabb) {
    t_list *p;
    if (*tabb == NULL)
        return ;
    p = *tabb;
    *tabb = (*tabb)->next;
    (*tabb)->prev = NULL;
    p->next = *taba;
    p->prev = NULL;
    *taba = p;
}

void pb(t_list **taba, t_list **tabb) {
    t_list *p;
    if (*taba == NULL)
        return ;
    p = *taba;
    *taba = (*taba)->next;
    (*taba)->prev = NULL;
    p->next = *tabb;
    p->prev = NULL;
    *tabb = p;
}