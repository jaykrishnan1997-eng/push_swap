/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvoelkne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:44:52 by gvoelkne          #+#    #+#             */
/*   Updated: 2026/05/18 15:27:15 by gvoelkne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_splits(char const *s, char *targets)
{
	char	**splits;
	int		idx;

	splits = ft_split(s, targets);
	idx = 0;
	if (!splits)
		printf("\t(null)\n");
	while (splits && splits[idx])
	{
		printf("\t%d = '%s'\n", idx, splits[idx]);
		idx++;
	}
}

int	*parse_nums(char *nums_str)
{
	char	**splits;
	int		idx;
	int		*num;

	if (!nums_str)
		return (NULL);
	splits = ft_split(s, targets);
	if (!splits)
		return (NULL);
	idx = 0;
	while (splits && splits[idx])
	{
		num = ft_atoi(splits[idx]);
		if (!num)
			return (NULL); // todo: cleanup the linked list
		idx++;
	}
}

t_args	parse_args(int argc, char **argv)
{
	int		idx;
	t_args	prog_args;

	// how can i determine between the nums being passed as a string vs positional args?
	// iterate over argv:
	// - if str starts with '--' => treat as flag, parse it
	// - if calc_splits(str,
			whitespace_chars) > 2 => treat it as a series of nums
	idx = 0;
	prog_args = {NULL, ADAPTIVE, 0};
	while (idx < argc)
	{
		printf("argv[%d] = '%s'\n", idx, argv[idx]);
		printf("\tsplitted:\n");
		print_splits(argv[idx], "\t\n\v\f\r ");
		idx++;
	}
	if (argc < 2)
	{
		printf("less than two args provided - exiting.");
		_exit(0); // correct?
	}
	return (prog_args);
}

int	main(int argc, char **argv)
{
	t_args	parsed_args;

	// potential flags: '--bench', '--simple', '--medium', '--complex',
		'--adaptive'
	// if no flags are provided: just exit.
	// the bench flag can always be provided
	// default mode/flag = 'adaptive'
	// example calls:
	// ./push_swap --simple 5 4 3 2 1
	//  ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
	// error mgmt examples:
	// $> ./push_swap --adaptive 0 one 2 3
		// invalid input: each number can only appear once in the input seq
	// Error
	//
	// $> ./push_swap --simple 3 2 3
	// Error
	//
	parsed_args = parse_args(argc, argv);
	printf("======\n");
	printf("parsed program args:\n");
	printf("\tbenchmark_enabled: %d\n", parsed_args.benchmark_enabled);
}
