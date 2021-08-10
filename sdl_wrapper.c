#include "includes/sdl_wrapper.h"

#include <SDL2/SDL.h>

SDL_Window *window;
SDL_Renderer *renderer;

int width = 0, height = 0;
int mouseX = 0, mouseY = 0;

int size(int w, int h) {
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDLの初期化に失敗しました %s", SDL_GetError());
        return 1;
    }


    if (SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer)) {
        SDL_Log("ウィンドウかレンダラの初期化に失敗しました", SDL_GetError());
        return 2;
    }

    width = w;
    height = h;
}

void draw_done() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                exit(0);
        }
    }
    SDL_Delay(16);
    SDL_RenderPresent(renderer);
    SDL_GetMouseState(&mouseX, &mouseY);
}

void background(int r, int g, int b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
}

void rect(int x, int y, int w, int h) {
    SDL_Rect rect;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

void println(const char message) {
    SDL_Log(message);
}
