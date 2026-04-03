#include "io.h"

// LED RGB conectado aos pinos do shield PQDB
// Bit 0 = vermelho, Bit 1 = verde, Bit 2 = azul

// Define a cor do LED RGB usando mask de bits
// 0x01 = vermelho, 0x02 = verde, 0x04 = azul
// Combinações: 0x03=amarelo, 0x05=magenta, 0x06=ciano, 0x07=branco
void rgbColor(int led) {
  digitalWrite(LED_RED_PIN, (led & 1) ? HIGH : LOW);
  digitalWrite(LED_GREEN_PIN, (led & 2) ? HIGH : LOW);
  digitalWrite(LED_BLUE_PIN, (led & 4) ? HIGH : LOW);
}

// Acende os LEDs especificados pela mask
void turnOn(int led) {
  if (led & 1) {
    digitalWrite(LED_RED_PIN, HIGH);
  }
  if (led & 2) {
    digitalWrite(LED_GREEN_PIN, HIGH);
  }
  if (led & 4) {
    digitalWrite(LED_BLUE_PIN, HIGH);
  }
}

// Apaga os LEDs especificados pela mask
void turnOff(int led) {
  if (led & 1) {
    digitalWrite(LED_RED_PIN, LOW);
  }
  if (led & 2) {
    digitalWrite(LED_GREEN_PIN, LOW);
  }
  if (led & 4) {
    digitalWrite(LED_BLUE_PIN, LOW);
  }
}

// Inicializa os pinos do LED RGB como saída
void rgbInit(void) {
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);
}
