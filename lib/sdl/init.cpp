#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "solarsystemclock/sdl/error.h"

#include "solarsystemclock/sdl/init.h"

using namespace solarsystemclock::sdl;

Init::Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw Error("Could not initialise SDL.");
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        throw Error("Could not initialise SDL_image.", IMG_GetError());
    }

    if (Mix_Init(MIX_INIT_OGG) != MIX_INIT_OGG) {
        throw Error("Could not initialise SDL_mixer.", Mix_GetError());
    }

    if (TTF_Init() == -1) {
        throw Error("Could not initialise SDL_ttf.", TTF_GetError());
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
}

Init::~Init() {
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}
