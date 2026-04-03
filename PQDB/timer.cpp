#include "timer.h"
#include "arduino.h"

// Tempo final da contagem (em milliseconds)
unsigned long int targetTime;

// Configura o timer para contar 'time' milissegundos
void timerStart(unsigned int time) {
    targetTime = millis() + time;
}

// Aguarda até que a contagem termine
void timerWait(void) {
    while (targetTime > millis());
}

// Verifica se a contagem já terminou
// Retorna 1 se o tempo passou, 0 se ainda está contando
int timerFinished(void) {
    return targetTime <= millis() ? 1 : 0;
}

// Gera um atraso bloqueante de 'time' milissegundos
void timerDelay(unsigned int time) {
    timerStart(time);
    timerWait();
}

// Inicializa o timer
void timerInit(void) {
    // O Arduino já inicializa o timer automaticamente
}
