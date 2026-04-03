# Snake Game - Arduino/PQDB

Implementação do clássico jogo da cobrinha (Snake) para Arduino, rodando no shield PQDB Mini.

**Autor:** Rafael de Moura Moreira \<rafaelmmoreira@gmail.com\>

## Hardware Necessário

- Arduino Uno Rev. 3
- Shield PQDB Mini (ou compatível)
- 4 botões (usados para controle direcional)
- Display Nokia 5110 (84x48 pixels)

> **Nota:** Esta implementação supõe o uso do shield PQDB Mini. Nem todos os componentes do shield são utilizados — apenas 4 botões e o display Nokia 5110 são necessários para o jogo.

## Como Jogar

1. **Movimento:** Use os 4 botões para controlar a direção da cobrinha (cima, baixo, esquerda, direita)
2. **Objetivo:** Coma a comida (quadrado com borda) para fazer a cobra crescer
3. **Game Over:** Se a cobra colidir com as paredes ou com ela mesma, o jogo termina
4. **Vitória:** Preencha todo o mapa (252 posições) para vencer

## Estrutura do Jogo

O jogo utiliza uma arquitetura de loop simples:

```
loop_Input()  → Lê entrada do teclado
loop_Update()  → Atualiza posições e verifica colisões
loop_Draw()   → Desenha o estado atual na tela
```

## Especificações

- **Campo de jogo:** 21 x 12 células
- **Cada célula:** 4x4 pixels no display
- **Tamanho máximo da cobra:** 252 nós (mapa completo)
- **Delay entre frames:** ~100ms

## Driver do Display

Este projeto utiliza os drivers do shield PQDB Mini.

Para instruções detalhadas das ligações do circuito, consulte:

- **Hardware:** https://github.com/augustocrmattos/PQDB-Hardware
- **Estudo:** https://embarcados.com.br/pqdb-mini/

## Compilação

1. Copie a pasta `snake` para o diretório de sketches do Arduino IDE
2. Certifique-se de que a pasta `PQDB` (biblioteca de drivers) está no diretório `libraries`
3. Abra `snake.ino` e compile

## Sobre o Projeto

Este projeto foi desenvolvido durante a **CPBSB** (Campus Party Brasília) — um dos maiores eventos de tecnologia e inovação do Brasil.
