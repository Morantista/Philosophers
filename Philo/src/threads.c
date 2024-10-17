/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:01:05 by cballet           #+#    #+#             */
/*   Updated: 2024/10/17 20:43:26 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_create_philosopher_threads(t_monitor *monitor)
{
	int	i;

	i = 0;
	printf("je suis rentre dans philo_thread");
	while (i < monitor->info->nbr_philo)
	{
		pthread_create(&(monitor->philo[i].thread_id), NULL, ft_routine, &monitor->philo[i]);
		i++;
	}
	printf("je suis passe dans philo_thread");

}


void	ft_create_monitoring_thread(t_monitor *monitor)
{
	pthread_create(&(monitor->monitor), NULL, ft_monitoring, (void *)monitor->philo);
	printf("je suis rentre dans monitoring_thread");
}
