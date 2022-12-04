#include <SDL.h>
#include <SDL_ttf.h>

#include <spdlog/spdlog.h>

#include "solarsystemclock/sdl/error.h"
#include "solarsystemclock/sdl/renderer.h"
#include "solarsystemclock/sdl/surface.h"
#include "solarsystemclock/sdl/texture.h"

#include "solarsystemclock/sdl/font.h"

using namespace solarsystemclock::sdl;

Font::Font(TTF_Font *font, const std::string &filename, int point_size)
        : m_logger(spdlog::get("sdl")),
        m_filename(filename),
        m_point_size(point_size),
        m_font(font) {
    if (!m_filename.empty()) {
        m_logger->info("Creating font: {} @ {}pt", m_filename, m_point_size);
    }

    if (!m_font) {
        throw Error("Could not create font.", TTF_GetError());
    }
}

Font::Font(const std::string &filename, int point_size)
        : Font(TTF_OpenFont(filename.c_str(), point_size), filename, point_size) {

}

Font::~Font() {
    if (!m_filename.empty()) {
        m_logger->info("Destroying font: {} @ {}pt", m_filename, m_point_size);
    }

    if (m_font) {
        TTF_CloseFont(m_font);
    }
}

Surface Font::render_utf8_solid(const std::string &text, SDL_Color color) const {
    auto sdl_surface = TTF_RenderUTF8_Solid(*this, text.c_str(), color);
    return Surface(sdl_surface);
}

Surface Font::render_utf8_blended(const std::string &text, SDL_Color color) const {
    auto sdl_surface = TTF_RenderUTF8_Blended(*this, text.c_str(), color);
    return Surface(sdl_surface);
}
