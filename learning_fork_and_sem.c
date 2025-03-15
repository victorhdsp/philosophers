#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

int main(void) {
    const char  *semName = "/meu_semaforo";
    sem_t       *semaphore;
    pid_t       pid[2];
    int         index;

    semaphore = sem_open(semName, O_CREAT | O_EXCL, 0644, 0);
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        sem_unlink(semName);
        exit(EXIT_FAILURE);
    }
    
    index = 0;
    while (index < 2)
    {
        pid[index] = fork();
        if (pid[index] < 0) {
            perror("sem_open");
            sem_close(semaphore);
            sem_unlink(semName);
            exit(EXIT_FAILURE);
        }
        else if (pid[index] == 0) {
            sleep(4);
            printf("filho\n");
            sem_post(semaphore);
            sem_post(semaphore);
            sem_close(semaphore);
            exit(EXIT_SUCCESS);
        }
        else {
            printf("pai, %d\n", pid[index]);
            kill(pid[index], SIGKILL);
            //waitpid(pid[index], NULL, 0);
            //sem_wait(semaphore);
            sem_close(semaphore);
            sem_unlink(semName);
        }
        index++;
    }
    
    return 0;
}
