#include "push_swap.h"

void sb(t_list *tab, int size) {
    int helper;

    if (size < 2)
        return ;
    helper = tab->content;
    tab->content = tab->next->content;
    tab->next->content = helper;
}
//tu sa zrobic
void ss(t_list *taba, t_list *tabb, int sizea, int sizeb) {
    sb(taba, sizea);
    sb(tabb, sizeb);
}