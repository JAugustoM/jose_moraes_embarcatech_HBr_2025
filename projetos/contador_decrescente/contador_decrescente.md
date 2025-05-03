---
layout: page
title: Contador Decrescente
---

Autor: José Augusto Alves de Moraes

Curso: Residência Tecnológica em Sistemas Embarcados

Instituição: EmbarcaTech - HBr

Brasília, abril de 2025

---

## Objetivos

O objetivo deste projeto foi implementar um contador que consegue, enquanto ativo, registrar a quantidade de vezes que um botão é pressionado. O usuário também deve ser capaz de reiniciar o contador a qualquer momento.

---

## Componentes Utilizados

Para o desenvolvimento deste projeto foi usada exclusivamente a BitDogLab usando a seguinte pinagem.

| Componentes        | Quantidade | GPIO               |
| ------------------ | ---------- | -------------------|
| Botões             | 2          | 5, 6               |
| Display OLED       | 1          | 14 (SDA), 15 (SDC) |

---

## Utilização

### Dependêcias

- Pico C SDK
- VS Code Raspberry Pi Pico Extension

### Como Compilar e Executar

Dentro do VS Code, selecione a opção "Compile Pico Project" usando o menu de comandos, Ctrl+Shift+P por padrão para abrir o menu, para compilar o projeto. Após compilado, conecte a placa em modo Bootsel, pressionando o botão Bootsel enquanto conecta a placa no computador feito isso passe o arquivo pomodoro.elf para a placa usando a ferramenta picotool load da Pico C SDK ou passe o arquivo manualmente usando um gestor de arquivos, ou o terminal.

Alternativamente, o projeto pode ser compilado com o seguinte comando:

`cmake -S . -B build -G Ninja && ninja -C build`

Após executar o comando basta passar o arquivo para a placa, como explicado anteriormente.
