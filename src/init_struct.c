/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:01:11 by cballet           #+#    #+#             */
/*   Updated: 2024/12/12 19:20:28 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_init_struct_info(int argc, char **argv, t_info *info)
{
	printf("je rentre dans l'init_struct_info\n");
	info->nbr_philo = ft_atoi(argv[1], &info->nbr_philo);
	printf("alloc argv1\n");
	info->time_to_die = ft_atoi(argv[2], &info->time_to_die);
	printf("alloc argv2\n");
	info->time_to_eat = ft_atoi(argv[3], &info->time_to_eat);
	printf("alloc argv3\n");
	info->time_to_sleep = ft_atoi(argv[4], &info->time_to_sleep);
	printf("alloc argv4\n");
	info->nbr_of_times_each_philo_must_eat = -1;
	info->nbr_philo_finish = 0;
	info->nbr_philo_finish = 0;
	info->stop = 0;
	if (argc == 6)
		info->nbr_of_times_each_philo_must_eat = ft_atoi(argv[5], &info->nbr_of_times_each_philo_must_eat);
	else
		info->nbr_of_times_each_philo_must_eat = -1;
	info->start_time = ft_timestamp_ms();
	printf("je suis passe dans l'init_struct_info\n");
}

void	ft_init_struct_philo(t_monitor *monitor)
{
	int	i;

	i = 0;
	while (i < monitor->info->nbr_philo)
	{
		monitor->philo[i].info = monitor->info;
		monitor->philo[i].id = i + 1;
		printf("ID du philosophe : %d\n", monitor->philo[i].id);
		monitor->philo[i].dead = 0;
		monitor->philo[i].time_last_meal = monitor->info->start_time;
		monitor->philo[i].nbr_meal = monitor->philo->info->nbr_of_times_each_philo_must_eat;
		if (i == monitor->info->nbr_philo - 1)
			monitor->philo[i].mutex_right_fork = &monitor->philo[0].mutex_left_fork;
		else
			monitor->philo[i].mutex_right_fork = &monitor->philo[i + 1].mutex_left_fork;
		i++;
	}
	printf("je suis passe dans l'init_struct_philo\n");
}

void	ft_init_mutex(t_monitor *monitor)
{
	int	i;

	i = 0;
	pthread_mutex_init(&(monitor->info->mutex_write), NULL);
	while (i < monitor->info->nbr_philo)
	{
		pthread_mutex_init(&(monitor->philo[i].mutex_left_fork), NULL);
		pthread_mutex_init(&(monitor->philo[i].mutex_philo_dead), NULL);
		pthread_mutex_init(&(monitor->philo[i].mutex_finish_diner), NULL);
		pthread_mutex_init(&(monitor->philo[i].mutex_time_eat), NULL);
		i++;
	}
	printf("je suis passe dans l'init_mutex\n");
}

void	ft_init_struct(int argc, char **argv, t_monitor *monitor)
{
	printf("je rentre dans l'init struct\n");
	ft_init_struct_info(argc, argv, monitor->info);
	ft_init_struct_philo(monitor);
	ft_init_mutex(monitor);
	printf("je suis passe dans l'init struct\n");
}
