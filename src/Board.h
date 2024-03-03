#include <string>
#include <SDL2/SDL_render.h>

class Board
{
public:
    Board(std::string path);
    ~Board();

    void update();
    void render();

private:
    SDL_Texture *texr;
};