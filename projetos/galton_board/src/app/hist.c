#include "hist.h"
#include "board.h"
#include "screen_handler.h"
#include <math.h>
#include <stdio.h>

bool hist = false;

float col_ceil = 8;

void draw_hist() {
  while (col_ceil < piles[8]) {
    col_ceil++;
  }
  char text[8][22] = {
      "                     ", "                     ", "                     ",
      "                     ", "                     ", "                     ",
      "                     ", "                     ",
  };

  char ceil_number[5];
  char middle_number[5];

  snprintf(ceil_number, 5, "%4.0f", col_ceil);
  snprintf(middle_number, 5, "%4.0f", ceil(col_ceil / 2));

  for (int i = 0; i < 4; i++) {
    text[0][i] = ceil_number[i];
  }

  for (int i = 0; i < 4; i++) {
    text[4][i] = middle_number[i];
  }

  float cols[8];

  for (int i = 0; i < 8; i++) {
    cols[i] = ceil((piles[i] / col_ceil) * 8);
  }

  for (int i = 0; i < 8; i++) {
    for (int j = 7; j >= (8 - cols[i]); j--) {
      int col1 = 5 + (2 * i);
      int col2 = 6 + (2 * i);
      text[j][col1] = 'o';
      text[j][col2] = 'o';
    }
  }

  draw_screen(text);
}
