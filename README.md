# CPBSB2 - Arduino

Projetos desenvolvidos durante a **CPBSB** (Campus Party Brasília) para demonstração de programação em Arduino utilizando o shield PQDB Mini.

## Projetos

### [PQDB](./PQDB/) - Biblioteca de Drivers

Biblioteca de drivers para o shield PQDB (Plataforma de Desenvolvimento Brasileiro), com suporte a:

- Display Nokia 5110 (LCD gráfico 84x48)
- Teclado matricial 4x4
- Display de 7 segmentos (4 dígitos via 74HC595)
- Conversor A/D para sensores analógicos
- LED RGB, Buzzer (PWM), Serial, I2C
- RTC DS1307, Timer e mais

Consulte o [README do PQDB](./PQDB/README.md) para mais detalhes.

### [snake](./snake/) - Jogo da Cobrinha

Implementação do clássico jogo Snake para Arduino com shield PQDB Mini.

- Controle via 4 botões (cima, baixo, esquerda, direita)
- Display Nokia 5110 para gráficos
- Detecção de colisão com paredes e com o próprio corpo

Consulte o [README do Snake](./snake/README.md) para mais detalhes.

## Hardware

- **Arduino Uno Rev. 3**
- **Shield PQDB Mini**

Para esquemáticos e documentação do hardware:

- https://github.com/augustocrmattos/PQDB-Hardware
- https://embarcados.com.br/pqdb-mini/

## Como Usar

1. Copie as pastas `PQDB` e `snake` para o diretório `libraries` do Arduino IDE
2. Abra o sketch desejado (`PQDB.ino` ou `snake.ino`)
3. Compile e faça o upload para o Arduino com o shield PQDB

## Licença

MIT License
