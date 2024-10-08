/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:57:00 by cballet           #+#    #+#             */
/*   Updated: 2024/10/07 10:55:01 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/philo.h"


int	main(int argc, char **argv)
{
	t_general_info info;
	t_share	share;
	t_philo	*philo;

	ft_parsing(argc, argv);
	philo = malloc(sizeof(t_philo) * info.nbr_philo);
	if (!philo)
		return (4);
	 init_table(argc, argv, &info, &share, philo);
}
