#include "includes/block_plain.h"

#include "includes/sdl_wrapper.h"
#include "includes/ball_function.h"
#include "includes/block_function.h"
#include "includes/racket_function.h"


int blocks[BLOCK_LENGTH];
float ball_x, ball_y, ball_width, ball_height, ball_dx, ball_dy;
float racket_width = 50.0, racket_height = 3.0;

void main(void) {
    size(400, 300);
    initBall();
    initBlocks();

    while (1) {
        ball_x += ball_dx; // ball_dx は1フレームごとにx方向に動く距離(速度)
        ball_y += ball_dy; // ball_dy は1フレームごとにy方向に動く距離(速度)
        
        background(192, 192, 255);
        rect(ball_x, ball_y, ball_width, ball_height); // ball

        checkBlocksAndBounceBall();
        showBlocks();

        bounceBallByRacketOrNot(height - 50);
        showRacket(height - 50);

        // 落ちた時の判定
        if (ball_y + ball_height >= height) {
            initBall();
            initBlocks();
        }
        if (ball_x < 0 || ball_x + ball_width >= width) { // 左右の壁のどちらかに突き抜けている場合
            ball_dx = -ball_dx;
        }
        if (ball_y < 0) { // 上の壁に突き抜けている場合
            ball_dy = -ball_dy;
        }
    
        draw_done();
    }
}
