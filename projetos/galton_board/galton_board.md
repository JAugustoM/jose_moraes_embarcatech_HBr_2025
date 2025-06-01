---
layout: page
title: Galton Board
---

Autor: José Augusto Alves de Moraes

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, maio de 2025

---

## Objetivos

O objetivo deste projeto foi praticar a criação e o uso de testes unitários, utilizando como base o projeto de leitura de temperatura, que teve sua funcionalidade testada neste projeto.

---

## Componentes Utilizados

Para desenvolver o projeto foi utilizado um botão e o display OLED da BitDogLab utilizando a seguinte pinagem.

| Componente         | Quantidade | GPIO               |
| ------------------ | ---------- | -------------------|
| Botão              | 1          | 5                  |
| Display OLED       | 1          | 14 (SDA), 15 (SDC) |

---

## Utilização

### Dependêcias

- Pico C SDK
- VS Code Raspberry Pi Pico Extension

### Como Compilar e Executar

Para compilar o projeto é possível utilizar a extensão da Pico C SDK ou o terminal, executando o seguinte comando na raiz da pasta `galton_board`.

`cmake -S . -B build -G Ninja && ninja -C build`

Após compilar o projeto basta passar o arquivo para a placa com o comando a seguir:

`sudo picotool load build/src/app/galton_board.elf`
