#include "includes/hit.h"

/*
 ふたつの長方形が重なるかどうかをしらべて、
 重なったとき:true, 重ならないとき:false を返す
*/
int isOverlap(float x1, float y1, float w1, float h1, 
  float x2, float y2, float w2, float h2) {
  return x1 < x2 + w2 && x2 < x1 + w1 && y1 < y2 + h2 && y2 < y1 + h1;
}

/*
 ブロックの位置と大きさ、
 ボールの位置と大きさ、ボールの移動速度の情報を与えて
 跳ね返る方向（x軸、y軸の別）を返す
 跳ね返らない時: 0
 x軸のみの時: 1
 y軸のみの時: 2
 x軸, y軸両方の時: 3
*/
int willOverlapByPositionDifferential(float ball_x, float ball_y, float w, float h,
 float bx, float by, float block_width, float block_height, float ball_dx, float ball_dy) {
  int xflag = 0, yflag = 0;
  
  if (!isOverlap(ball_x, ball_y, w, h, bx + ball_dx, by + ball_dy, block_width, block_height)) {
    return 0; // ぶつからなかったら 0を返す
  }
  
  if (isOverlap(ball_x, ball_y, w, h, bx + ball_dx, by, block_width, block_height)) xflag = 1;
  if (isOverlap(ball_x, ball_y, w, h, bx, by + ball_dy, block_width, block_height)) yflag = 2;
  if (xflag + yflag > 0) return xflag + yflag;
  return 3;
}
