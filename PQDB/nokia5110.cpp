#include "nokia5110.h"
#include <Arduino.h>
#include <avr/pgmspace.h>

// Inicializa o display Nokia 5110
// vop: contraste (0xC0 típico para 5V)
// tempCoef: coeficiente de temperatura (0x07 padrão)
// bias: modo bias (0x14 típico)
void initializeDisplay(byte vop, byte tempCoef, byte bias) {
    pinMode(RST, OUTPUT);
    pinMode(DC, OUTPUT);
    pinMode(DIN, OUTPUT);
    pinMode(CLK, OUTPUT);

    // Reset do display
    digitalWrite(RST, LOW);
    digitalWrite(RST, HIGH);

    // Comandos estendidos para configuração
    LcdWriteCmd(0x21);  // H=1: comandos estendidos ativos

    // Configura contraste (Vop)
    // Fórmula: VLCD = 3.06 + VOP × 0.06
    // Exemplo: 5V = 3.06 + 32 × 0.06 → VOP = 0xC0
    LcdWriteCmd(vop);

    // Coeficiente de temperatura (empirico, tipico 0x04)
    LcdWriteCmd(tempCoef);

    // Bias mode 1:40 (valor ótimo do datasheet: 0x14)
    LcdWriteCmd(bias);

    // Retorna para comandos básicos
    LcdWriteCmd(0x20);

    // Modo de vídeo normal (sem inversão)
    LcdWriteCmd(0x0C);
}

// Escreve uma string no display
void LcdWriteString(char *characters) {
    while (*characters) {
        LcdWriteCharacter(*characters++);
    }
}

// Escreve um caractere no display
// Busca o padrão de pixels na tabela ASCII armazenada em PROGMEM
void LcdWriteCharacter(char character) {
    for (int i = 0; i < 5; i++) {
        byte temp = pgm_read_byte_near(ASCII + ((character - 0x20) * 5) + i);
        LcdWriteData(temp);
    }
    LcdWriteData(0x00);  // Espaço entre caracteres
}

// Envia dado ao display (pinos DC=HIGH para dados)
void LcdWriteData(byte dat) {
    digitalWrite(DC, HIGH);
    shiftOut(DIN, CLK, MSBFIRST, dat);
}

// Move o cursor para posição (x, y)
// x: coluna (0-83), y: linha (0-5)
void LcdXY(int x, int y) {
    LcdWriteCmd(0x80 | x);  // Comando de coluna
    LcdWriteCmd(0x40 | y);  // Comando de linha
}

// Envia comando ao display (pinos DC=LOW para comandos)
void LcdWriteCmd(byte cmd) {
    digitalWrite(DC, LOW);
    shiftOut(DIN, CLK, MSBFIRST, cmd);
}