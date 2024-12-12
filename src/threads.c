/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:01:05 by cballet           #+#    #+#             */
/*   Updated: 2024/12/11 20:56:48 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_create_philosopher_threads(t_monitor *monitor)
{
	int	i;

	i = 0;
	printf("je suis rentre dans philo_thread\n");
	while (i < monitor->info->nbr_philo)
	{
		printf("je rentre dans la boucle philo_thread\n");
		pthread_create(&(monitor->philo[i].thread_id), NULL, ft_routine, &monitor->philo[i]);
		i++;
	}
	printf("je suis passe dans philo_thread\n");

}


void	ft_create_monitoring_thread(t_monitor *monitor)
{
	pthread_create(&(monitor->monitor), NULL, ft_monitoring, (void *)monitor);
	printf("je suis rentre dans monitoring_thread");
}
