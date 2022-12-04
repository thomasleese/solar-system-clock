#ifndef SOLARSYSTEMCLOCK_SDL_RENDERER_H
#define SOLARSYSTEMCLOCK_SDL_RENDERER_H

#include <memory>

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

struct SDL_Window;

namespace solarsystemclock::sdl {

    class Window;

    class Renderer {
    public:
        explicit Renderer(SDL_Renderer *renderer);

        Renderer(SDL_Window *window, int index, uint32_t flags);

        ~Renderer();

        operator SDL_Renderer *() const noexcept {
            return m_renderer;
        }

        void set_target(SDL_Texture *texture = nullptr) const;

        void get_output_size(int *width, int *height) const;

        void get_logical_size(int *width, int *height) const;

        void set_logical_size(int width, int height);

        void render_copy(SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_FRect *dstrect) const;

        void render_copy(SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_FRect *dstrect, double angle,
                         const SDL_FPoint *center, SDL_RendererFlip flip) const;

        void fill(uint8_t r, uint8_t g, uint8_t b, uint8_t a) const;

        void clear() const;

        void present() const noexcept;

    private:
        SDL_Renderer *m_renderer;
    };

}

#endif // SOLARSYSTEMCLOCK_SDL_RENDERER_H
