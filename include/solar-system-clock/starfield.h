struct SDL_Renderer;

namespace solarsystemclock {

    class Texture;

    struct Star {
        int x, y;
        int size;
        int r, g, b, a;
    };

    class Starfield {
    public:
        Starfield(SDL_Renderer *renderer);
        ~Starfield();

        void resize(int width, int height);
        void update(float dt);
        void draw();

    private:
        SDL_Renderer *m_renderer;

        Texture *m_star_texture;

        Star *m_stars;
        int m_no_stars;
    };

}
