# Leitor de Temperatura do MCU

Autor: José Augusto Alves de Moraes

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, abril de 2025

---

## Objetivos

O objetivo deste projeto foi implementar a leitura da temperatura, em graus Celsius, do MCU da BitDogLab calculado utilizando a fórmula disponibilizada no manual da Pi Pico W que multiplica a voltagem interna do MCU multiplicado por um fator de conversão para determinar, aproximadamente, a temperatura do microcontrolador.

---

## Componentes Utilizados

Para o desenvolvimento deste projeto não foram usados quaisquer componentes da BitDogLab além do microcontrolador.

---

## Utilização

### Dependêcias

- Pico C SDK
- VS Code Raspberry Pi Pico Extension

### Como Compilar e Executar

Dentro do VS Code, selecione a opção "Compile Pico Project" usando o menu de comandos, Ctrl+Shift+P por padrão para abrir o menu, para compilar o projeto. Após compilado, conecte a placa em modo Bootsel, pressionando o botão Bootsel enquanto conecta a placa no computador feito isso passe o arquivo pomodoro.elf para a placa usando a ferramenta picotool load da Pico C SDK ou passe o arquivo manualmente usando um gestor de arquivos, ou o terminal.
