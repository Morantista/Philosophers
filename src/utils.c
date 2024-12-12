/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:39:19 by cballet           #+#    #+#             */
/*   Updated: 2024/12/11 20:44:20 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

unsigned long	ft_timestamp_ms(void)
{
	struct timeval	current_time;
	unsigned long	timestamp_ms;

	gettimeofday(&current_time, NULL);
	timestamp_ms = (current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000;
	return (timestamp_ms);
}

void	ft_writing_status(char *str, t_monitor *monitor, const char *color,
		unsigned long timestamp)
{
	unsigned long time;

	time = timestamp - monitor->info->start_time;
	if (time >= 0 && (ft_dead_flag(monitor) != 0))
		return ;
	pthread_mutex_lock(&monitor->info->mutex_write);
	printf(" %s%ld %d  %s%s/n", color, time, monitor->philo->id, str, NO_COLOR);
	pthread_mutex_unlock(&monitor->info->mutex_write);
}
