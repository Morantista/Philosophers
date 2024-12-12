/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:21:26 by cballet           #+#    #+#             */
/*   Updated: 2024/12/12 17:43:15 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

/*J'ai besoin de checker

- s'il est mort
- si ils ont tous mange
*/

int	ft_philos_get_finished(t_philo *philo, t_monitor *monitor)
{
	int	philo_finish;

	pthread_mutex_lock(&philo->mutex_finish_diner);
	philo_finish = monitor->info->nbr_philo_finish;
	pthread_mutex_unlock(&philo->mutex_finish_diner);
	return (philo_finish);
}

void	ft_philos_finished(t_philo *philo, t_monitor *monitor)
{
	unsigned long	time_in_ms;

	time_in_ms = ft_timestamp_ms();
	ft_writing_status("ALL PHILOSPHERS FINISHED THEIR MEALS", monitor,
		YELLOW, time_in_ms);
}

int	ft_last_meal(t_philo *philo)
{
	unsigned long	time_last_meal;

	pthread_mutex_lock(&philo->mutex_time_eat);
	time_last_meal = philo->time_last_meal;
	pthread_mutex_unlock(&philo->mutex_time_eat);
	return (time_last_meal);
}


void	*ft_monitoring(void *philosopher)
{
	t_philo			*philo;
	t_monitor		*monitor;
	int				i;
	int				philo_finish;
	unsigned long	time_in_ms;
	unsigned long	time_last_meal;
	monitor = (t_monitor*)philosopher;
	philo = monitor->philo;
	i = 0;
	while (1)
	{
		while (i < philo->info->nbr_philo)
		{
			philo_finish = ft_philos_get_finished(&philo[i], monitor);
			time_in_ms = ft_timestamp_ms();
			time_last_meal = ft_last_meal(&philo[i]);
			if ((time_in_ms - time_last_meal) > philo[i].info->time_to_die)
				return(ft_count_philo_died(monitor),NULL);

		}
		if (philo_finish == philo->info->nbr_philo)
			return((ft_philos_finished(&philo[i], monitor)), NULL);
	}
	printf("je suis rentre dans le monitoring");
	return (NULL);
}
