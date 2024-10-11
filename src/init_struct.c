/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:01:11 by cballet           #+#    #+#             */
/*   Updated: 2024/10/11 15:47:44 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_init_struct_info(int argc, char **argv, t_general_info *info)
{
	info->nbr_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->nbr_of_times_each_philo_must_eat = -1;
	if (argc == 6)
		info->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		info->nbr_of_times_each_philo_must_eat = -1;
	info->start_time = ft_timestamp_ms();
}

void	ft_init_struct_philo(int argc, char **argv, t_general_info *info,
		t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].dead = 0;
		philo[i].time_last_meal = info->start_time;
		philo[i].nbr_meal = philo->info->nbr_of_times_each_philo_must_eat;
		if (i == info->nbr_philo - 1)
			philo[i].mutex_right_fork = &philo[0].mutex_left_fork;
		else
			philo[i].mutex_right_fork = &philo[i + 1].mutex_left_fork;
		i++;
	}
}

void	ft_init_mutex(t_general_info *info, t_philo *philo, t_share *share)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(share->mutex_write), NULL);
	pthread_mutex_init(&(share->mutex_nbr_philo_dead), NULL);
	while (i < info->nbr_philo)
	{
		pthread_mutex_init(&(philo[i].mutex_left_fork), NULL);
		pthread_mutex_init(&(philo[i].mutex_philo_dead), NULL);
		pthread_mutex_init(&(philo[i].share->mutex_finish_diner), NULL);
		pthread_mutex_init(&(philo[i].mutex_time_eat), NULL);
		i++;
	}
}

void	ft_init_struct_share(int argc, char **argv, t_general_info *info,
		t_philo *philo, t_share *share)
{
	share->philo = philo;
	share->nbr_philo_finish = 0;
	share->nbr_philo_dead = share->philo->dead;
	share->nbr_philo_finish = 0;
	share->stop = 0;
}

void	ft_init_struct(int argc, char **argv, t_general_info *info,
		t_philo *philo, t_share *share)
{
	ft_init_mutex(info, philo, share);
	ft_init_struct_info(argc, argv, info);
	ft_init_struct_philo(argc, argv, info, philo);
	ft_init_struct_share(argc, argv, info, philo, share);
}
