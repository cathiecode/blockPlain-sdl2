#include "includes/sdl_wrapper.h"

#include "includes/hit.h"
#include "includes/block_plain.h"
#include "includes/block_function.h"

float block_width, block_height = 40.0;

/*
 10個のブロックを初期化する
*/
void initBlocks() {
  for (int i = 0; i < BLOCK_LENGTH; i++) {
    blocks[i] = 2;
  }
  block_width = width / BLOCK_LENGTH; // ブロックの幅を決める
}

/*
 10個のブロックのどれかにぶつかっていたら跳ね返る
*/
void checkBlocksAndBounceBall() {
  for (int i = 0; i < BLOCK_LENGTH; i++) {
    if (blocks[i] > 0) {
      int ret = willOverlapByPositionDifferential(i * block_width, 40, block_width, block_height, ball_x, ball_y, ball_width, ball_height, ball_dx, ball_dy);
      if (ret > 0) {
        if (ret == 1) {
          ball_dx = -ball_dx;
        } else if (ret == 2) {
          ball_dy = -ball_dy;
          blocks[i]--;
        } else if (ret == 3) {
          ball_dx = -ball_dx;
          ball_dy = -ball_dy;
          blocks[i]--;
        }
        return;
      }
    }
  }  
}

/*
 10個のブロックを表示する
*/
void showBlocks() {
  for (int i = 0; i < BLOCK_LENGTH; i++) {
    if (blocks[i] > 0) {
      /* text(blocks[i], i * block_width, block_height); // 消すために必要なhitの個数の表示 */
      rect(i * block_width, 40, block_width, block_height); // ブロックの形の表示
    }
  }
}
