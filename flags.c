#include "push_swap.h"

int	str_is_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (0);
		i++;
	}
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
void initialize_flags(int number_of_args, char *args[], t_flags *flags)
{
	int	i;

	i = 0;
	flags->is_bench = 0;
	flags->is_simple = 0;
	flags->is_medium = 0;
	flags->is_complex = 0;
	while (i < 2 && !is_number(args[i + 1]) && i < number_of_args)
	{
		if (!check_flags(args[i + 1], flags))
		{
			//error trzeba bedzie dac
			return ;
		}
		i++;
	}
	i = 0;
	while (i < 2 && !is_number(args[number_of_args - 1 - i]))
	{
		if (!check_flags(args[number_of_args - 1 - i], flags))
		{
			//error trzeba bedzie dac
			return ;
		}
		i++;
	}
}