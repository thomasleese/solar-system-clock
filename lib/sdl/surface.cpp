#include <SDL.h>
#include <SDL_image.h>

#include "solarsystemclock/sdl/error.h"

#include "solarsystemclock/sdl/surface.h"

using namespace solarsystemclock::sdl;

Surface::Surface(SDL_Surface *surface, const std::string &filename)
        : m_filename(filename), m_surface(surface) {
    if (!m_surface) {
        throw Error("Could not create surface.");
    }
}

Surface::Surface(const std::string &filename)
        : Surface(IMG_Load(filename.c_str()), filename) {

}

Surface::Surface(Surface &&other_surface) noexcept
        : Surface(other_surface.m_surface, other_surface.m_filename) {
    other_surface.m_filename = "";
    other_surface.m_surface = nullptr;
}

Surface::~Surface() {
    if (m_surface) {
        SDL_FreeSurface(m_surface);
    }
}
