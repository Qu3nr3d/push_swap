#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
    int	i;

    i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	get_strategy(char *arg)
{
    if (ft_strcmp(arg, "--simple") == 0)
        return (SIMPLE);
    if (ft_strcmp(arg, "--medium") == 0)
        return (MEDIUM);
    if (ft_strcmp(arg, "--complex") == 0)
        return (COMPLEX);
    if (ft_strcmp(arg, "--adaptive") == 0)
        return (ADAPTIVE);
    return (0);
}

int	parse_flags(int argc, char **argv, t_config *config)
{
    int	i;
    int	strategy;

    config->strategy = ADAPTIVE;
    config->bench = 0;
    i = 1;
    while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
    {
        strategy = get_strategy(argv[i]);
        if (strategy)
            config->strategy = strategy;
        else if (ft_strcmp(argv[i], "--bench") == 0)
            config->bench = 1;
        else
            return (0);
        i++;
    }
    config->first_number = i;
    return (1);
}