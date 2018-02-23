struct SDL_Renderer;
struct SDL_Texture;

namespace solarsystemclock {

    class Texture {
    public:
        Texture(SDL_Renderer *renderer, std::string filename);
        ~Texture();

        void draw(SDL_Renderer *renderer, int x, int y, int width, int height, int r, int g, int b, int a);

    private:
        SDL_Texture *m_texture;

        SDL_Rect *m_src_rect;
        SDL_Rect *m_dest_rect;
    };

}
