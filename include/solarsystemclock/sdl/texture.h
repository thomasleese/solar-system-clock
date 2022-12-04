#ifndef SOLARSYSTEMCLOCK_SDL_TEXTURE_H
#define SOLARSYSTEMCLOCK_SDL_TEXTURE_H

#include <string>

#include <SDL2/SDL_blendmode.h>

struct SDL_Color;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;

namespace solarsystemclock::sdl {

    class Texture {
    public:
        explicit Texture(SDL_Texture *texture);
        Texture(SDL_Renderer *renderer, int width, int height);
        Texture(SDL_Renderer *renderer, SDL_Surface *surface);
        Texture(SDL_Renderer *renderer, const std::string &filename);
        Texture(Texture &&texture) noexcept;
        Texture(const Texture &) = delete;

        ~Texture();

        operator SDL_Texture *() const {
            return m_texture;
        }

        void set_blend_mode(SDL_BlendMode blend_mode);

        void set_color_mod(uint8_t red, uint8_t green, uint8_t blue);

        void set_alpha_mod(uint8_t alpha);

    private:
        SDL_Texture *m_texture;
    };

}

#endif // SOLARSYSTEMCLOCK_SDL_TEXTURE_H
