#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define NO_COLOR "\033[0m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define BLUE "\033[36m"
# define GREY "\033[90m"
# define YELLOW "\033[33m"

typedef struct s_info
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_times_each_philo_must_eat;
	unsigned long	start_time;
	int				nbr_philo_finish;
	int				stop;
	pthread_mutex_t	mutex_write;
}					t_info;
/*Contient les paramètres de simulation qui sont communs à tous les philosophes.*/

typedef struct s_philo
{
	t_info			*info;
	int				id;
	pthread_t		thread_id;
	int				dead;
	pthread_mutex_t	mutex_philo_dead;
	unsigned long	time_last_meal;
	pthread_mutex_t	mutex_finish_diner;
	pthread_mutex_t	mutex_time_eat;
	int				nbr_meal;
	// int				finish_diner;

	// int				first_action;
	pthread_mutex_t	*mutex_right_fork;
	pthread_mutex_t	mutex_left_fork;

}					t_philo;

typedef struct s_monitor
{
	t_info			*info;
	t_philo			*philo;

	pthread_t		monitor;

}					t_monitor;

// UTILS
unsigned long		ft_timestamp_ms(void);
void				ft_writing_status(char *str, t_monitor *monitor,
						const char *color, unsigned long timestamp);

// INIT STRUCT
void				ft_init_struct(int argc, char **argv, t_monitor *monitor);

// ROUTINE
int					ft_dead_flag(t_monitor *monitor);
void				ft_count_philo_died(t_monitor *monitor);
void				ft_count_philo_finish(t_monitor *monitor);
void				*ft_routine(void *thread_id);

// THREAD
void				ft_create_philosopher_threads(t_monitor *monitor);
void				ft_create_monitoring_thread(t_monitor *monitor);

// MONITORING
void				*ft_monitoring(void *philosopher);

// PARSING
int					ft_atoi(char *str, int result);
void				ft_parsing(int argc, char **argv);
void				ft_is_error(int code_error);

// UTILS COUNT
void				ft_count_philo_finish(t_monitor *monitor);
void				ft_count_philo_died(t_monitor *monitor);
#endif
