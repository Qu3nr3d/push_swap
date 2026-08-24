#include "checker.h"

// static bool str_is_equal(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] && s2[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return (0);
// 		i++;
// 	}
// 	if (s1[i] || s2[i])
// 		return (false);
// 	return (true);
// }

// static bool is_operation(char *s)
// {
// 	if (str_is_equal(s, "sa\n"))
// 		return (true);
// 	if (str_is_equal(s, "sb\n"))
// 		return (true);
// 	if (str_is_equal(s, "ss\n"))
// 		return (true);
// 	if (str_is_equal(s, "pa\n"))
// 		return (true);
// 	if (str_is_equal(s, "pb\n"))
// 		return (true);
// 	if (str_is_equal(s, "ra\n"))
// 		return (true);
// 	if (str_is_equal(s, "rb\n"))
// 		return (true);
// 	if (str_is_equal(s, "rr\n"))
// 		return (true);
// 	if (str_is_equal(s, "rra\n"))
// 		return (true);
// 	if (str_is_equal(s, "rrb\n"))
// 		return (true);
// 	if (str_is_equal(s, "rrr\n"))
// 		return (true);
// 	return (false);
// }


bool	read_stdin(char *operation)
{
	static char *stash = NULL;
	static int stash_size = 0;
	char *buffer;

	if (stash)

}