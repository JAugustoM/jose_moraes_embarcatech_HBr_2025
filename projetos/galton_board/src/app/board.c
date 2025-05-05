#include "board.h"
#include "pico/rand.h"
#include "screen_handler.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int piles[9] = {0};
int count = 0;
List *list;

const uint8_t MAX_LEFT = 1;
const uint8_t MAX_RIGHT = 19;

char INIT_STATE[8][22] = {
    "|                   |", "|         *         |", "|        * *        |",
    "|       * * *       |", "|      * * * *      |", "|     * * * * *     |",
    "|    * * * * * *    |", "|   * * * * * * *   |",
    // 3 5 7 9 11 13 15 17
    // 0 1 2 3 4  5  6  7  8
};

Dir coll(Ball *ball) {
  if (ball->pos_x == MAX_LEFT) {
    ball->pos_x++;
    return right;
  }

  if (ball->pos_x == MAX_RIGHT) {
    ball->pos_x--;
    return left;
  }

  Dir dir = get_rand_32() % 2;

  if (dir == left)
    ball->pos_x--;

  else
    ball->pos_x++;

  return dir;
}

List *create_list() {
  list = malloc(sizeof(List));

  if (list != NULL) {
    list->first = NULL;
    list->last = NULL;
  }

  return list;
}

Ball *create_ball() {
  Ball *ball = malloc(sizeof(Ball));

  if (ball != NULL) {
    ball->pos_x = 10;
    ball->pos_y = 0;
    ball->falling = true;
    ball->next_ball = NULL;

    if (list->first == NULL) {
      list->first = ball;
      list->last = ball;

    } else {
      Ball *last_ball = list->last;
      last_ball->next_ball = ball;
      list->last = ball;
    }

    count++;

    return ball;
  }

  return NULL;
}

Ball *remove_ball(Ball *ball) {
  Ball *next_ball = ball->next_ball;
  list->first = next_ball;

  int pile = (ball->pos_x / 2) - 1;

  piles[pile]++;

  if (piles[8] < piles[pile])
    piles[8]++;

  free(ball);
  return next_ball;
}

void tick() {
  Ball *ball = list->first;

  while (ball != NULL) {
    ball->pos_y++;

    if (ball->pos_y == 8) {
      ball = remove_ball(ball);
    } else {
      coll(ball);
      ball = ball->next_ball;
    }
  }
}

void draw_board() {
  char text[8][22];
  snprintf(text[0], 22, "|               %4d|", count);

  for (int i = 1; i < 8; i++)
    strcpy(text[i], INIT_STATE[i]);

  Ball *ball = list->first;

  while (ball != NULL) {
    text[ball->pos_y][ball->pos_x] = 'o';
    ball = ball->next_ball;
  }

  draw_screen(text);
}
