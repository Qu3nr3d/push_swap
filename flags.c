#include "push_swap.h"

int	str_is_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] || s2[i])
		return (0);
	return (1);
}

int check_flags(char *str, t_flags *flags)
{
	if (str_is_equal("--bench", str))
		flags->is_bench++;
	else if (str_is_equal("--simple", str))
		flags->is_simple++;
	else if (str_is_equal("--medium", str))
		flags->is_medium++;
	else if (str_is_equal("--complex", str))
		flags->is_complex++;
	else
		return (0);
	return (1);
}

// jeszcze trzeba bedzie dla number_of_args = 1, 2 i 3 ogarnac + jak bedzie wiecej razy bench i simple itd
void initialize_flags(int argc, char *args[], t_flags *flags)
{
	int	i;

	i = 0;
	flags->is_bench = 0;
	flags->is_simple = 0;
	flags->is_medium = 0;
	flags->is_complex = 0;
	flags->is_adaptive = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]) && !check_flags(argv[i], flags))
			return (0);
		i++;
	}
	i = 0;
	return (1);
}


int	is_flag(char *str)
{
	if (str_is_equal("--bench", str))
		return (1);
	if (str_is_equal("--simple", str))
		return (1);
	if (str_is_equal("--medium", str))
		return (1);
	if (str_is_equal("--complex", str))
		return (1);
	if (str_is_equal("--adaptive", str))
		return (1);
	return (0);
}