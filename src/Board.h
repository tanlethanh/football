#include <string>
#include <SDL2/SDL_render.h>

class Board
{
public:
    Board(std::string path);
    ~Board();

    void update();
    void render();

    SDL_Rect getLeftLineRect();
    SDL_Rect getRightLineRect();
    SDL_Rect getTopLineRect();
    SDL_Rect getBottomLineRect();

private:
    SDL_Texture *texr;
    SDL_Rect leftLineRect;
    SDL_Rect rightLineRect;
    SDL_Rect topLineRect;
    SDL_Rect bottomLineRect;
};