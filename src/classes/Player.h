#ifndef PLAYER_H
#define PLAYER_H

#include <Time.hpp>
#include <abstract/Object.hpp>
#include <SDL2/SDL.h>

class Player : public Object {
public:
    Player(float x, float y, float w, float h, float speed);
    void handleInput(const SDL_Event& event);
    void update(float deltaTime);
    void render(SDL_Renderer* renderer);
private:
    SDL_Rect rect;
    int speed;
};

#endif
