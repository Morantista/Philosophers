/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:57:00 by cballet           #+#    #+#             */
/*   Updated: 2024/10/11 17:55:26 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/philo.h"


int	main(int argc, char **argv)
{
	t_general_info info;
	t_share	share;
	t_philo	*philo;
	int	i;

	ft_parsing(argc, argv);
	philo = malloc(sizeof(t_philo) * info.nbr_philo);
	if (!philo)
		return (4);
	ft_init_struct(argc, argv, &info, &share, philo);
	ft_create_philosopher_threads(&info, philo);
	ft_create_monitoring_thread(&share, philo);
	i = 0;
	while (i < info.nbr_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	pthread_join(share.monitor, NULL);
	free(philo);
	return(0);
}
