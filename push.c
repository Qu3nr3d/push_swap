#include "push_swap.h"

void pa(t_list **taba, t_list **tabb, t_list **last_a) {
    t_list *p;
    if (*tabb == NULL)
        return ;
    p = *tabb;
    *tabb = (*tabb)->next;
    if (*tabb)
        (*tabb)->prev = NULL;
    p->next = *taba;
    p->prev = NULL;
    if (*taba)
        (*taba)->prev = p;
    else
        *last_a = p;
    *taba = p;
}

void pb(t_list **tabb, t_list **taba, t_list **last_b) {
    t_list *p;
    if (*taba == NULL)
        return ;
    p = *taba;
    *taba = (*taba)->next;
    if (*taba)
        (*taba)->prev = NULL;
    p->next = *tabb;
    p->prev = NULL;
    if (*tabb)
        (*tabb)->prev = p;
    else
        *last_b = p;
    *tabb = p;
}