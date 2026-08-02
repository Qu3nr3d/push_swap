#include "push_swap.h"
void sa(t_list *tab, int size) {
    int helper;

    if (size < 2)
        return ;
    helper = tab->number;
    tab->number = tab->next->number;
    tab->next->number = helper;
}

void sb(t_list *tab, int size) {
    int helper;

    if (size < 2)
        return ;
    helper = tab->number;
    tab->number = tab->next->number;
    tab->next->number = helper;
}

void ss(t_list *taba, t_list *tabb, int sizea, int sizeb) {
    sa(taba, sizea);
    sb(tabb, sizeb);
}