#pragma once
#include <SDL2/SDL_rect.h>
#include <iostream>

enum Alignment
{
    LEFT_CENTER,
    RIGHT_CENTER,
    CENTER_CENTER
};

inline SDL_Rect getAlignRect(Alignment align, int x, int y, int w, int h)
{
    std::cout << x << " " << y << " " << w << " " << h << std::endl;
    SDL_Rect rect;
    if (align == Alignment::LEFT_CENTER)
    {
        rect.x = x;
        rect.y = y - h / 2;
        rect.w = w;
        rect.h = h;
    }
    else if (align == Alignment::RIGHT_CENTER)
    {
        rect.x = x - w;
        rect.y = y - h / 2;
        rect.w = w;
        rect.h = h;
    }
    else if (align == Alignment::CENTER_CENTER)
    {
        rect.x = x - w / 2;
        rect.y = y - h / 2;
        rect.w = w;
        rect.h = h;
    }

    return rect;
}