/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:15:05 by cballet           #+#    #+#             */
/*   Updated: 2024/12/12 17:48:13 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_dead_flag(t_monitor *monitor)
{
	int	dead;

	pthread_mutex_lock(&monitor->philo->mutex_philo_dead);
	dead = monitor->philo->dead;
	pthread_mutex_unlock(&monitor->philo->mutex_philo_dead);
	return (dead);
}

void	ft_eating(t_monitor *monitor)
{
	unsigned long	time_ms;

	time_ms = ft_timestamp_ms();
	pthread_mutex_lock(&monitor->philo->mutex_time_eat);
	monitor->philo->time_last_meal = time_ms;
	pthread_mutex_unlock(&monitor->philo->mutex_time_eat);
	pthread_mutex_lock(monitor->philo->mutex_right_fork);
	time_ms = ft_timestamp_ms();
	ft_writing_status("Has taken right fork", monitor, GREEN,
		time_ms);
	pthread_mutex_lock(&monitor->philo->mutex_left_fork);
	time_ms = ft_timestamp_ms();
	ft_writing_status("Has taken left fork", monitor, GREEN,
		time_ms);
	time_ms = ft_timestamp_ms();
	ft_writing_status("Is eating", monitor, BLUE, time_ms);
	usleep(monitor->philo->info->time_to_eat);
	monitor->philo->nbr_meal--;
	if (monitor->philo->nbr_meal == 0)
		ft_count_philo_finish(monitor);
	pthread_mutex_unlock(monitor->philo->mutex_right_fork);
	pthread_mutex_unlock(&monitor->philo->mutex_left_fork);
}

void	ft_sleeping(t_monitor *monitor)
{
	unsigned long	time_in_ms;

	time_in_ms = ft_timestamp_ms();
	ft_writing_status("is sleeping", monitor, GREY, time_in_ms);
	usleep(monitor->philo->info->time_to_sleep * 1000);
}

void	ft_thinking(t_monitor *monitor)
{
	unsigned long	time_in_ms;
	unsigned long	time_thinking;

	time_in_ms = ft_timestamp_ms();
	ft_writing_status("is thinking", monitor, GREY, time_in_ms);
	if (monitor->philo->info->time_to_eat > monitor->philo->info->time_to_sleep)
		time_thinking = ((monitor->philo->info->time_to_eat - monitor->philo->info->time_to_sleep)
				* 1000);
	else
		time_thinking = 0;
	usleep(time_thinking * 1000);
}

void	ft_one_philo(t_monitor *monitor)
{
	unsigned long	time_in_ms;

	time_in_ms = ft_timestamp_ms();
	pthread_mutex_lock(&monitor->philo->mutex_left_fork);
	time_in_ms = ft_timestamp_ms();
	ft_writing_status("Has taken left fork", monitor, GREEN,
		time_in_ms);
	time_in_ms = ft_timestamp_ms();
	ft_writing_status("Couldn't take right fork", monitor, RED,
		time_in_ms);
	usleep(monitor->info->time_to_die * 1000);
	ft_count_philo_died(monitor);
	pthread_mutex_unlock(&monitor->philo->mutex_left_fork);
}

void	*ft_routine(void *thread_id)
{
	t_monitor	*monitor;
	unsigned long	time_in_ms;

	printf("je rentre dans la routine \n");
	monitor = (t_monitor *)thread_id;
	time_in_ms = ft_timestamp_ms();
	if (monitor->info->nbr_philo == 1)
	{
		ft_one_philo(monitor);
		printf("je rentre dans le if 1 de la routine \n");
	}
	if (monitor->info->time_to_eat > monitor->info->time_to_die)
	{
		ft_count_philo_died(monitor);
		printf("je rentre dans le if 2 de la routine \n");
	}
	if (monitor->philo->id % 2 != 0)
	{
		usleep(monitor->info->time_to_eat * 1000);
		printf("je rentre dans le if 3 de la routine \n");
	}
	while (ft_dead_flag(monitor) == 0)
	{
		printf("je rentre dans la boucle de la routine \n");
		ft_eating(monitor);
		ft_sleeping(monitor);
		ft_thinking(monitor);
	}
	printf("je suis rentre dans la routine \n");
	return (NULL);
}
