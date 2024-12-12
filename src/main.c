/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:57:00 by cballet           #+#    #+#             */
/*   Updated: 2024/12/12 17:57:31 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

// int	main(int argc, char **argv)
// {
// 	t_info		info;
// 	t_share		share;
// 	t_philo		*philo;
// 	t_monitor	monitor;
// 	int			i;

// 	printf("main check 1\n");
// 	ft_parsing(argc, argv);
// 	printf("main check 2\n");
// 	philo = malloc(sizeof(t_philo) * info.nbr_philo);
// 	if (!philo)
// 		return (4);
// 	ft_init_struct(argc, argv, &monitor);
// 	printf("main check 3\n");
// 	ft_create_philosopher_threads(&monitor);
// 	printf("main check 4\n");
// 	ft_create_monitoring_thread(&monitor);
// 	printf("main check 5\n");
// 	i = 0;
// 	while (i < info.nbr_philo)
// 	{
// 		pthread_join(philo[i].thread_id, NULL);
// 		i++;
// 	}
// 	pthread_join(monitor.monitor, NULL);
// 	free(philo);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_monitor	*monitor;
	t_info	info;
	int			i;

	printf("main check 1\n");
	ft_parsing(argc, argv);
	printf("main check 2\n");
	ft_init_struct(argc, argv, monitor);
	printf("main check 3\n");
	monitor->philo = malloc(sizeof(t_philo) * info.nbr_philo);
	if (!monitor->philo)
		ft_is_error(4);
	printf("main check 4\n");
	ft_create_philosopher_threads(monitor);
	printf("main check 5\n");
	ft_create_monitoring_thread(monitor);
	printf("main check 6\n");
	i = 0;
	while (i < monitor->info->nbr_philo)
	{
		pthread_join(monitor->philo[i].thread_id, NULL);
		i++;
	}
	pthread_join(monitor->monitor, NULL);
	free(monitor->philo);
	free(monitor->info);
	return (0);
}
