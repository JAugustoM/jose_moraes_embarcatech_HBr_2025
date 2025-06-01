---
layout: page
title: MQTT
---

Autor: José Augusto Alves de Moraes

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, junho de 2025

---

## Objetivos

O objetivo deste projeto foi praticar conceitos relacionados a conectividade MQTT, criptografia, entre outros. Para isso foi implementado um publisher e um subscriber mqtt que utiliza criptografia leve para enviar mensagens.

---

## Componentes Utilizados

Para desenvolver o projeto foram utilizadas duas BitDogLabs, uma como publisher e uma como subscriber.

---

## Utilização

### Dependêcias

- Pico C SDK
- VS Code Raspberry Pi Pico Extension

### Como Compilar e Executar

Para compilar o projeto é possível utilizar a extensão da Pico C SDK ou o terminal, executando o seguinte comando na raiz da pasta `mqtt`.

`cmake -S . -B build -G Ninja && ninja -C build`

Após compilar o projeto basta passar o arquivo para a placa com o comando a seguir:

`sudo picotool load build/src/app/mensagem.elf`
