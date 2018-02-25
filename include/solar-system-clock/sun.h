struct SDL_Renderer;

namespace solarsystemclock {

    class Texture;

    class Sun {
    public:
        Sun(SDL_Renderer *renderer);
        ~Sun();

        void resize(int width, int height);
        void update(float dt);
        void draw();

    private:
        SDL_Renderer *m_renderer;
        Texture *m_texture;

        int m_size, m_cx, m_cy;
    };

}
