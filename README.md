# philosophers

***This project focuses on the basics of threading a process and how to work on the same memory space. We learnt how to make `threads`, and discover the `mutex`, `semaphore` and `shared memory`.***

## Project requirements

- A number of philosophers are sitting at a round table doing one of three things: `eating`, `thinking` or `sleeping`. 
  
- The philosophers sit at a circular table with a large bowl of spaghetti in the center. There are some forks on the table. As spaghetti is difficult to serve and philo_eat with a single fork, it is assumed that a philosopher `must philo_eat with two forks`, one for each hand.

- The philosophers must never be starving. Every philosopher needs to eat. Philosophers don’t speak with each other. Philosophers don’t know when another philosopher is about to die. 

- Each time a philosopher has finished eating, he will drop his forks and start sleeping. When a philosopher is done sleeping, he will start thinking. The simulation stops when a philosopher dies.

### Mandatory part
- Each philosopher is a `thread`.
- There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there is only one fork on the table.
- To prevent philosophers from duplicating forks, we should protect the forks state
with a `mutex` for each of them.

### Bonus part

- All the forks are put in the middle of the table.
- They have no states in memory but the number of available forks is represented by
a `semaphore.
- Each philosopher should be a process. But the main process should not be a
philosopher.

## How to test

- These parameters are required in order when running the executable: `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `number_of_times_each_philosopher_must_eat(optional)`
- Do not test with more than 200 philosophers
- Do not test with `time_to_die` `time_to_eat` `time_to_sleep` under 60ms
- Test with `5 800 200 200`, no one should die
- Test with `5 800 200 200 7`, the simulation should stop when all the philosophers have eaten at least 7 times each

> Run the following commands:

```shell
$ git clone https://github.com/prranges/philosophers.git
$ cd philo - for mandatory part
$ cd philo_bonus - for mandatory part
$ make
$ ./philo_one 5 800 200 200
```
