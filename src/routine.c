/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cballet <cballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:15:05 by cballet           #+#    #+#             */
/*   Updated: 2024/10/07 14:13:00 by cballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int ft_dead_flag(t_philo *philo)
{
    int dead;
    
    pthread_mutex_lock(&philo->mutex_philo_dead);
    dead = philo->dead;
    pthread_mutex_unlock(&philo->mutex_philo_dead);
    return (dead);
}

void ft_is_sleeping(t_share *share)
{
    unsigned long time_in_ms;

    time_in_ms = ft_timestamp_ms;
    ft_writing_status("is sleeping", share, GREY, time_in_ms);
    usleep(share->philo->info->time_to_sleep * 1000);
}

void    ft_is_thinking(t_share *share)
{
    if 
}