#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // Necessário para a função sleep()

// Função que cada thread irá executar
void *trabalho_da_thread(void *arg) {
    int id = *((int *)arg); // Recebe o ID da thread
    
    for (int i = 1; i <= 5; i++) {
        printf("Thread %d executando: passo %d\n", id, i);
        sleep(1); // Pausa de 1 segundo para visualizarmos a alternância na CPU
    }
    
    // Encerra a thread atual
    pthread_exit(NULL); 
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    printf("Processo principal (Main) iniciado.\n");

    // Cria as threads, passando a função e o ID correspondente
    pthread_create(&thread1, NULL, trabalho_da_thread, &id1);
    pthread_create(&thread2, NULL, trabalho_da_thread, &id2);

    // O processo principal aguarda o término das threads especificadas
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Processo principal (Main) finalizado.\n");
    return 0;
}