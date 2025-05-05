# Teste Unitário

Autor: José Augusto Alves de Moraes

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, abril de 2025

---

## Objetivos

O objetivo deste projeto foi praticar a criação e o uso de testes unitários, utilizando como base o projeto de leitura de temperatura, que teve sua funcionalidade testada neste projeto.

---

## Componentes Utilizados

Para o desenvolvimento deste projeto não foram usados quaisquer componentes da BitDogLab além do microcontrolador, especificamente o conversor ADC da Pico W para obter a voltagem consumida pelo microcontrolador.

---

## Utilização

### Dependêcias

- Pico C SDK
- VS Code Raspberry Pi Pico Extension

### Como Compilar e Executar

Para compilar o projeto e executar o teste unitario use o seguinte comando:

`cmake -S . -B build -G Ninja -D TARGET_GROUP=test && ninja -C build`

Após compilar o projeto basta passar o arquivo para a placa com o comando a seguir e depois observar o resultado dos testes utilizando algum monitor serial, como o minicom ou o PuTTy.

`sudo picotool load build/src/test/tests.elf`
