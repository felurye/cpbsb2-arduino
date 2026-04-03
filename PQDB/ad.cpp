// -----------------------------------------------------------------------
//   Conversor Analógico-Digital (ADC)
//   Autor: Rodrigo Maximiano Antunes de Almeida
//   Adaptado para Arduino/PQDB
//   Licença: GNU GPL 2
// -----------------------------------------------------------------------
//   Leitura de sensores analógicos através do conversor AD do Arduino.
//   Canais disponíveis: A0, A1, A2, A3
// -----------------------------------------------------------------------

#include "arduino.h"
#include "ad.h"

// Mapeamento dos pinos analógicos para canais do ADC
static const uint8_t pinMap[] = {A0, A1, A2, A3};

// Inicializa o conversor AD
void adInit(void) {
    // O Arduino já configura o ADC automaticamente
}

// Lê o valor analógico do canal especificado (0-3)
// Retorna -1 se o canal for inválido
int adRead(int channel) {
    if (channel < 0 || channel > 3) {
        return -1;
    }
    return analogRead(pinMap[channel]);
}
