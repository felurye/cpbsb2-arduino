# PQDB - Platforma de Desenvolvimento Brasileiro

Biblioteca de drivers para o shield PQDB (Platforma de Desenvolvimento Brasileiro), desenvolvida para Arduino Uno.

## Hardware Suportado

- **Arduino Uno Rev. 3**
- **Shield PQDB Mini**

## Módulos Disponíveis

| Driver              | Arquivo            | Descrição                      |
| ------------------- | ------------------ | ------------------------------ |
| Display Nokia 5110  | `nokia5110.cpp/.h` | Display LCD gráfico 84x48      |
| Teclado Matricial   | `keypad.cpp/.h`    | Matriz de botões 4x4           |
| Display 7 Segmentos | `ssd.cpp/.h`       | 4 dígitos via 74HC595          |
| Conversor AD        | `ad.cpp/.h`        | Leitura de sensores analógicos |
| PWM/Buzzer          | `pwm.cpp/.h`       | Controle de buzzer             |
| LED RGB             | `rgb.cpp/.h`       | LED RGB (pwm)                  |
| Serial              | `serial.cpp/.h`    | Comunicação UART               |
| I2C                 | `i2c.cpp/.h`       | Protocolo I2C                  |
| DS1307              | `ds1307.cpp/.h`    | RTC (Relógio de tempo real)    |
| Timer               | `timer.cpp/.h`     | Controle de delays             |
| Console             | `console.c/.h`     | Funções de console             |
| Shift Register      | `so.cpp/.h`        | Driver 74HC595                 |

## Arquivos Principais

- `PQDB.ino` - Programa de demonstração de todos os módulos
- `io.h` - Mapeamento de pinos do shield

## Como Usar

1. Copie a pasta `PQDB` para o diretório `libraries` do Arduino IDE
2. Abra o sketch `PQDB.ino` como exemplo
3. Compile e faça o upload para o Arduino com o shield PQDB

## Dependências

Este projeto utiliza apenas bibliotecas nativas do Arduino. Para mais informações sobre o shield PQDB, consulte o repositório oficial:

- **Hardware:** https://github.com/augustocrmattos/PQDB-Hardware
- **Estudo:** https://embarcados.com.br/pqdb-mini/

## Sobre o Projeto

Este projeto foi desenvolvido durante a **CPBSB** (Campus Party Brasília) — um dos maiores eventos de tecnologia e inovação do Brasil.
