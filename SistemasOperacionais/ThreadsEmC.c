#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *Barra(void *arg){
    int i = *((int *)arg);
    for(int j = 0 ; j < 100; j = j + 5){
        printf("thread %d contagem: %d%%\n", i, j);
        usleep(250000); // Sleep for 250 milliseconds
    }
    return NULL;
}

int main(){
    pthread_t threads[5];
    int thread_ids[5];

    for(int i = 0; i < 5; i++){
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, Barra, &thread_ids[i]);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}