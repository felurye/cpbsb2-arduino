#include "ssd.h"
#include "io.h"
#include "so.h"

// Tabela de conversão para display de 7 segmentos (formato ed0cgafb)
// Valores para dígitos 0-F
static const char valor[] = {
    0xD7, 0x11, 0xCD, 0x5D, 0x1B, 0x5E, 0xDE, 0x15,
    0xDF, 0x5F, 0x9F, 0xDA, 0xC6, 0xD9, 0xCE, 0x8E
};

// Display atualmente ativo (multiplexação)
static char display;
// Valores a serem exibidos em cada dígito
static char v0, v1, v2, v3;

// Define o valor de um dígito específico (0-3)
void ssdDigit(char position, char value) {
    if (position == 0)      { v0 = value; }
    else if (position == 1) { v1 = value; }
    else if (position == 2) { v2 = value; }
    else if (position == 3) { v3 = value; }
}

// Atualiza o display: desliga todos os dígitos e ativa o próximo
// Implementa multiplexação temporal dos 4 dígitos
void ssdUpdate(void) {
    // Desliga todos os displays
    digitalWrite(DISP_1_PIN, LOW);
    digitalWrite(DISP_2_PIN, LOW);
    digitalWrite(DISP_3_PIN, LOW);
    digitalWrite(DISP_4_PIN, LOW);

    // Ativa apenas o dígito atual
    switch (display) {
        case 0:
            soWrite(valor[v0]);
            digitalWrite(DISP_1_PIN, HIGH);
            display = 1;
            break;
        case 1:
            soWrite(valor[v1]);
            digitalWrite(DISP_2_PIN, HIGH);
            display = 2;
            break;
        case 2:
            soWrite(valor[v2]);
            digitalWrite(DISP_3_PIN, HIGH);
            display = 3;
            break;
        case 3:
            soWrite(valor[v3]);
            digitalWrite(DISP_4_PIN, HIGH);
            display = 0;
            break;
        default:
            display = 0;
            break;
    }
}

// Inicializa o display de 7 segmentos
void ssdInit(void) {
    soInit();
    pinMode(DISP_1_PIN, OUTPUT);
    pinMode(DISP_2_PIN, OUTPUT);
    pinMode(DISP_3_PIN, OUTPUT);
    pinMode(DISP_4_PIN, OUTPUT);
    v0 = 0;
    v1 = 0;
    v2 = 0;
    v3 = 0;
}