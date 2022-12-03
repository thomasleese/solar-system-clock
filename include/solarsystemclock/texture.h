#include <string>

struct SDL_Renderer;
struct SDL_Texture;

namespace solarsystemclock {

    class Texture {
    public:
        Texture(SDL_Renderer *renderer, std::string filename);
        Texture(SDL_Texture *texture, int width, int height);
        ~Texture();

        void draw(SDL_Renderer *renderer, double x, double y, double width, double height, double angle, int r, int g, int b, int a);
        void draw(SDL_Renderer *renderer, double x, double y, double width, double height, int r, int g, int b, int a);
        void draw(SDL_Renderer *renderer, double x, double y, int r, int g, int b, int a);

    private:
        SDL_Texture *m_texture;

        SDL_Rect *m_src_rect;
        SDL_Rect *m_dest_rect;
    };

}
