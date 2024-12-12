/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:44:04 by cballet           #+#    #+#             */
/*   Updated: 2024/12/12 17:44:51 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_count_philo_finish(t_monitor *monitor)
{
	unsigned long	time_in_ms;

	time_in_ms = ft_timestamp_ms();
	pthread_mutex_lock(&monitor->philo->mutex_finish_diner);
	monitor->info->nbr_philo_finish++;
	pthread_mutex_unlock(&monitor->philo->mutex_finish_diner);
	ft_writing_status("A PHILO FINISH DINER", monitor, GREEN,time_in_ms);
}

void	ft_count_philo_died(t_monitor *monitor)
{
	unsigned long	time_in_ms;

	time_in_ms = ft_timestamp_ms();
	ft_writing_status("A PHILO DIED", monitor, RED,time_in_ms);
	pthread_mutex_lock(&monitor->philo->mutex_philo_dead);
	monitor->philo->dead++;
	pthread_mutex_unlock(&monitor->philo->mutex_philo_dead);

}
