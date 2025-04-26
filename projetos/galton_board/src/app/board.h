#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include <stdint.h>

typedef enum dir { left, right } Dir;

typedef struct ball {
  uint8_t pos_x;
  uint8_t pos_y;
  bool falling;
  struct ball *next_ball;
} Ball;

typedef struct ball_list {
  Ball *first;
  Ball *last;
} List;

extern int piles[9];
extern List *list;
extern char INIT_STATE[8][22];

extern Dir coll(Ball *ball);
extern List *create_list();
extern Ball *create_ball();
extern Ball *remove_ball(Ball *ball);
extern void tick();
extern void draw_board();

#endif
