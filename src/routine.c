/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:15:05 by cballet           #+#    #+#             */
/*   Updated: 2024/10/11 18:09:20 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_dead_flag(t_philo *philo)
{
	int	dead;

	pthread_mutex_unlock(&philo->share->nbr_philo_dead);
	dead = philo->share->nbr_philo_dead;
	pthread_mutex_unlock(&philo->share->nbr_philo_dead);
	return (dead);
}

void	ft_count_philo_finish(t_philo *philo)
{
	unsigned long	time_in_ms;

	time_in_ms = ft_timestamp_ms();
	pthread_mutex_lock(&philo->share->mutex_finish_diner);
	philo->share->nbr_philo_finish++;
	pthread_mutex_unlock(&philo->share->mutex_finish_diner);
	ft_writing_status("A PHILO FINISH DINER", philo->share, GREEN,time_in_ms);
}

void	ft_count_philo_died(t_philo *philo)
{
	unsigned long	time_in_ms;

	time_in_ms = ft_timestamp_ms();
	ft_writing_status("A PHILO DIED", philo->share, RED,time_in_ms);
	pthread_mutex_lock(&philo->mutex_philo_dead);
	philo->dead++;
	pthread_mutex_unlock(&philo->mutex_philo_dead);

}

void	ft_eating(t_philo *philo)
{
	unsigned long	time_ms;

	time_ms = ft_timestamp_ms;
	pthread_mutex_lock(&philo->mutex_time_eat);
	philo->time_last_meal = time_ms;
	pthread_mutex_unlock(&philo->mutex_time_eat);
	pthread_mutex_lock(&philo->mutex_right_fork);
	time_ms = ft_timestamp_ms;
	ft_writing_status("Has taken right fork", philo->share, GREEN,
		ft_timestamp_ms);
	pthread_mutex_lock(&philo->mutex_left_fork);
	time_ms = ft_timestamp_ms;
	ft_writing_status("Has taken left fork", philo->share, GREEN,
		ft_timestamp_ms);
	time_ms = ft_timestamp_ms;
	ft_writing_status("Is eating", philo->share, BLUE, ft_timestamp_ms);
	usleep(philo->info->time_to_eat);
	philo->nbr_meal--;
	if (philo->nbr_meal == 0)
		ft_count_philo_finish(philo);
	pthread_mutex_unlock(&philo->mutex_right_fork);
	pthread_mutex_ublock(&philo->mutex_left_fork);
}

void	ft_sleeping(t_philo *philo)
{
	unsigned long	time_in_ms;

	time_in_ms = ft_timestamp_ms;
	ft_writing_status("is sleeping", philo->share, GREY, time_in_ms);
	usleep(philo->info->time_to_sleep * 1000);
}

void	ft_thinking(t_philo *philo)
{
	unsigned long	time_in_ms;
	unsigned long	time_thinking;

	time_in_ms = ft_timestamp_ms;
	ft_writing_status("is thinking", philo->share, GREY, time_in_ms);
	if (philo->info->time_to_eat > philo->info->time_to_sleep)
		time_thinking = ((philo->info->time_to_eat > philo->info->time_to_sleep)
				* 1000);
	else
		time_thinking = 0;
	usleep(time_thinking * 1000);
}

void	ft_one_philo(t_philo *philo)
{
	unsigned long	time_in_ms;

	time_in_ms = ft_timestamp_ms;
	pthread_mutex_lock(&philo->mutex_left_fork);
	time_in_ms = ft_timestamp_ms;
	ft_writing_status("Has taken left fork", philo->share, GREEN,
		ft_timestamp_ms);
	time_in_ms = ft_timestamp_ms;
	ft_writing_status("Couldn't take right fork", philo->share, RED,
		ft_timestamp_ms);
	usleep(philo->info->time_to_die * 1000);
	ft_count_philo_died(philo);
	pthread_mutex_unlock(&philo->mutex_left_fork);
}

void	*ft_routine(void *thread_id)
{
	t_philo			*philo;
	unsigned long	time_in_ms;

	philo = (t_philo *)thread_id;
	time_in_ms = ft_timestamp_ms;
	if (philo->info->nbr_philo == 1)
		ft_one_philo(philo);
	if (philo->info->time_to_eat > philo->info->time_to_die)
		ft_count_philo_died(philo);
	if (philo->id % 2 != 0)
		usleep(philo->info->time_to_eat * 1000);
	while (ft_dead_flag == 0)
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (NULL);
}
