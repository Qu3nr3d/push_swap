#include "push_swap.h"
#include <stdarg.h>
#include <stdio.h>

t_stack create_stack(int n, ...)
{
	int i;
	int number;
	t_list *head;
	t_stack stack;
	va_list numbers;

    va_start(numbers, n);
	stack.size = n;
	head = NULL;
	i = 0;
	while (i < n)
	{
		number = va_arg(numbers, int);
		ft_lstadd_back(&head, ft_lstnew(number));
		i++;
	}
	stack.first_node = head;
	stack.last_node = ft_lstlast(head);
	return (stack);
}

void display_stack(t_list *tab)
{
	t_list *node;

	node = tab;
	while (node)
	{
		printf("| ");
		printf("%d", node->number);
		printf(" |");
		node = node->next;
		printf("\n");
	}
	printf("\n");
}

// int main(void)
// {
// 	t_stack stack_a = create_stack(500, -491, -627, -475, -731, -563, -555, -535, -775, -67, -799, -707, -715, -891, -687, -783, -403, -587, -247, -643, -467, -859, -495, -759, -479, -311, -711, -867, -287, -447, -419, -231, -807, -703, -659, -435, -607, -691, -423, -443, -723, -747, -63, -271, -619, -411, -667, -195, -279, -851, -531, -499, -339, -387, -679, -871, -335, -315, -379, -523, -383, -455, -291, -623, -699, -911, -95, -663, -763, -647, -539, -767, -331, -599, -527, -487, -567, -295, -883, -427, -463, -547, -803, -407, -275, -551, -579, -211, -415, -471, -771, -139, -223, -507, -163, -603, -779, -147, -519, -363, -639, -395, -515, -43, -671, -791, -451, -895, -595, -167, -199, -431, -303, -511, -111, -875, -743, -299, -615, -655, -899, -571, -727, -251, -255, -683, -751, -35, -631, -307, -755, -59, -819, -131, -55, -15, -243, -483, -143, 17, -999, -99, -71, -907, 33, -11, -739, 57, -191, -79, -27, -795, -215, -343, -347, -155, -995, -787, -903, -359, -923, -219, -283, 149, 65, 13, -47, -319, 109, -171, -183, -591, -963, -843, -123, 73, -375, -39, -175, -391, 77, 105, -227, -239, -115, -327, -91, -151, -651, -263, -207, 141, -935, -7, 49, -3, 5, 1, 169, -355, -815, 121, 85, -827, -107, -23, -967, -203, -399, 165, -559, 9, -127, -947, 229, -931, 125, -735, -887, 129, 173, 137, -323, 93, -543, 101, -915, 81, 89, -371, -31, 113, -635, -187, -235, 213, 53, 285, -439, 177, 41, 25, 29, 37, -259, -75, 161, 181, 45, 193, 197, -991, 185, 305, -975, 97, 133, 321, 117, 329, 369, -87, 317, -51, 257, -695, 281, 189, 237, -863, 201, 301, 241, 69, -267, 269, 253, 233, 157, 217, 393, 381, -179, 309, 261, 249, 209, 453, 325, -19, 153, 385, 225, 389, -611, 265, 401, -823, 349, -835, 277, 289, 61, 365, -583, -367, 293, 413, 421, 377, -351, 357, -831, 373, 333, 221, 521, 397, 417, 457, 145, 337, 313, 409, 449, 485, 353, 565, -939, 429, 361, 297, -103, 341, 205, 473, -927, 461, 437, 433, -847, 469, 465, 481, 501, 517, 513, -811, 537, 577, 581, 273, 545, 529, 549, -503, 425, 601, -839, -971, 561, 637, 489, -135, 525, -159, 21, 621, 557, 597, 553, -83, 405, 673, 593, 617, 505, 441, 573, 585, -951, 629, 497, -879, 665, 493, 661, 693, 533, 445, 625, 245, 609, 605, 685, 633, 729, 653, 509, 613, 681, 641, 709, 677, -987, -675, 345, 717, 657, 737, 697, 645, -575, -719, 689, 773, 589, 753, -119, 725, 569, 713, 757, 649, 765, 705, 817, 781, 805, 669, 721, 733, 541, -943, -983, -979, -959, -955, -919, -855, -459, 477, 701, 741, 745, 749, 761, 769, 777, 785, 789, 793, 797, 801, 809, 813, 821, 825, 829, 833, 837, 841, 845, 849, 853, 857, 861, 865, 869, 873, 877, 881, 885, 889, 893, 897, 901, 905, 909, 913, 917, 921, 925, 929, 933, 937, 941, 945, 949, 953, 957, 961, 965, 969, 973, 977, 981, 985, 989, 993, 997);
// 	t_stack stack_b = create_stack(0);
// 	int counter = 0;
//
// 	simple_sort(&stack_a, &stack_b, &counter);
// 	printf("stack a\n");
// 	display_stack((stack_a.first_node));
// 	printf("%i ilosc ruchow", counter);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_flags	flags;
	t_stack stack_a;
	t_stack stack_b;
	t_metrics metrics;

	if (argc == 1)
		return (3);
	initialize_flags(argc, argv, &flags);
	//printf("bench: %i\n", flags.is_bench);
	//printf("simple: %i\n", flags.is_simple);
	//printf("medium: %i\n", flags.is_medium);
	//printf("complex: %i\n", flags.is_complex);
	initialize_stacks(&stack_a, &stack_b);
	parse(argc, argv, &stack_a);
	display_stack(stack_a.first_node);
	// mozliwe ze tu trzeba bedzie ifa usunac
	if (flags.is_bench == 1)
		initialize_metrics(&metrics, flags, stack_a);
	printf("disorder: %f\n", metrics.disorder);
	printf("strategy: %s\n", metrics.strategy);
	printf("total_ops: %i\n", metrics.total_ops);
	printf("ops before:\n");
	printf(" %i\n", metrics.ops.use_pa);
	printf(" %i\n", metrics.ops.use_pb);
	printf(" %i\n", metrics.ops.use_sa);
	printf(" %i\n", metrics.ops.use_sb);
	printf(" %i\n", metrics.ops.use_ss);
	printf(" %i\n", metrics.ops.use_ra);
	printf(" %i\n", metrics.ops.use_rb);
	printf(" %i\n", metrics.ops.use_rr);
	printf(" %i\n", metrics.ops.use_rra);
	printf(" %i\n", metrics.ops.use_rrb);
	printf(" %i\n", metrics.ops.use_rrr);
	complex_sort(&stack_a, &stack_b, &metrics.ops);
	display_stack(stack_a.first_node);
	printf("ops after:\n");
	printf(" %i\n", metrics.ops.use_pa);
	printf(" %i\n", metrics.ops.use_pb);
	printf(" %i\n", metrics.ops.use_sa);
	printf(" %i\n", metrics.ops.use_sb);
	printf(" %i\n", metrics.ops.use_ss);
	printf(" %i\n", metrics.ops.use_ra);
	printf(" %i\n", metrics.ops.use_rb);
	printf(" %i\n", metrics.ops.use_rr);
	printf(" %i\n", metrics.ops.use_rra);
	printf(" %i\n", metrics.ops.use_rrb);
	printf(" %i\n", metrics.ops.use_rrr);
	
	return (0);
	/*
	int	is_bench;
	int	is_strategy_selector;

	is_bench = 0;
	is_strategy_selector = 0;



	int i = 1;
	int flag = 0;
	int bench = 0;
	t_stack stack_a;
	t_list *p;
	t_list *node
	t_stack stack_b;
	t_ops ops;
	char *is_bench;
	char *is_strategy;
	ops = {0};
	if(!ft_strcmp("--bench", argv[1]))
	{
		is_bench = argv[1];
		bench++;
		i++;
	}
	if(bench == 1)
	{
		IS_ARG(argv[2]);
		is_strategy = argv[2];
	}
	else
	{
		IS_ARG(argv[1]);
		is_strategy = argv[2];
	}
	while(i <= argc)
	{
		node = ft_lstnew(argv[i]);
		if(i == 2)
			stack_a->first_node = node;
		else
			ft_lstadd_back(node, p);
		i++;
	}
	stack_a->last_node = node;

	if(bench)
		benchmark(is_strategy, &stack_a, &stack_b, &ops);
	else if(flag)
		strategy(is_strategy, &stack_a, &stack_b, &ops);
	else
		compute_disorder(&stack_a, &stack_b, &ops);
	*/
}