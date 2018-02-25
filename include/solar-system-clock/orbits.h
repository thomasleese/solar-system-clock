struct SDL_Renderer;

namespace solarsystemclock {

    class Texture;

    class Orbits {
    public:
        Orbits(SDL_Renderer *renderer);
        ~Orbits();

        void resize(int width, int height);
        void draw();

    private:
        SDL_Renderer *m_renderer;
        Texture *m_texture;

        int m_size, m_cx, m_cy;
    };

}
