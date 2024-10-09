/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:01:05 by cballet           #+#    #+#             */
/*   Updated: 2024/10/09 17:09:24 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	create_philosopher_threads(t_general_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i] != 0);
		i++;
	}
}
