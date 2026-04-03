#include "keypad.h"

#include "io.h"
#include "so.h"

static unsigned int keys;

// Vetor com o "nome" dos botões
// U -> up, L -> left, D -> down, R -> right
// S -> start, s -> select
// A ordem é referente a posição dos botões
static const char charKey[] = {'U', 'L', 'D', 'R', 'S',
                               'S', 'S', 'A', 'B', 's'};

unsigned int kpRead(void) { return keys; }
char kpReadKey(void) {
  int i;

  kpDebounce();
  for (i = 0; i < 10; i++) {
    if (kpRead() & (1 << i)) {
      return charKey[i];
    }
  }
  return 0;
}

void kpDebounce(void) {
  unsigned char i;
  static unsigned char tempo;
  static unsigned int newRead;
  static unsigned int oldRead;
  newRead = 0;
  for (int i = 0; i < 5; i++) {
    soWrite(1 << (i + 3));
    if (digitalRead(KEYPAD_1_PIN)) {
      bitSet(newRead, i);
    }
    if (digitalRead(KEYPAD_2_PIN)) {
      bitSet(newRead, i + 5);
    }
  }
  if (oldRead == newRead) {
    tempo--;
  } else {
    tempo = 4;
    oldRead = newRead;
  }
  if (tempo == 0) {
    keys = oldRead;
  }
}
void kpInit(void) {
  soInit();
  pinMode(KEYPAD_1_PIN, INPUT);
  pinMode(KEYPAD_2_PIN, INPUT);
}
