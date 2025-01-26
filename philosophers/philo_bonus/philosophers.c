#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philosopher {
    int             id;
    int             left_fork;
    int             right_fork;
    int             meals_eaten;
    long long       last_meal;
    pthread_t       thread;
    struct s_data   *data;
} t_philosopher;

typedef struct s_data {
    int             num_philosophers;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             meals_required;
    int             someone_died;
    long long       start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    t_philosopher  *philosophers;
} t_data;

long long get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void print_state(t_data *data, int id, char *state)
{
    pthread_mutex_lock(&data->print_mutex);
    if (!data->someone_died)
        printf("%lld %d %s\n", get_time() - data->start_time, id + 1, state);
    pthread_mutex_unlock(&data->print_mutex);
}

void take_forks(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
    print_state(philo->data, philo->id, "has taken a fork");
    pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
    print_state(philo->data, philo->id, "has taken a fork");
}

void put_down_forks(t_philosopher *philo)
{
    pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

void *philosopher_routine(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;
    t_data *data = philo->data;

    if (philo->id % 2)
        usleep(1000);
    
    while (!data->someone_died && 
           (data->meals_required == -1 || philo->meals_eaten < data->meals_required))
    {
        // Think
        print_state(data, philo->id, "is thinking");
        
        // Take forks
        take_forks(philo);
        
        // Eat
        print_state(data, philo->id, "is eating");
        philo->last_meal = get_time();
        usleep(data->time_to_eat * 1000);
        philo->meals_eaten++;
        
        // Put down forks
        put_down_forks(philo);
        
        // Sleep
        print_state(data, philo->id, "is sleeping");
        usleep(data->time_to_sleep * 1000);
    }
    return NULL;
}

void *death_monitor(void *arg)
{
    t_data *data = (t_data *)arg;
    int i;
    
    while (1)
    {
        for (i = 0; i < data->num_philosophers; i++)
        {
            if (get_time() - data->philosophers[i].last_meal > data->time_to_die)
            {
                pthread_mutex_lock(&data->print_mutex);
                printf("%lld %d died\n", get_time() - data->start_time, i + 1);
                data->someone_died = 1;
                pthread_mutex_unlock(&data->print_mutex);
                return NULL;
            }
        }
        if (data->meals_required != -1)
        {
            int all_ate = 1;
            for (i = 0; i < data->num_philosophers; i++)
            {
                if (data->philosophers[i].meals_eaten < data->meals_required)
                {
                    all_ate = 0;
                    break;
                }
            }
            if (all_ate)
                return NULL;
        }
        usleep(1000);
    }
    return NULL;
}

int init_data(t_data *data, int argc, char **argv)
{
    if (argc != 5 && argc != 6)
    {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
        return 0;
    }
    
    data->num_philosophers = atoi(argv[1]);
    data->time_to_die = atoi(argv[2]);
    data->time_to_eat = atoi(argv[3]);
    data->time_to_sleep = atoi(argv[4]);
    data->meals_required = (argc == 6) ? atoi(argv[5]) : -1;
    data->someone_died = 0;
    
    if (data->num_philosophers <= 0 || data->time_to_die <= 0 || 
        data->time_to_eat <= 0 || data->time_to_sleep <= 0 || 
        (argc == 6 && data->meals_required <= 0))
    {
        printf("Invalid arguments\n");
        return 0;
    }
    
    return 1;
}

int init_mutexes(t_data *data)
{
    int i;
    
    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
    if (!data->forks)
        return 0;
        
    for (i = 0; i < data->num_philosophers; i++)
    {
        if (pthread_mutex_init(&data->forks[i], NULL))
            return 0;
    }
    
    if (pthread_mutex_init(&data->print_mutex, NULL))
        return 0;
        
    return 1;
}

int init_philosophers(t_data *data)
{
    int i;
    
    data->philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);
    if (!data->philosophers)
        return 0;
        
    for (i = 0; i < data->num_philosophers; i++)
    {
        data->philosophers[i].id = i;
        data->philosophers[i].meals_eaten = 0;
        data->philosophers[i].last_meal = get_time();
        data->philosophers[i].data = data;
        data->philosophers[i].left_fork = i;
        data->philosophers[i].right_fork = (i + 1) % data->num_philosophers;
    }
    
    return 1;
}

int create_threads(t_data *data)
{
    int i;
    pthread_t monitor;
    
    data->start_time = get_time();
    
    for (i = 0; i < data->num_philosophers; i++)
    {
        if (pthread_create(&data->philosophers[i].thread, NULL, 
                          philosopher_routine, &data->philosophers[i]))
            return 0;
    }
    
    if (pthread_create(&monitor, NULL, death_monitor, data))
        return 0;
        
    for (i = 0; i < data->num_philosophers; i++)
        pthread_join(data->philosophers[i].thread, NULL);
    pthread_join(monitor, NULL);
    
    return 1;
}

void cleanup(t_data *data)
{
    int i;
    
    for (i = 0; i < data->num_philosophers; i++)
        pthread_mutex_destroy(&data->forks[i]);
    pthread_mutex_destroy(&data->print_mutex);
    
    free(data->forks);
    free(data->philosophers);
}

int main(int argc, char **argv)
{
    t_data data;
    
    if (!init_data(&data, argc, argv))
        return 1;
    
    if (!init_mutexes(&data))
    {
        printf("Failed to initialize mutexes\n");
        return 1;
    }
    
    if (!init_philosophers(&data))
    {
        printf("Failed to initialize philosophers\n");
        cleanup(&data);
        return 1;
    }
    
    if (!create_threads(&data))
    {
        printf("Failed to create threads\n");
        cleanup(&data);
        return 1;
    }
    
    cleanup(&data);
    return 0;
}