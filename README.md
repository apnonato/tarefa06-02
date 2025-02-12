# Projeto Tarefa_U4C7O123E

Este projeto é um exemplo de controle de um servo motor e LEDs RGB utilizando a Raspberry Pi Pico W. É destinado a fins de estudo e aprendizado, e por isso é livre para uso e modificação.

## Estrutura do Projeto

- `tarefa_U4C7O123E.c`: Código fonte principal que configura e controla o servo motor e os LEDs RGB.
- `CMakeLists.txt`: Arquivo de configuração do CMake para compilar o projeto.
- `diagram.json`: Diagrama de conexão dos componentes no Wokwi.
- `pico_sdk_import.cmake`: Script para importar o SDK da Raspberry Pi Pico.
- `wokwi.toml`: Configuração do Wokwi para simulação do firmware.

## Requisitos

- Raspberry Pi Pico W
- Servo motor
- LEDs RGB
- SDK da Raspberry Pi Pico

## Funcionamento

O código configura o PWM para controlar um servo motor e LEDs RGB. O servo motor é posicionado em 0°, 90° e 180° graus, enquanto os LEDs mudam de cor conforme a posição do servo.

## Autor

- Andressa Peixoto Notato

## Licença

Este projeto é destinado a fins de estudo e aprendizado, e por isso é livre para uso e modificação.