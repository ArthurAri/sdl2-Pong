#include "Player.h"
#include <iostream>
#include <string>
#include <utils/Vector.hpp>

Player::Player(float x, float y, float w, float h, float speed)
    : Object(Vector3(x, y, 0)), speed(speed)
{
    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;
}

Math::Vector2 input;
float inpx = 0;
float inpy = 0;

bool w;
bool a;
bool s;
bool d;

void ResetInput()
{
    w = false;
    a = false;
    s = false;
    d = false;
}

void Player::update(float deltaTime)
{
    if (w && s || !w && !s)input.y = 0;
    if (a && d || !a && !d)input.x = 0;
    if (w && !s)input.y = -1;
    if (!w && s)input.y = 1;
    if (d && !a)input.x = 1;
    if (!d && a)input.x = -1;

    std::cout << w << s << a << d << std::endl;

    Vector2 normalizedInput;
    // if (input != Math::Vector2::zero)
    //     normalizedInput /= input.magnitude();
    position += input * Time::deltaTime * 100;
    rect.x = SDL_round(position.x);
    std::cout << position.x << std::endl;
    rect.y = SDL_round(position.y);
}
void Player::handleInput(const SDL_Event& event)
{
    bool isDown = (event.type == SDL_KEYDOWN);

    switch (event.key.keysym.sym) {
        case SDLK_w: w = isDown; break;
        case SDLK_a: a = isDown; break;
        case SDLK_s: s = isDown; break;
        case SDLK_d: d = isDown; break;
    }
}

void Player::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 100, 60, 255);
    SDL_RenderFillRect(renderer, &rect);
}
