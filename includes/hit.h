int isOverlap(
    float x1, float y1, float w1, float h1,
    float x2, float y2, float w2, float h2);

int willOverlapByPositionDifferential(
    float ball_x, float ball_y, float w, float h,
    float bx, float by,
    float block_width, float block_height,
    float ball_dx, float ball_dy);
