#ifndef SOLARSYSTEMCLOCK_SDL_FONT_H
#define SOLARSYSTEMCLOCK_SDL_FONT_H

#include <memory>
#include <string>

struct SDL_Color;
typedef struct _TTF_Font TTF_Font;

namespace spdlog {
    class logger;
}

namespace solarsystemclock::sdl {

    class Surface;
    class Texture;

    class Font {
    public:
        explicit Font(TTF_Font *font, const std::string &filename = "", int point_size = 0);

        Font(const std::string &filename, int point_size);

        ~Font();

        operator TTF_Font *() const {
            return m_font;
        }

        [[nodiscard]] int point_size() const {
            return m_point_size;
        }

        [[nodiscard]] Surface render_utf8_solid(const std::string &text, SDL_Color color) const;

        [[nodiscard]] Surface render_utf8_blended(const std::string &text, SDL_Color color) const;

    private:
        std::shared_ptr<spdlog::logger> m_logger;

        std::string m_filename;
        int m_point_size;
        TTF_Font *m_font;
    };

}

#endif // SOLARSYSTEMCLOCK_SDL_FONT_H
