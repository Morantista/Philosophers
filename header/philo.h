#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <limits.h>

#define NO_COLOR "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[36m"
#define GREY "\033[90m"



typedef struct s_general_info
{
	int	nbr_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_of_times_each_philo_must_eat;
	unsigned long	start_time;
}   t_general_info;
/*Contient les paramètres de simulation qui sont communs à tous les philosophes.*/


typedef	struct s_philo
{
	t_general_info      *info;
	int                 id;
	pthread_t           thread_id;
	int					dead;
	pthread_mutex_t		mutex_philo_dead;
	unsigned long       time_last_meal;
	pthread_mutex_t		mutex_time_eat;
    int                 nbr_meal;
    int                 finish_diner;
	pthread_mutex_t		mutex_finish_diner;
	
	int					first_action;
    pthread_mutex_t     *mutex_right_fork;
    pthread_mutex_t     mutex_left_fork;
 

}t_philo;
/*Contient les informations propres à chaque philosophe, avec des pointeurs vers les ressources partagées.*/

typedef	struct s_share
{
	t_philo				*philo;
	int					nbr_philo_finish;
	int					nbr_philo_dead;
	int					stop;
	pthread_mutex_t		mutex_write;
	pthread_t			monitor;
}	t_share;
/*Contient les mutex et les variables de contrôle partagées entre tous les philosophes.*/

//UTILS
int	ft_atoi(char *str);
unsigned long   ft_timestamp_ms(void);
void    ft_writing_status(char *str, t_share *share, const char *color, unsigned long timestamp);

//INIT STRUCT
void    init_table(int argc, char **argv, t_general_info *info, t_philo *philo, t_share *share);

//ROUTINE
int ft_dead_flag(t_philo *philo);

#endif
