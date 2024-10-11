/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:01:05 by cballet           #+#    #+#             */
/*   Updated: 2024/10/10 13:05:59 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_create_philosopher_threads(t_general_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, ft_routine, &philo[i] != 0);
		i++;
	}
}


void	ft_create_monitoring_thread(t_share *share, t_philo *philo)
{
	pthread_create(share->monitor, NULL, ft_monitoring, (void *)philo);
}
