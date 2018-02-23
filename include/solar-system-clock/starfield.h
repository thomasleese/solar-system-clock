struct SDL_Renderer;

namespace solarsystemclock {

    class Starfield {
    public:
        Starfield(SDL_Renderer *renderer);
        ~Starfield();

        void resize(int width, int height);
        void render(float dt);

    private:
        SDL_Renderer *m_renderer;
    };

}
